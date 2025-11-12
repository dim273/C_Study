// 备忘录模式
#include <iostream>
#include <string>
#include <ctime>
#include <vector>

// 备忘录接口
class Memento
{
public:
  virtual ~Memento() {}
  virtual std::string GetName() const = 0; // 获取备忘录名称
  virtual std::string Date() const = 0;    // 获取备忘录创建时间
  virtual std::string State() const = 0;   // 获取备忘录状态
};

// 具体的备忘录
class ConcreteMemento : public Memento
{
private:
  std::string state;
  std::string date;

public:
  ConcreteMemento(std::string _state) : state(_state)
  {
    this->state = _state;
    std::time_t now = std::time(0);
    this->date = std::ctime(&now);
  }

  // 获取备忘录名称：格式为“日期 / （状态前9个字符）”
  std::string GetName() const override
  {
    return this->date + " / (" + this->state.substr(0, 9) + ")";
  }

  // 获取备忘录创建时间
  std::string Date() const override
  {
    return this->date;
  }

  std::string State() const override
  {
    return this->state;
  }
};

// 发起人
class Originator
{
private:
  std::string state;

  // 随机生成字符串，作为状态
  std::string GenerateRandomString(int length = 10)
  {
    const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    int stringLength = sizeof(charset) - 1;

    std::string random_string;
    for (int i = 0; i < length; ++i)
    {
      random_string += charset[rand() % stringLength];
    }
    return random_string;
  }

public:
  Originator(std::string _state) : state(_state)
  {
    std::cout << "发起人的初始状态为: " << this->state << "\n";
  }

  void DoSomething()
  {
    std::cout << "发起人正在做一些重要的事情...\n";
    this->state = this->GenerateRandomString(30);
    std::cout << "发起人新状态为: " << this->state << "\n";
  }

  Memento *Save()
  {
    return new ConcreteMemento(this->state);
  }

  void Restore(Memento *memento)
  {
    this->state = memento->State();
    std::cout << "发起人状态恢复到: " << this->state << "\n";
    delete memento; // 避免内存泄漏
  }
};

// 管理者
class Caretaker
{
private:
  std::vector<Memento *> mementos;
  Originator *originator;

public:
  Caretaker(Originator *_originator) : originator(_originator) {}

  void Backup()
  {
    std::cout << "\n管理者：正在保存发起人状态...\n";
    this->mementos.push_back(this->originator->Save());
  }

  void Undo()
  {
    if (this->mementos.empty())
    {
      std::cout << "管理者：没有备忘录可供恢复。\n";
      return;
    }
    Memento *memento = this->mementos.back();
    this->mementos.pop_back();
    std::cout << "管理者：正在恢复发起人状态到: " << memento->GetName() << "\n";
    this->originator->Restore(memento);
  }

  void ShowHistory() const
  {
    std::cout << "管理者：这里是备忘录列表:\n";
    for (Memento *memento : this->mementos)
    {
      std::cout << memento->GetName() << "\n";
    }
  }

  ~Caretaker()
  {
    for (Memento *memento : mementos)
    {
      delete memento;
    }
  }
};

int main()
{
  std::srand(static_cast<unsigned int>(std::time(NULL)));

  Originator *originator = new Originator("初始");
  Caretaker *caretaker = new Caretaker(originator);

  caretaker->Backup();
  originator->DoSomething();
  caretaker->Backup();
  originator->DoSomething();
  caretaker->Backup();
  originator->DoSomething();

  std::cout << "\n\n";

  caretaker->ShowHistory();

  std::cout << "现在开始撤销操作\n";
  caretaker->Undo();
  std::cout << "第二次撤销\n";
  caretaker->Undo();

  delete originator;
  delete caretaker;

  return 0;
}