//
//  XX_CallBack2.cpp
//  XXCPlusPlus
//
//  Created by tomxiang on 2018/11/19.
//  Copyright © 2018年 tomxiang. All rights reserved.
//

#include "XX_CallBack2.hpp"
#include <XXTiles/XXTiles.h>

namespace {
    using cb1_t = std::function<void()>;
    using callbacks_t = std::vector<cb1_t>;
    
    callbacks_t callbacks;
    
    void foo1()
    {
        std::cout << "foo1 is called" << std::endl;
    }
    
    void foo2(int i)
    {
        std::cout << "foo2 is called with: " << i << std::endl;
    }
    
} // end anonymous namespace

void testCallBack2(){
    // Bind a free function.
    cb1_t f1 = std::bind(&foo1);
    callbacks.push_back(f1);
    
    // Bind a free function with an int argument.
    // Here the argument is statically known.
    cb1_t f2 = std::bind(&foo2, 5);
    callbacks.push_back(f2);
    
    // Bind a free function with an int argument.
    // Here the argument is bound and can be changed at runtime.
    int n = 15;
    cb1_t f3 = std::bind(&foo2, std::cref(n));
    callbacks.push_back(f3);
    
    for(auto &f:callbacks){
        f();;
    }
}

