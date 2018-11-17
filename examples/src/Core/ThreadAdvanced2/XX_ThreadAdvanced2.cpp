//
//  XX_ThreadAdvanced2.cpp
//  XXCPlusPlus
//
//  Created by tomxiang on 2018/11/17.
//  Copyright © 2018年 tomxiang. All rights reserved.
//

#include "XX_ThreadAdvanced2.hpp"
#include <XXTiles/XXTiles.h>


void thread_function(std::string &s)
{
    std::cout << "thread function ";
    std::cout << "message is = " << s << std::endl;
    s = "Justin Beaver";
}

void testThreadAdvanced2(){
    string s = "tomxiang";
    std::thread t(&thread_function,ref(s));
    
    //Function1
//    t.join();
    
    //Function2
    std::thread t2 = move(t);
    std::cout << "main thread id = " << std::this_thread::get_id() << std::endl;
    std::cout << "t thread id = " << t.get_id() << std::endl;
    std::cout << "t2 thread id = " << t2.get_id() << std::endl;

    t2.join();
    std::cout << "testThreadAdvanced2 Number of threads = "<<  std::thread::hardware_concurrency() << std::endl;
    cout << "testThreadAdvanced2结果是: " << s << endl;
}

void testAdvanced2_2()
{
    std::thread t([](){
        std::cout << "thread function" << endl;
    });
    std::cout << "----testAdvanced2_2----main thread" << endl;
    t.join();     // main thread waits for t to finish
}
