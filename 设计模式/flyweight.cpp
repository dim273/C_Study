// 享元模式
#include "../head.h"

// 内在状态，多个对象共有的状态，不会随对象变化而改变
struct SharedState
{
  std::string brand;
  std::string model;
  std::string color;

  SharedState(const std::string &brand, const std::string &model, const std::string &color)
      : brand(brand), model(model), color(color)
  {
  }

  friend std::ostream &operator<<(std::ostream &os, const SharedState &state)
  {
    return os << "[品牌: " << state.brand << ", 型号: " << state.model << ", 颜色: " << state.color << "]";
  }
};

// 外在状态，每个对象独有的状态，随对象变化而改变
struct UniquedState
{
  std::string owner;
  std::string plaates;
  UniquedState(const std::string &owner, const std::string &plaates)
      : owner(owner), plaates(plaates)
  {
  }

  friend std::ostream &operator<<(std::ostream &os, const UniquedState &state)
  {
    return os << "[车主: " << state.owner << ", 车牌: " << state.plaates << "]";
  }
};

// 享元（Flyweight）类：存储内在状态，并提供方法接收外在状态执行操作。
class Flyweight
{
private:
  SharedState *shared_state;

public:
  Flyweight(const SharedState *_shared_state) : shared_state(new SharedState(*_shared_state)) {}

  Flyweight(const Flyweight &other) : shared_state(new SharedState(*other.shared_state)) {}

  ~Flyweight()
  {
    delete shared_state;
  }

  SharedState *get_shared_state() const
  {
    return shared_state;
  }

  void operation(const UniquedState &uniqued_state) const
  {
    std::cout << "Flyweight: 显示共享状态 ";
    std::cout << *shared_state;
    std::cout << " 和独有状态 ";
    std::cout << uniqued_state;
    std::cout << std::endl;
  }
};

// 享元工厂类：创建和管理享元对象，确保共享机制。
class FlyweightFactory
{
private:
  std::unordered_map<std::string, Flyweight> flyweights;

  std::string GetKey(const SharedState &ss) const
  {
    return ss.brand + "_" + ss.model + "_" + ss.color;
  }

public:
  FlyweightFactory(std::initializer_list<SharedState> shared_states)
  {
    for (const SharedState &ss : shared_states)
    {
      this->flyweights.insert(std::make_pair<std::string, Flyweight>(this->GetKey(ss), Flyweight(&ss)));
    }
  }

  Flyweight GetFlyweight(const SharedState &shared_state)
  {
    std::string key = this->GetKey(shared_state);
    if (this->flyweights.find(key) == this->flyweights.end())
    {
      std::cout << "FlyweightFactory: 不能找到享元, 创建新的享元对象.\n";
      this->flyweights.insert(std::make_pair(key, Flyweight(&shared_state)));
    }
    else
    {
      std::cout << "FlyweightFactory: 享元已存在, 共享现有享元对象.\n";
    }
    return this->flyweights.at(key);
  }

  void ListFlyweights() const
  {
    size_t count = this->flyweights.size();
    std::cout << "\nFlyweightFactory: 我们有 " << count << " 个享元对象:\n";
    for (const auto &pair : this->flyweights)
    {
      std::cout << pair.first << "\n";
    }
  }
};

// 客户端代码
void AddCarToPoliceDatabase(FlyweightFactory &ff, const std::string &plates,
                            const std::string &owner, const std::string &brand,
                            const std::string &model, const std::string &color)
{
  std::cout << "\n客户: 添加车牌号码为 " << plates << " 的车辆到数据库.\n";
  Flyweight flyweight = ff.GetFlyweight(SharedState(brand, model, color));
  flyweight.operation(UniquedState(owner, plates));
}

int main()
{
  FlyweightFactory *ff = new FlyweightFactory({{"BMW", "X5", "红色"},
                                               {"BMW", "X3", "白色"},
                                               {"丰田", "威驰", "蓝色"},
                                               {"丰田", "卡罗拉", "黑色"},
                                               {"本田", "雅阁", "灰色"}});
  ff->ListFlyweights();
  AddCarToPoliceDatabase(*ff, "京A88888", "张三", "BMW", "X5", "红色");
  AddCarToPoliceDatabase(*ff, "沪B66666", "李四", "奥迪", "A6", "白色");
  ff->ListFlyweights();

  delete ff;

  return 0;
}