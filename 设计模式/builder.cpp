// 建造者模式
#include "../head.h"

// 产品，建造者模式的目标
class Product
{
public:
  std::vector<std::string> parts;
  void ListParts() const
  {
    std::cout << "产品包含部分有：";
    for (const auto &part : parts)
    {
      std::cout << part << " ";
    }
    std::cout << std::endl;
  }
};

// 建造者接口
class Builder
{
public:
  virtual ~Builder() {}
  // 构建部件的方法
  virtual void ProducePartA() const = 0;
  virtual void ProducePartB() const = 0;
  virtual void ProducePartC() const = 0;
};

// 具体建造者类
class ConcreteBuilder1 : public Builder
{
private:
  Product *protect;

public:
  ConcreteBuilder1()
  {
    this->Reset();
  }
  ~ConcreteBuilder1()
  {
    delete protect;
  }
  void Reset()
  {
    this->protect = new Product();
  }
  void ProducePartA() const override
  {
    this->protect->parts.push_back("头");
  }
  void ProducePartB() const override
  {
    this->protect->parts.push_back("手");
  }
  void ProducePartC() const override
  {
    this->protect->parts.push_back("角");
  }
  Product *GetProduct()
  {
    Product *result = this->protect;
    this->Reset();
    return result;
  }
};

class Director
{
private:
  Builder *builder;

public:
  void set_builder(Builder *builder)
  {
    this->builder = builder;
  }
  void BuildMinimalViableProduct()
  {
    this->builder->ProducePartA();
  }
  void BuildFullFeaturedProduct()
  {
    this->builder->ProducePartA();
    this->builder->ProducePartB();
    this->builder->ProducePartC();
  }
};

// 客户端代码
void ClientCode(Director *director)
{
  ConcreteBuilder1 *builder = new ConcreteBuilder1();
  director->set_builder(builder);

  std::cout << "标准基本产品：" << std::endl;
  director->BuildMinimalViableProduct();
  Product *p = builder->GetProduct();
  p->ListParts();
  delete p;

  std::cout << "标准完整产品：" << std::endl;
  director->BuildFullFeaturedProduct();
  p = builder->GetProduct();
  p->ListParts();
  delete p;

  std::cout << "自定义产品：" << std::endl;
  builder->ProducePartA();
  builder->ProducePartC();
  p = builder->GetProduct();
  p->ListParts();
  delete p;

  delete builder;
}

int main()
{
  Director *director = new Director();

  ClientCode(director);

  delete director;
  return 0;
}