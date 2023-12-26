#include <iostream>
#include <vector>
using namespace std;

// 工厂模式：定义一个用于创建对象的接口，让子类决定实例化哪一个类
// 抽象产品类：汽车
class Car {
public:
    virtual void run() = 0; // 虚函数，表示汽车的运行方法
    virtual ~Car() {} // 虚析构函数，方便子类析构
};

// 具体产品类：宝马汽车
class BMW : public Car {
public:
    void run() override {
        cout << "BMW is running" << endl;
    }
};

// 具体产品类：奔驰汽车
class Benz : public Car {
public:
    void run() override {
        cout << "Benz is running" << endl;
    }
};

// 抽象工厂类：汽车工厂
class CarFactory {
public:
    virtual Car* createCar() = 0; // 虚函数，表示创建汽车的方法
    virtual ~CarFactory() {} // 虚析构函数，方便子类析构
};

// 具体工厂类：宝马汽车工厂
class BMWFactory : public CarFactory {
public:
    Car* createCar() override {
        return new BMW(); // 创建宝马汽车对象
    }
};

// 具体工厂类：奔驰汽车工厂
class BenzFactory : public CarFactory {
public:
    Car* createCar() override {
        return new Benz(); // 创建奔驰汽车对象
    }
};

// 建造者模式：将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示
// 产品类：汽车零件
class CarPart {
public:
    string name; // 零件名称
    CarPart(string name) : name(name) {} // 构造函数
};

// 抽象建造者类：汽车组装者
class CarBuilder {
public:
    virtual void buildEngine() = 0; // 虚函数，表示建造引擎的方法
    virtual void buildWheel() = 0; // 虚函数，表示建造轮子的方法
    virtual void buildBody() = 0; // 虚函数，表示建造车身的方法
    virtual vector<CarPart*> getCar() = 0; // 虚函数，表示获取汽车的方法
    virtual ~CarBuilder() {} // 虚析构函数，方便子类析构
};

// 具体建造者类：宝马汽车组装者
class BMWBuilder : public CarBuilder {
private:
    vector<CarPart*> car; // 用于存储汽车零件的容器
public:
    void buildEngine() override {
        car.push_back(new CarPart("BMW engine")); // 建造宝马引擎并添加到容器中
    }
    void buildWheel() override {
        car.push_back(new CarPart("BMW wheel")); // 建造宝马轮子并添加到容器中
    }
    void buildBody() override {
        car.push_back(new CarPart("BMW body")); // 建造宝马车身并添加到容器中
    }
    vector<CarPart*> getCar() override {
        return car; // 返回汽车零件容器
    }
};

// 具体建造者类：奔驰汽车组装者
class BenzBuilder : public CarBuilder {
private:
    vector<CarPart*> car; // 用于存储汽车零件的容器
public:
    void buildEngine() override {
        car.push_back(new CarPart("Benz engine")); // 建造奔驰引擎并添加到容器中
    }
    void buildWheel() override {
        car.push_back(new CarPart("Benz wheel")); // 建造奔驰轮子并添加到容器中
    }
    void buildBody() override {
        car.push_back(new CarPart("Benz body")); // 建造奔驰车身并添加到容器中
    }
    vector<CarPart*> getCar() override {
        return car; // 返回汽车零件容器
    }
};

// 指挥者类：汽车制造者
class CarMaker {
private:
    CarBuilder* builder; // 持有一个汽车组装者的指针
public:
    CarMaker(CarBuilder* builder) : builder(builder) {} // 构造函数，传入一个汽车组装者的指针
    vector<CarPart*> makeCar() {
        builder->buildEngine(); // 建造引擎
        builder->buildWheel(); // 建造轮子
        builder->buildBody(); // 建造车身
        return builder->getCar(); // 返回汽车
    }
};

// 组合模式：将对象组合成树形结构以表示“部分-整体”的层次结构，使得用户对单个对象和组合对象的使用具有一致性
// 抽象组件类：汽车部件
class CarComponent {
public:
    virtual void show() = 0; // 虚函数，表示展示汽车部件的方法
    virtual ~CarComponent() {} // 虚析构函数，方便子类析构
};

// 叶子组件类：汽车零件
class CarLeaf : public CarComponent {
private:
    CarPart* part; // 持有一个汽车零件的指针
public:
    CarLeaf(CarPart* part) : part(part) {} // 构造函数，传入一个汽车零件的指针
    void show() override {
        cout << part->name << endl; // 展示汽车零件的名称
    }
};

// 复合组件类：汽车
class CarComposite : public CarComponent {
private:
    vector<CarComponent*> components; // 用于存储汽车部件的容器
public:
    CarComposite(vector<CarPart*> parts) {
        for (auto part : parts) {
            components.push_back(new CarLeaf(part)); // 将汽车零件转换为汽车部件并添加到容器中
        }
    }
    void show() override {
        for (auto component : components) {
            component->show(); // 展示每个汽车部件
        }
    }
};

// 单例模式：保证一个类仅有一个实例，并提供一个访问它的全局访问点
// 单例类：汽车仓库
class CarWarehouse {
private:
    static CarWarehouse* instance; // 静态成员变量，用于存储唯一的实例
    vector<Car*> cars; // 用于存储汽车的容器
    CarWarehouse() {} // 私有构造函数，防止外部创建实例
public:
    static CarWarehouse* getInstance() { // 静态成员函数，用于获取唯一的实例
        if (instance == nullptr) { // 如果实例不存在，就创建一个
            instance = new CarWarehouse();
        }
        return instance; // 返回实例
    }
    void addCar(Car* car) { // 成员函数，用于添加汽车到仓库
        cars.push_back(car);
    }
    void showCars() { // 成员函数，用于展示仓库中的汽车
        for (auto car : cars) {
            car->run();
        }
    }
};

// 初始化静态成员变量
CarWarehouse* CarWarehouse::instance = nullptr;

// 原型模式：用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象
// 抽象原型类：汽车原型
class CarPrototype {
public:
    virtual CarPrototype* clone() = 0; // 虚函数，表示克隆汽车原型的方法
    virtual void run() = 0; // 虚函数，表示汽车原型的运行方法
    virtual ~CarPrototype() {} // 虚析构函数，方便子类析构
};

// 具体原型类：宝马汽车原型
class BMWPrototype : public CarPrototype {
public:
    CarPrototype* clone() override {
        return new BMWPrototype(); // 返回一个新的宝马汽车原型对象
    }
    void run() override {
        cout << "BMW prototype is running" << endl; // 展示宝马汽车原型的运行方法
    }
};

// 具体原型类：奔驰汽车原型
class BenzPrototype : public CarPrototype {
public:
    CarPrototype* clone() override {
        return new BenzPrototype(); // 返回一个新的奔驰汽车原型对象
    }
    void run() override {
        cout << "Benz prototype is running" << endl; // 展示奔驰汽车原型的运行方法
    }
};

