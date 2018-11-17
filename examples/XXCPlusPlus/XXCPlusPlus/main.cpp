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
#include "XX2_Lambda.hpp"
#include "XX_OverrideFinal.hpp"
#include "XX_Thread.hpp"
#include "XX_ThreadBind.hpp"
#include "XX_InitializerList.hpp"
#include "XX_ThreadAdvanced.hpp"
#include "XX_ThreadAdvanced2.hpp"

int main(int argc, const char * argv[]) {
    //testManager
    std::cout << "----------testManager-----------" << std::endl;
    testManager();

    //testFunction
    std::cout << "----------testFunction-----------" << std::endl;
    testFunction();
    
    //testLambda
    std::cout  << "-----------testLambda-----------" << std::endl;;
    testLambda();
    
    //testOverrideFinal
    std::cout << "-----------testOverrideFinal-----------" << std::endl;
    testOverrideFinal();
    
    //thread
    std::cout << "-----------testThread-----------" << std::endl;
    testThread();
    
    //threadBind
    std::cout << "-----------threadBind-----------" << std::endl;
    testThreadBind();
    
    //threadIntialzerList
    std::cout << "-----------threadIntialzerList-----------" << std::endl;
    testIntialzerList();
    
    //testThreadAdvanced
    std::cout << "-----------testThreadAdvanced-----------" << std::endl;
    testThreadAdvanced();
    
    //testThreadAdvanced2
    cout << "-----------testThreadAdvanced2-----------" << std::endl;
    testThreadAdvanced2();
    testAdvanced2_2();
    
    return 0;

}
