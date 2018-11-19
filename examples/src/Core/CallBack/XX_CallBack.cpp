//
//  XX_CallBack.cpp
//  XXCPlusPlus
//
//  Created by tomxiang on 2018/11/19.
//  Copyright © 2018年 tomxiang. All rights reserved.
//

#include "XX_CallBack.hpp"
#include <XXTiles/XXTiles.h>

namespace {
    using cb1_t = std::function<void()>;
    using cb2_t = std::function<void(string&)>;
    
    void foo1()
    {
        std::cout << "foo1 is called\n";
    }
    
    void foo2(string& x)
    {
        x = "50";
        std::cout << "foo2 before is called with: " << x << "\n";
    }
    
    struct S {
        void foo3()
        {
            std::cout << "foo3 is called.\n";
        }
    };
}

void testCallBack(){
    //Bind a free function.
    cb1_t f1 = std::bind(&foo1);
    //Invoke the function foo1.
    f1();
    
    string x = "60";
    cb2_t f2 = std::bind(&foo2, std::placeholders::_1);
    f2(x);
    std::cout << "foo2 after is called with: " << x << "\n";

    S s;
    cb1_t f3 = std::bind(&S::foo3,&s);
    f3(); 
}


