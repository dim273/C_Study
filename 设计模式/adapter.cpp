#include <iostream>
#include <string>
#include <algorithm>

// 目标接口
class Target
{
public:
  virtual ~Target() = default;

  virtual std::string Request() const
  {
    return "目标接口: 默认的目标行为。";
  }
};

class Adaptee
{
public:
  std::string SpecificRequest() const
  {
    return ".eetpadA eht fo roivaheb laicepS";
  }
};

// 适配器
class Adapter : public Target, public Adaptee
{
public:
  Adapter() {}
  std::string Request() const override
  {
    std::string to_reverse = SpecificRequest();

    std::reverse(to_reverse.begin(), to_reverse.end());

    return "适配器: (已转换) " + to_reverse;
  }
};

// 客户端代码
void ClientCode(const Target *target)
{
  std::cout << target->Request();
}

int main()
{
  std::cout << "客户端: 我可以很好地使用目标接口对象:\n";
  Target *target = new Target;
  ClientCode(target);
  std::cout << "\n\n";
  Adaptee *adaptee = new Adaptee;
  std::cout << "客户端: 适配者类有一个奇怪的接口。看，我不理解它:\n";
  // 客户端无法直接使用 Adaptee 的 SpecificRequest 方法，因为接口不匹配
  std::cout << "适配者: " << adaptee->SpecificRequest();
  std::cout << "\n\n";

  std::cout << "客户端: 但我可以通过适配器来使用它:\n";
  Adapter *adapter = new Adapter;
  // 客户端调用的是 Target 接口的 Request 方法
  ClientCode(adapter);
  std::cout << "\n";

  // 释放动态分配的内存
  delete target;
  delete adaptee;
  delete adapter;

  return 0;
}