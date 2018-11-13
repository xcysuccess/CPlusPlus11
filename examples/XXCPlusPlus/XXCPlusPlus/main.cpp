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

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    SP<XXManager> manager = SP<XXManager>(new XXManager());
    //foreach
    manager->testForEach();
    
    return 0;

}
