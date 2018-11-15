//
//  XX2_Lambda.cpp
//  XXCPlusPlus
//
//  Created by tomxiang on 2018/11/15.
//  Copyright © 2018年 tomxiang. All rights reserved.
//

#include "XX2_Lambda.hpp"
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class CTest{
public:
    CTest(): m_nData(20){ NULL; }
    void TestLambda()
    {
        vector<int> vctTemp;
        vctTemp.push_back(1);
        vctTemp.push_back(2);
        
        // 无函数参考对象, 输出: 1 2
        {
            for_each(vctTemp.begin(), vctTemp.end(), [](int v){ cout << v << endl; });
        }
        // 以值方式传递作用域内所有可见的局部变量（包括this），输出：11 12
        {
            int a = 10;
            for_each(vctTemp.begin(), vctTemp.end(), [=](int v){ cout << v+a << endl; });
        }
        // 以引用方式传递作用域内所有可见的局部变量（包括this），输出：11 13 12
        {
            int a = 10;
            for_each(vctTemp.begin(), vctTemp.end(), [&](int v)mutable{ cout << v+a << endl; a++; });
            cout << a << endl;
        }
        // 以值方式传递局部变量a，输出：11 13 10
        {
            int a = 10;
            for_each(vctTemp.begin(), vctTemp.end(), [a](int v)mutable{ cout << v+a << endl; a++; });
            cout << a << endl;
        }
        // 以引用方式传递局部变量a，输出：11 13 12
        {
            int a = 10;
            for_each(vctTemp.begin(), vctTemp.end(), [&a](int v){ cout << v+a << endl; a++; });
            cout << a << endl;
        }
        // 传递this，输出：21 22
        {
            for_each(vctTemp.begin(), vctTemp.end(), [this](int v){ cout << v+m_nData << endl; });
        }
        // 除b按引用传递外，其他均按值传递，输出：11 12 17
        {
            int a = 10;
            int b = 15;
            for_each(vctTemp.begin(), vctTemp.end(), [=, &b](int v){ cout << v+a << endl; b++; });
            cout << b << endl;
        }
        //
        
        
    }
    
    
    
    
private:
    int m_nData;
    
};
