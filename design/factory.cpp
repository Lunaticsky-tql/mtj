//
// Created by 田佳业 on 2023/9/10.
//
#include<iostream>

class Core {
public:
    virtual void work() = 0;
    // 如果派生类有自己独有的数据成员，则虚析构函数是必须的。
    virtual ~Core()= default;
};

class CoreA : public Core {
public:
    void work() override{
        std::cout<<"Core A is working"<<std::endl;
    }
};
class CoreB: public Core {
public:
    void work() override{
        std::cout<<"Core B is working"<<std::endl;
    }
};

class Factory {
public:
    virtual Core* createCore() = 0;
    virtual ~Factory()= default;
};

class FactoryA : public Factory {
public:
    Core* createCore() override{
        return new CoreA;
    }
};

class FactoryB : public Factory {
public:
    Core* createCore() override{
        return new CoreB;
    }
};

Core* getCore(Factory* factory){
    return factory->createCore();
}

int main(){
    Factory* factoryA = new FactoryA;
    Factory* factoryB = new FactoryB;
    Core* coreA = getCore(factoryA);
    Core* coreB = getCore(factoryB);
    coreA->work();
    coreB->work();
    return 0;
}