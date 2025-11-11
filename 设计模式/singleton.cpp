// 单例模式
#include <iostream>
#include <string>
#include <thread>

class Singleton
{
protected:
  Singleton(const std::string _value) : value(_value) {}
  static Singleton *singleton;
  std::string value;

public:
  // 单例模式无法被复制或转移
  Singleton(Singleton &other) = delete;
  void operator=(const Singleton &) = delete;
  static Singleton *GetInstance(const std::string &value);
  void SomeBusinessLogic() {}
  std::string Value() const
  {
    return value;
  }
};

Singleton *Singleton::singleton = nullptr;

// 获取实例，如果不存在的话创建实例
Singleton *Singleton::GetInstance(const std::string &value)
{
  if (singleton == nullptr)
  {
    singleton = new Singleton(value);
  }
  return singleton;
}

void ThreadFoo()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  Singleton *Singleton = Singleton::GetInstance("FOO");
  std::cout << Singleton->Value() << "\n";
}

void ThreadBar()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  Singleton *Singleton = Singleton::GetInstance("BAR");
  std::cout << Singleton->Value() << "\n";
}

int main()
{
  std::cout << "如果看见一个相同的结果，则实例被重复使用\n"
            << "如果是两个不同的结果，那么创建了两个实例\n"
            << "接下来，让我们看看结果\n";
  std::thread t1(ThreadFoo);
  std::thread t2(ThreadBar);
  t1.join();
  t2.join();
  return 0;
}
