// 桥接模式

#include "../head.h"

// 实现接口, 定义实现类的接口
class Implementor
{
public:
  virtual ~Implementor() {}
  virtual std::string OperationImpl() const = 0;
};

// 具体实现
class ConcreteImplementorA : public Implementor
{
public:
  std::string OperationImpl() const override
  {
    return "具体实现A的操作";
  }
};

class ConcreteImplementorB : public Implementor
{
public:
  std::string OperationImpl() const override
  {
    return "具体实现B的操作";
  }
};

// 抽象类, 定义抽象类的接口
class Abstraction
{
protected:
  Implementor *implementor;

public:
  Abstraction(Implementor *impl) : implementor(impl) {}
  virtual ~Abstraction() {}
  virtual std::string Operation() const
  {
    return "抽象类通过桥接调用: " + implementor->OperationImpl();
  }
};

// 扩展抽象类
class ExtendedAbstraction : public Abstraction
{
public:
  ExtendedAbstraction(Implementor *impl) : Abstraction(impl) {}
  std::string Operation() const override
  {
    return "扩展抽象类通过桥接调用: " + implementor->OperationImpl();
  }
};

// 客户端代码
void ClientCode(const Abstraction &abstraction)
{
  std::cout << abstraction.Operation() << std::endl;
}

int main()
{
  Implementor *implA = new ConcreteImplementorA();
  Abstraction *absA = new Abstraction(implA);
  ClientCode(*absA);

  delete absA;
  delete implA;

  Implementor *implB = new ConcreteImplementorB();
  Abstraction *absB = new ExtendedAbstraction(implB);
  ClientCode(*absB);

  delete absB;
  delete implB;

  return 0;
}