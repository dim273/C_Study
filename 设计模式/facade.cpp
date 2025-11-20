// 外观模式
#include "../head.h"

// 子系统1
class Subsystem1
{
public:
  std::string Operation1() const
  {
    return "一号就绪\n";
  }
  std::string OperationN() const
  {
    return "一号出发\n";
  }
};

// 子系统2
class Subsystem2
{
public:
  std::string Operation2() const
  {
    return "二号就绪\n";
  }
  std::string OperationM() const
  {
    return "二号出发\n";
  }
};

// 外观类，为子系统提供统一的简化接口
// 1. 封装子系统的复杂交互逻辑（如调用顺序、依赖关系）；
// 2. 提供一个客户端易于使用的统一方法（如Operation）；
// 3. 管理子系统的生命周期（创建、销毁）。

class Facade
{
protected:
  Subsystem1 *subsystem1;
  Subsystem2 *subsystem2;

public:
  Facade(Subsystem1 *subsystem1 = nullptr, Subsystem2 *subsystem2 = nullptr)
  {
    this->subsystem1 = subsystem1 ? subsystem1 : new Subsystem1();
    this->subsystem2 = subsystem2 ? subsystem2 : new Subsystem2();
  }

  ~Facade()
  {
    delete subsystem1;
    delete subsystem2;
  }

  std::string Operation() const
  {
    std::string res = "外观类初始化子系统:\n";
    res += this->subsystem1->Operation1();
    res += this->subsystem2->Operation2();
    res += "外观类操作子系统:\n";
    res += this->subsystem1->OperationN();
    res += this->subsystem2->OperationM();

    return res;
  }
};

// 客户端代码
void ClientCode(Facade *facade)
{
  std::cout << facade->Operation() << std::endl;
}

int main()
{
  Subsystem1 *subsystem1 = new Subsystem1;
  Subsystem2 *subsystem2 = new Subsystem2;
  Facade *facade = new Facade(subsystem1, subsystem2);
  ClientCode(facade);
  delete facade;
  return 0;
}
