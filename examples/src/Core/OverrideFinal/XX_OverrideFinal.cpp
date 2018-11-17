//
//  XX_OverrideFinal.cpp
//  XXCPlusPlus
//
//  Created by tomxiang on 2018/11/16.
//  Copyright © 2018年 tomxiang. All rights reserved.
//
//  1.继承的时候会有无意重写父类方法的问题---
//  2.virtual中如果方法一样,参数类型不同可能会被重复调用---

#include "XX_OverrideFinal.hpp"
#include <XXTiles/XXTiles.h>

//第一种情况----accidentally overrides A::func
class A
{
public:
    virtual void func();
};
class B: A{};
class F{};
class D: A, F
{
public:
    void func();//meant to declare a new function but
};

//第二种情况----
class  G
{
public:
    virtual void func(double x){
        cout << "G: " << x << endl;
    };
};

class H: public G
{
public:
    void func(double x) override final{
        cout << "H: " << x << endl;
    };
};

class Q: public H
{
public:
//    void func(double x){
//        cout << "H: " << x << endl;
//    };
};


void testOverrideFinal(){
    H *p=new H;
    p->func(5.0);
//    p->func(5.0); // calls H::f
}
