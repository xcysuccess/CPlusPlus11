//
//  XXManager.cpp
//  XXCPlusPlus
//
//  Created by tomxiang on 2018/11/13.
//  Copyright © 2018年 tomxiang. All rights reserved.
//  https://www.kancloud.cn/wangshubo1989/new-characteristics/99704

#include "XXManager.h"
#include <XXTiles/XXTiles.h>

class Base{
public:
    virtual void f(short){
        std::cout << "B::f" << std::endl;
    }
};

class D:public Base{
public:
    virtual void f(int) {
        std::cout << "D::f" << std::endl;
    }
};

XXManager::XXManager(){
    printf(__func__);
}
XXManager::~XXManager(){
    printf(__func__);
    cout << std::endl;
}

void XXManager::testForEach(){
    int nArr[5] = {1,2,3,4,5};
    int sum = 1;
    for(int x : nArr){
        sum *= x;   //数组中每个元素倍乘
    }
    printf("testForEach结果:%d\n",sum);
}

void XXManager::testAutoType(){
    cout << "testAutoType:";
//    vector<int> vec(6,10);
    vector<int> vec = {7, 5, 16, 8};
    for(auto iterAuto = vec.begin();iterAuto != vec.end(); ++iterAuto) {
        cout << *iterAuto << " ";
    }
    cout << std::endl;
}

void XXManager::testLambda(){
    auto func = [](int i){
        return i+4;
    };
    cout << "testLambda:";
    cout << func(10) << std::endl;
}

auto XXManager::testPostposition(int x, int y) -> int{
    return x + y;
}
void XXManager::testPointNull(){
    int *p1 = NULL;
    int *p = nullptr;
    if(p == p1){
        cout << "p==p1" << endl;
    }else{
        cout << "p!=p1" << endl;
    }
}

void XXManager::testInherit(){
    cout<<"testInherit"<<endl;
    D p;
    p.f(5);
}


void testManager(){
    SP<XXManager> manager = SP<XXManager>(new XXManager());
    //foreach
    manager->testForEach();
    //auto
    manager->testAutoType();
    //Lambda
    manager->testLambda();
    //后置返回值
    int sum = manager->testPostposition(10,5);
    std::cout<<"testPostposition:sum:"<<sum<<std::endl;
    //testNull
    manager->testPointNull();
    //testInherit:继承
    manager->testInherit();
}
