#include<iostream>
#include"matrix.h"
#include"matrix.cpp"

int main()
{
    auto A = new Matrix<int,3,4>;
    *A<<1,2,3,4,5,6,7,8,9,10,11,12;
    auto B = new Matrix<int,4,4>;
    B->Identity();
    auto C = *A**B;
    std::cout<<C<<std::endl;
    C *=3;
    std::cout<<C<<std::endl;
    delete A, B;
    A = nullptr;
    B = nullptr;
}
