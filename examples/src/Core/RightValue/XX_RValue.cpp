//
//  XX_RValue.cpp
//  XXCPlusPlus
//
//  Created by tomxiang on 2018/11/19.
//  Copyright © 2018年 tomxiang. All rights reserved.
//

#include "XX_RValue.hpp"
#include <XXTiles/XXTiles.h>

int getValue ()
{
    int ii = 10;
    return ii;
}

void f(int& i) { std::cout << "lvalue ref: " << i << "\n"; }
void f(int&& i) { std::cout << "rvalue ref: " << i << "\n"; }


void printReference (int& value)
{
    cout << "lvalue: value = " << value << endl;
}

void printReference (int&& value)
{
    cout << "rvalue: value = " << value << endl;
}

void testRValue(){
    int i = 77;
    f(i);    // lvalue ref called
    f(99);   // rvalue ref called
    
    //std::move 可以取地址的是左值,不能取地址的是右值
    //move不会移除
    f(std::move(i));  // 稍后介绍
    
    std::cout << getValue() << endl;;
    
    
    int ii = 11;
    printReference(ii);
    printReference(getValue());  //  printReference(99);
}
