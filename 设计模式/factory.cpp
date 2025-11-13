// 工厂方法
#include <iostream>
#include <string>

// 产品接口
class Product
{
public:
  virtual ~Product() {}
  virtual std::string Operation() const = 0;
};

// 具体产品A
class ConcreteProductA : public Product
{
public:
  std::string Operation() const override
  {
    return "ConcreteProductA 制作的产品";
  }
};

// 具体产品B
class ConcreteProductB : public Product
{
public:
  std::string Operation() const override
  {
    return "ConcreteProductB 制作的产品";
  }
};

// 创建者类
class Creator
{
public:
  virtual ~Creator() {}
  virtual Product *FactoryMethod() const = 0;

  std::string SomeOperation() const
  {
    Product *product = this->FactoryMethod();
    std::string result = "Creator: 通过工厂方法创建了一个产品, 为: " + product->Operation() + "\n";
    result += product->Operation();
    delete product;
    return result;
  }
};

// 具体创建者A
class ConcreteCreatorA : public Creator
{
public:
  Product *FactoryMethod() const override
  {
    return new ConcreteProductA();
  }
};
// 具体创建者B
class ConcreteCreatorB : public Creator
{
public:
  Product *FactoryMethod() const override
  {
    return new ConcreteProductB();
  }
};

void ClientCode(const Creator &creator)
{
  std::cout << "客户端: 我不关心创建者的类, 只要通过它来获取产品即可.\n"
            << creator.SomeOperation() << std::endl;
}

int main()
{
  std::cout << "应用：使用 ConcreteCreatorA 启动。\n";
  Creator *creator = new ConcreteCreatorA();
  ClientCode(*creator);
  std::cout << std::endl;

  std::cout << "应用：使用 ConcreteCreatorB 启动。\n";
  Creator *creator2 = new ConcreteCreatorB();
  ClientCode(*creator2);

  // 释放创建者对象
  delete creator;
  delete creator2;
  return 0;
}