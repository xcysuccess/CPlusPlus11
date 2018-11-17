//
//  XX_Thread.cpp
//  XXCPlusPlus
//
//  Created by tomxiang on 2018/11/17.
//  Copyright © 2018年 tomxiang. All rights reserved.
//

#include "XX_Thread.hpp"
#include <XXTiles/XXTiles.h>

void testSecondDuration(){
    using namespace std::chrono_literals;
    std::cout << "Hello waiter" << std::endl; // flush is intentional
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(2s);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end-start;
    std::cout << "Waited " << elapsed.count() << " ms\n";
}
/**
 线程休眠

 @param n 指定时间几秒
 */
void pause_thread(int n){
    std::this_thread::sleep_for (std::chrono::seconds(n));
    std::cout << "pause of " << n << " seconds ended\n";
}

void testThreadJoin(){
    cout << "Spawning 3 threads..." << endl;
    std::thread t1 (pause_thread,5);
    std::thread t2 (pause_thread,10);
    std::thread t3 (pause_thread,20);
    std::cout << "Done spawning threads. Now waiting for them to join:\n";
    t1.join();
    t2.join();
    t3.join();
    std::cout << "All threads joined!\n";
}

void testThreadDetach(){
    std::cout << "Spawning and detaching 3 threads...\n";
    std::thread (pause_thread,1).detach();
    std::thread (pause_thread,2).detach();
    std::thread (pause_thread,3).detach();
    std::cout << "Done spawning threads.\n";
    
    std::cout << "(the main thread will now pause for 5 seconds)\n";
    // give the detached threads time to finish (but not guaranteed!):
    pause_thread(5);
}

void testThread(){
    std::cout << "testThreadAdvanced Number of threads = "<<  std::thread::hardware_concurrency() << std::endl;
    //    testThreadJoin();
    testThreadDetach();
}
