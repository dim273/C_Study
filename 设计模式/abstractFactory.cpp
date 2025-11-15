// 抽象工厂模式
#include "../head.h"

// 抽象产品A接口
class AbstractProductA
{
public:
  virtual ~AbstractProductA() {}
  virtual std::string UsefulFunctionA() const = 0;
};

// 具体产品A1
class ConcreteProductA1 : public AbstractProductA
{
public:
  std::string UsefulFunctionA() const override
  {
    return "产品A1";
  }
};

// 具体产品A2
class ConcreteProductA2 : public AbstractProductA
{
public:
  std::string UsefulFunctionA() const override
  {
    return "产品A2";
  }
};

// 抽象产品B接口
class AbstractProductB
{
public:
  virtual ~AbstractProductB() {}
  virtual std::string UsefulFunctionB() const = 0;
  virtual std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const = 0;
};

// 具体产品B1
class ConcreteProductB1 : public AbstractProductB
{
public:
  std::string UsefulFunctionB() const override
  {
    return "产品B1";
  }
  std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override
  {
    return "产品B1和" + collaborator.UsefulFunctionA() + "一起工作";
  }
};

// 产品B2
class ConcreteProductB2 : public AbstractProductB
{
public:
  std::string UsefulFunctionB() const override
  {
    return "产品B2";
  }
  std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override
  {
    return "产品B2和" + collaborator.UsefulFunctionA() + "一起工作";
  }
};

// 抽象工厂接口
class AbstractFactory
{
public:
  virtual ~AbstractFactory() {}
  virtual AbstractProductA *CreateProductA() const = 0;
  virtual AbstractProductB *CreateProductB() const = 0;
};

// 具体工厂1
class ConcreteFactory1 : public AbstractFactory
{
public:
  AbstractProductA *CreateProductA() const override
  {
    return new ConcreteProductA1();
  }
  AbstractProductB *CreateProductB() const override
  {
    return new ConcreteProductB1();
  }
};

// 具体工厂2
class ConcreteFactory2 : public AbstractFactory
{
public:
  AbstractProductA *CreateProductA() const override
  {
    return new ConcreteProductA2();
  }
  AbstractProductB *CreateProductB() const override
  {
    return new ConcreteProductB2();
  }
};

// 客户端代码
void ClientCode(const AbstractFactory &factory)
{
  const AbstractProductA *productA = factory.CreateProductA();
  const AbstractProductB *productB = factory.CreateProductB();

  std::cout << productB->UsefulFunctionB() << std::endl;
  std::cout << productB->AnotherUsefulFunctionB(*productA) << std::endl;

  delete productA;
  delete productB;
}

int main()
{
  std::cout << "客户端代码使用抽象工厂1" << std::endl;
  ConcreteFactory1 *factory1 = new ConcreteFactory1();
  ClientCode(*factory1);
  delete factory1;

  std::cout << "\n客户端代码使用抽象工厂2" << std::endl;
  ConcreteFactory2 *factory2 = new ConcreteFactory2();
  ClientCode(*factory2);
  delete factory2;

  return 0;
}