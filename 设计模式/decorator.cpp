// 瑁呴グ妯″紡
#include <iostream>
#include <string>

class People
{
public:
  virtual ~People() {}
  virtual std::string Operation() const = 0;
};

class ConcretePeople : public People
{
public:
  std::string Operation() const override
  {
    return "我是ikun";
  }
};

class Decorator : public People
{
protected:
  People *_people;

public:
  Decorator(People *people) : _people(people) {}

  std::string Operation() const override
  {
    return _people->Operation();
  }
};

class ClothDecoratorA : public Decorator
{
public:
  ClothDecoratorA(People *people) : Decorator(people) {}

  std::string Operation() const override
  {
    return "背带裤(" + Decorator::Operation() + ")";
  }
};

class ClothDecoratorB : public Decorator
{
public:
  ClothDecoratorB(People *people) : Decorator(people) {}

  std::string Operation() const override
  {
    return "篮球(" + Decorator::Operation() + ")";
  }
};

void ClientCode(People *people)
{
  std::cout << "当前的形象：" << people->Operation();
}

int main()
{
  People *ikun = new ConcretePeople;
  std::cout << "路人ikun:\n";
  ClientCode(ikun);
  std::cout << "\n";

  ClothDecoratorA *decoratorA = new ClothDecoratorA(ikun);
  std::cout << "普通ikun:\n";
  ClientCode(decoratorA);
  std::cout << "\n";

  ClothDecoratorB *decoratorB = new ClothDecoratorB(decoratorA);
  std::cout << "高级ikun:\n";
  ClientCode(decoratorB);
  std::cout << "\n";

  delete decoratorB;
  delete decoratorA;
  delete ikun;
  return 0;
}