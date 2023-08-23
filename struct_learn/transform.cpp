//
// Created by 田佳业 on 2023/7/20.
//
#include<iostream>
int main(){
    std::vector<double> deg_C {21.0, 30.5, 0.0, 3.2, 100.0};
    std::vector<double> deg_F(deg_C.size());
    std::transform(std::begin(deg_C), std::end(deg_C), std::begin(deg_F),[](double temp){ return 32.0 + 9.0*temp/5.0; });
    for(auto temp:deg_F){
        std::cout<<temp<<std::endl;
    }
    return 0;
}