#include "CarFactory.h"
// main���������Դ���
int main() {
    // ����һ������������������
    CarFactory* bmwFactory = new BMWFactory();
    // ����һ��������������
    Car* bmw = bmwFactory->createCar();
    // ����һ������������װ�߶���
    CarBuilder* bmwBuilder = new BMWBuilder();
    // ����һ�����������߶��󣬴��뱦��������װ��
    CarMaker* bmwMaker = new CarMaker(bmwBuilder);
    // ����һ����������
    vector<CarPart*> bmwParts = bmwMaker->makeCar();
    // ����һ�������������󣬴��뱦���������
    CarComponent* bmwCar = new CarComposite(bmwParts);
    // ����һ����������ԭ�Ͷ���
    CarPrototype* bmwPrototype = new BMWPrototype();
    // ��¡һ����������ԭ�Ͷ���
    CarPrototype* bmwClone = bmwPrototype->clone();

    // ����һ������������������
    CarFactory* benzFactory = new BenzFactory();
    // ����һ��������������
    Car* benz = benzFactory->createCar();
    // ����һ������������װ�߶���
    CarBuilder* benzBuilder = new BenzBuilder();
    // ����һ�����������߶��󣬴��뱼��������װ��
    CarMaker* benzMaker = new CarMaker(benzBuilder);
    // ����һ����������
    vector<CarPart*> benzParts = benzMaker->makeCar();
    // ����һ�������������󣬴��뱼���������
    CarComponent* benzCar = new CarComposite(benzParts);
    // ����һ����������ԭ�Ͷ���
    CarPrototype* benzPrototype = new BenzPrototype();
    // ��¡һ����������ԭ�Ͷ���
    CarPrototype* benzClone = benzPrototype->clone();

    // ����һ�������ֿ���󣬻�ȡΨһ��ʵ��
    CarWarehouse* warehouse = CarWarehouse::getInstance();
    // �����������ͱ���������ӵ��ֿ���
    warehouse->addCar(bmw);
    warehouse->addCar(benz);

    // չʾ�ֿ��е�����
    cout << "Cars in the warehouse:" << endl;
    warehouse->showCars();
    // չʾ�������������
    cout << "BMW car parts:" << endl;
    bmwCar->show();
    // չʾ�������������
    cout << "Benz car parts:" << endl;
    benzCar->show();
    // չʾ��������ԭ�ͺͿ�¡�����з���
    cout << "BMW prototype and clone:" << endl;
    bmwPrototype->run();
    bmwClone->run();
    // չʾ��������ԭ�ͺͿ�¡�����з���
    cout << "Benz prototype and clone:" << endl;
    benzPrototype->run();
    benzClone->run();

    // �ͷŶ�̬������ڴ�
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
    // ����Ҫɾ���ֿ������Ϊ���ǵ�����

    return 0;
}
