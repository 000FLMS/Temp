#include "CarFactory.h"
// main函数：测试代码
int main() {
    // 创建一个宝马汽车工厂对象
    CarFactory* bmwFactory = new BMWFactory();
    // 创建一个宝马汽车对象
    Car* bmw = bmwFactory->createCar();
    // 创建一个宝马汽车组装者对象
    CarBuilder* bmwBuilder = new BMWBuilder();
    // 创建一个汽车制造者对象，传入宝马汽车组装者
    CarMaker* bmwMaker = new CarMaker(bmwBuilder);
    // 制造一个宝马汽车
    vector<CarPart*> bmwParts = bmwMaker->makeCar();
    // 创建一个宝马汽车对象，传入宝马汽车零件
    CarComponent* bmwCar = new CarComposite(bmwParts);
    // 创建一个宝马汽车原型对象
    CarPrototype* bmwPrototype = new BMWPrototype();
    // 克隆一个宝马汽车原型对象
    CarPrototype* bmwClone = bmwPrototype->clone();

    // 创建一个奔驰汽车工厂对象
    CarFactory* benzFactory = new BenzFactory();
    // 创建一个奔驰汽车对象
    Car* benz = benzFactory->createCar();
    // 创建一个奔驰汽车组装者对象
    CarBuilder* benzBuilder = new BenzBuilder();
    // 创建一个汽车制造者对象，传入奔驰汽车组装者
    CarMaker* benzMaker = new CarMaker(benzBuilder);
    // 制造一个奔驰汽车
    vector<CarPart*> benzParts = benzMaker->makeCar();
    // 创建一个奔驰汽车对象，传入奔驰汽车零件
    CarComponent* benzCar = new CarComposite(benzParts);
    // 创建一个奔驰汽车原型对象
    CarPrototype* benzPrototype = new BenzPrototype();
    // 克隆一个奔驰汽车原型对象
    CarPrototype* benzClone = benzPrototype->clone();

    // 创建一个汽车仓库对象，获取唯一的实例
    CarWarehouse* warehouse = CarWarehouse::getInstance();
    // 将宝马汽车和奔驰汽车添加到仓库中
    warehouse->addCar(bmw);
    warehouse->addCar(benz);

    // 展示仓库中的汽车
    cout << "Cars in the warehouse:" << endl;
    warehouse->showCars();
    // 展示宝马汽车的零件
    cout << "BMW car parts:" << endl;
    bmwCar->show();
    // 展示奔驰汽车的零件
    cout << "Benz car parts:" << endl;
    benzCar->show();
    // 展示宝马汽车原型和克隆的运行方法
    cout << "BMW prototype and clone:" << endl;
    bmwPrototype->run();
    bmwClone->run();
    // 展示奔驰汽车原型和克隆的运行方法
    cout << "Benz prototype and clone:" << endl;
    benzPrototype->run();
    benzClone->run();

    // 释放动态分配的内存
    delete bmwFactory;
    delete bmw;
    delete bmwBuilder;
    delete bmwMaker;
    delete bmwCar;
    delete bmwPrototype;
    delete bmwClone;
    delete benzFactory;
    delete benz;
    delete benzBuilder;
    delete benzMaker;
    delete benzCar;
    delete benzPrototype;
    delete benzClone;
    // 不需要删除仓库对象，因为它是单例的

    return 0;
}
