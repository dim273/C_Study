// 原型模式
#include <iostream>
#include <unordered_map>
using std::string;

// 枚举类型：标记不同原型的类型
enum Type
{
  TYPE_A = 0,
  TYPE_B
};

// 抽象原型类
class Prototype
{
protected:
  string prototype_name;
  float prototype_field;

public:
  Prototype() {}
  Prototype(string name) : prototype_name(name) {}
  virtual ~Prototype() {}
  virtual Prototype *Clone() = 0; // 克隆接口
  virtual void Method(float field)
  {
    this->prototype_field = field;
    std::cout << "调用来自 " << prototype_name << " 的 Method, 参数为 " << field << std::endl;
  }
};

// 具体原型类A
class ConcretePrototypeA : public Prototype
{
private:
  float concrete_prototype_field_a;

public:
  ConcretePrototypeA(string name, float field) : Prototype(name), concrete_prototype_field_a(field) {}
  Prototype *Clone() override
  {
    return new ConcretePrototypeA(*this);
  }
};

// 具体原型类B
class ConcretePrototypeB : public Prototype
{
private:
  float concrete_prototype_field_b;

public:
  ConcretePrototypeB(string name, float field) : Prototype(name), concrete_prototype_field_b(field) {}
  Prototype *Clone() override
  {
    return new ConcretePrototypeB(*this);
  }
};

// 原型工厂
class PrototypeFactory
{
private:
  std::unordered_map<Type, Prototype *, std::hash<int>> prototypes;

public:
  PrototypeFactory()
  {
    prototypes[TYPE_A] = new ConcretePrototypeA("TYPE_A", 50.0f);
    prototypes[TYPE_B] = new ConcretePrototypeB("TYPE_B", 60.0f);
  }
  ~PrototypeFactory()
  {
    delete prototypes[Type::TYPE_A];
    delete prototypes[Type::TYPE_B];
  }
  Prototype *CreatePrototype(Type type)
  {
    return prototypes[type]->Clone();
  }
};

// 客户端代码
void Client(PrototypeFactory &factory)
{
  std::cout << "创建原型A" << std::endl;
  Prototype *prototype_a = factory.CreatePrototype(Type::TYPE_A);
  prototype_a->Method(90.0f);
  delete prototype_a;

  std::cout << "\n";

  std::cout << "创建原型B" << std::endl;
  Prototype *prototype_b = factory.CreatePrototype(Type::TYPE_B);
  prototype_b->Method(10.0f);
  delete prototype_b;
}

int main()
{
  PrototypeFactory *factory = new PrototypeFactory();
  Client(*factory);
  delete factory;
  return 0;
}