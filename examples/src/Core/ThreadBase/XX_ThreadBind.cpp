//
//  XX_ThreadBind.cpp
//  XXCPlusPlus
//
//  Created by tomxiang on 2018/11/17.
//  Copyright © 2018年 tomxiang. All rights reserved.
//

#include "XX_ThreadBind.hpp"
#include <XXTiles/XXTiles.h>

class Foo
{
    void bar_i() { cout << "hello" << endl; }
    void bar_1i(int i) { cout << "hello: " << i << endl;}
    
public:
    void bar(){
        //        std::bind(&Foo::bar_i, this);
        //        std::thread t(&Foo::bar_i, std::ref(*this));
        std::bind(&Foo::bar_i, this);
        std::thread t(&Foo::bar_i, this);
        t.join();
    }
    void bar1(int index){
        auto handler = std::bind(&Foo::bar_1i, this, index);
        std::thread t1(handler, this);
        t1.join();
    }
};

void testThreadBind(){
    Foo f;
    //    f.bar();
    f.bar1(5);
}
