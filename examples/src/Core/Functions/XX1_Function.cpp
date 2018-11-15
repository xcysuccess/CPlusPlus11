//
//  XX1_Function.cpp
//  XXCPlusPlus
//
//  Created by tomxiang on 2018/11/15.
//  Copyright © 2018年 tomxiang. All rights reserved.
//

#include "XX1_Function.hpp"

#include <functional>
#include <iostream>
using namespace std;

std::function<int(int)> Functional;

//普通方法
int TestFunc(int a){
    return a;
}

//lambda表达式
auto lambda = [](int a)->int{
    return a;
};

//仿函数
class Functor
{
public:
    int operator()(int a){
        return a;
    }
};

//类成员函数
//类静态函数
class TestClass{
public:
    int ClassMember(int a){
        return a;
    };
    static int StaticMember(int a){
        return a;
    };
};

void testFunction(){
    // 普通函数
    Functional = TestFunc;
    int result = Functional(10);
    cout << "普通函数: " << result << endl;
    
    // Lambda表达式
    Functional = lambda;
    result = Functional(20);
    cout << "lambda表达式: " << result << endl;
    
    // 仿函数
    Functor testFunctor;
    Functional = testFunctor;
    result = Functional(30);
    cout << "仿函数: " << result << endl;
    
    // 类成员函数
    TestClass testObj;
    Functional = std::bind(&TestClass::ClassMember, testObj, std::placeholders::_1);
    result = Functional(40);
    cout << "类成员函数: " << result << endl;
    
    // 类静态函数
    Functional = TestClass::StaticMember;
    result = Functional(50);
    cout << "类静态函数: " << result << endl;
};
