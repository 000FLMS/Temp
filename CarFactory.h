#include <iostream>
#include <vector>
using namespace std;

// ����ģʽ������һ�����ڴ�������Ľӿڣ����������ʵ������һ����
// �����Ʒ�ࣺ����
class Car {
public:
    virtual void run() = 0; // �麯������ʾ���������з���
    virtual ~Car() {} // ������������������������
};

// �����Ʒ�ࣺ��������
class BMW : public Car {
public:
    void run() override {
        cout << "BMW is running" << endl;
    }
};

// �����Ʒ�ࣺ��������
class Benz : public Car {
public:
    void run() override {
        cout << "Benz is running" << endl;
    }
};

// ���󹤳��ࣺ��������
class CarFactory {
public:
    virtual Car* createCar() = 0; // �麯������ʾ���������ķ���
    virtual ~CarFactory() {} // ������������������������
};

// ���幤���ࣺ������������
class BMWFactory : public CarFactory {
public:
    Car* createCar() override {
        return new BMW(); // ����������������
    }
};

// ���幤���ࣺ������������
class BenzFactory : public CarFactory {
public:
    Car* createCar() override {
        return new Benz(); // ����������������
    }
};

// ������ģʽ����һ�����Ӷ���Ĺ��������ı�ʾ���룬ʹ��ͬ���Ĺ������̿��Դ�����ͬ�ı�ʾ
// ��Ʒ�ࣺ�������
class CarPart {
public:
    string name; // �������
    CarPart(string name) : name(name) {} // ���캯��
};

// ���������ࣺ������װ��
class CarBuilder {
public:
    virtual void buildEngine() = 0; // �麯������ʾ��������ķ���
    virtual void buildWheel() = 0; // �麯������ʾ�������ӵķ���
    virtual void buildBody() = 0; // �麯������ʾ���쳵��ķ���
    virtual vector<CarPart*> getCar() = 0; // �麯������ʾ��ȡ�����ķ���
    virtual ~CarBuilder() {} // ������������������������
};

// ���彨�����ࣺ����������װ��
class BMWBuilder : public CarBuilder {
private:
    vector<CarPart*> car; // ���ڴ洢�������������
public:
    void buildEngine() override {
        car.push_back(new CarPart("BMW engine")); // ���챦�����沢��ӵ�������
    }
    void buildWheel() override {
        car.push_back(new CarPart("BMW wheel")); // ���챦�����Ӳ���ӵ�������
    }
    void buildBody() override {
        car.push_back(new CarPart("BMW body")); // ���챦������ӵ�������
    }
    vector<CarPart*> getCar() override {
        return car; // ���������������
    }
};

// ���彨�����ࣺ����������װ��
class BenzBuilder : public CarBuilder {
private:
    vector<CarPart*> car; // ���ڴ洢�������������
public:
    void buildEngine() override {
        car.push_back(new CarPart("Benz engine")); // ���챼�����沢��ӵ�������
    }
    void buildWheel() override {
        car.push_back(new CarPart("Benz wheel")); // ���챼�����Ӳ���ӵ�������
    }
    void buildBody() override {
        car.push_back(new CarPart("Benz body")); // ���챼�۳�����ӵ�������
    }
    vector<CarPart*> getCar() override {
        return car; // ���������������
    }
};

// ָ�����ࣺ����������
class CarMaker {
private:
    CarBuilder* builder; // ����һ��������װ�ߵ�ָ��
public:
    CarMaker(CarBuilder* builder) : builder(builder) {} // ���캯��������һ��������װ�ߵ�ָ��
    vector<CarPart*> makeCar() {
        builder->buildEngine(); // ��������
        builder->buildWheel(); // ��������
        builder->buildBody(); // ���쳵��
        return builder->getCar(); // ��������
    }
};

// ���ģʽ����������ϳ����νṹ�Ա�ʾ������-���塱�Ĳ�νṹ��ʹ���û��Ե����������϶����ʹ�þ���һ����
// ��������ࣺ��������
class CarComponent {
public:
    virtual void show() = 0; // �麯������ʾչʾ���������ķ���
    virtual ~CarComponent() {} // ������������������������
};

// Ҷ������ࣺ�������
class CarLeaf : public CarComponent {
private:
    CarPart* part; // ����һ�����������ָ��
public:
    CarLeaf(CarPart* part) : part(part) {} // ���캯��������һ�����������ָ��
    void show() override {
        cout << part->name << endl; // չʾ�������������
    }
};

// ��������ࣺ����
class CarComposite : public CarComponent {
private:
    vector<CarComponent*> components; // ���ڴ洢��������������
public:
    CarComposite(vector<CarPart*> parts) {
        for (auto part : parts) {
            components.push_back(new CarLeaf(part)); // ���������ת��Ϊ������������ӵ�������
        }
    }
    void show() override {
        for (auto component : components) {
            component->show(); // չʾÿ����������
        }
    }
};

// ����ģʽ����֤һ�������һ��ʵ�������ṩһ����������ȫ�ַ��ʵ�
// �����ࣺ�����ֿ�
class CarWarehouse {
private:
    static CarWarehouse* instance; // ��̬��Ա���������ڴ洢Ψһ��ʵ��
    vector<Car*> cars; // ���ڴ洢����������
    CarWarehouse() {} // ˽�й��캯������ֹ�ⲿ����ʵ��
public:
    static CarWarehouse* getInstance() { // ��̬��Ա���������ڻ�ȡΨһ��ʵ��
        if (instance == nullptr) { // ���ʵ�������ڣ��ʹ���һ��
            instance = new CarWarehouse();
        }
        return instance; // ����ʵ��
    }
    void addCar(Car* car) { // ��Ա��������������������ֿ�
        cars.push_back(car);
    }
    void showCars() { // ��Ա����������չʾ�ֿ��е�����
        for (auto car : cars) {
            car->run();
        }
    }
};

// ��ʼ����̬��Ա����
CarWarehouse* CarWarehouse::instance = nullptr;

// ԭ��ģʽ����ԭ��ʵ��ָ��������������࣬����ͨ��������Щԭ�ʹ����µĶ���
// ����ԭ���ࣺ����ԭ��
class CarPrototype {
public:
    virtual CarPrototype* clone() = 0; // �麯������ʾ��¡����ԭ�͵ķ���
    virtual void run() = 0; // �麯������ʾ����ԭ�͵����з���
    virtual ~CarPrototype() {} // ������������������������
};

// ����ԭ���ࣺ��������ԭ��
class BMWPrototype : public CarPrototype {
public:
    CarPrototype* clone() override {
        return new BMWPrototype(); // ����һ���µı�������ԭ�Ͷ���
    }
    void run() override {
        cout << "BMW prototype is running" << endl; // չʾ��������ԭ�͵����з���
    }
};

// ����ԭ���ࣺ��������ԭ��
class BenzPrototype : public CarPrototype {
public:
    CarPrototype* clone() override {
        return new BenzPrototype(); // ����һ���µı�������ԭ�Ͷ���
    }
    void run() override {
        cout << "Benz prototype is running" << endl; // չʾ��������ԭ�͵����з���
    }
};

