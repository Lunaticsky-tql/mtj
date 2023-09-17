//
// Created by 田佳业 on 2023/9/10.
//
#include<iostream>
class CPU{
public:
    virtual ~CPU()= default;
    virtual void work() = 0;
};

class AMDRyzen : public CPU{
public:
    void work() override{
        std::cout<<"AMD Ryzen is working"<<std::endl;
    }
};

class IntelCore : public CPU{
public:
    void work() override{
        std::cout<<"Intel Core is working"<<std::endl;
    }
};

class GPU{
public:
    virtual ~GPU()= default;
    virtual void work() = 0;
};

class AMDRadeon : public GPU{
public:
    void work() override{
        std::cout<<"AMD Radeon is working"<<std::endl;
    }
};

class IntelArc : public GPU{
public:
    void work() override{
        std::cout<<"Intel Arc is working"<<std::endl;
    }
};

class Factory{
public:
    virtual CPU* createCPU() = 0;
    virtual GPU* createGPU() = 0;
    virtual ~Factory()= default;
};

class AMD : public Factory{
public:
    CPU* createCPU() override{
        return new AMDRyzen;
    }
    GPU* createGPU() override{
        return new AMDRadeon;
    }
};

class Intel : public Factory{
public:
    CPU* createCPU() override{
        return new IntelCore;
    }
    GPU* createGPU() override{
        return new IntelArc;
    }
};

class Processor{
public:
    Processor(CPU* cpu,GPU* gpu):cpu(cpu),gpu(gpu){}
    void work(){
        cpu->work();
        gpu->work();
    }
private:
    CPU* cpu;
    GPU* gpu;
};
Processor* getProcessor(Factory* factory){
    return new Processor(factory->createCPU(),factory->createGPU());
}
int main(){
    Factory* amd = new AMD;
    Factory* intel = new Intel;
    Processor* amdProcessor = getProcessor(amd);
    Processor* intelProcessor = getProcessor(intel);
    amdProcessor->work();
    intelProcessor->work();
    delete amdProcessor;
    delete intelProcessor;
    delete amd;
    delete intel;
    return 0;
}