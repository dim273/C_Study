// 代理模式
#include <iostream>

// 抽象主题接口
class Subject
{
public:
  virtual void Resquest() const = 0;
};

// 真实主题类
class RealSubject : public Subject
{
public:
  void Resquest() const override
  {
    std::cout << "真实主题类\n";
  }
};

// 代理类
class Proxy : public Subject
{
private:
  RealSubject *real_subject;

  bool CheckAccess() const
  {
    std::cout << "代理类: 检查访问权限...\n";
    return true;
  }

  void LogAccess() const
  {
    std::cout << "代理类: 记录访问日志...\n";
  }

public:
  Proxy(RealSubject *real_subject_) : real_subject(new RealSubject(*real_subject_))
  {
  }
  ~Proxy()
  {
    delete real_subject;
  }

  void Resquest() const override
  {
    if (this->CheckAccess())
    {
      this->real_subject->Resquest();
      this->LogAccess();
    }
  }
};

// 客户端代码
void ClientCode(const Subject &subject)
{
  subject.Resquest();
}

int main()
{
  std::cout << "客户端: 直接访问真实主题:\n";
  RealSubject *real_subject = new RealSubject;
  ClientCode(*real_subject);

  std::cout << "\n";

  std::cout << "客户端: 通过代理访问真实主题:\n";
  Proxy *proxy = new Proxy(real_subject);
  ClientCode(*proxy);

  delete real_subject;
  delete proxy;

  return 0;
}