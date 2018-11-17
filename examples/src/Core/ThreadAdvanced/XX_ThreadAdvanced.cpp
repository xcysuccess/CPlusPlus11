//
//  XX_ThreadAdvanced.cpp
//  XXCPlusPlus
//
//  Created by tomxiang on 2018/11/17.
//  Copyright © 2018年 tomxiang. All rights reserved.
//
//joinable ： 代表该线程是可执行线程。
//not-joinable ：通常一下几种情况会导致线程成为not-joinable
//     1） 由thread的缺省构造函数构造而成(thread()没有参数)。
//     2） 该thread被move过（包括move构造和move赋值）
//     3） 该线程调用过join或者detach

#include "XX_ThreadAdvanced.hpp"
#include <XXTiles/XXTiles.h>

void mythread()
{
//    cout << "tomxiangtomxiang" << endl;
}

void testThreadAdvanced(){
    std::thread foo;
    std::thread bar(mythread);//joinable::可执行线程,有参数
    
    std::cout << "Joinable after construction:\n" << std::boolalpha;
    std::cout << "foo: " << foo.joinable() << endl;
    std::cout << "bar: " << bar.joinable() << endl;
    
    if (foo.joinable())
        foo.join();
    if (bar.joinable())
        bar.join();
    
    std::cout << "Joinable after joining:\n" << std::boolalpha;
    std::cout << "foo: " << foo.joinable() << endl;
    std::cout << "bar: " << bar.joinable() << endl;
}
