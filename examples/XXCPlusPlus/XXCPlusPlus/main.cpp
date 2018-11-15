//
//  main.cpp
//  XXCPlusPlus
//
//  Created by tomxiang on 2018/11/13.
//  Copyright © 2018年 tomxiang. All rights reserved.
//

#include <iostream>
#include <XXTiles/XXTiles.h>

#include "XXManager.h"
#include "XX1_Function.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "----------XXManager-----------" << std::endl;
    
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
    
    std::cout << "---------testFunction---------" << std::endl;
    //stdFunction
    testFunction();
    
    return 0;

}
