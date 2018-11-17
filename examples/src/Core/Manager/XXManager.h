//
//  XXManager.hpp
//  XXCPlusPlus
//
//  Created by tomxiang on 2018/11/13.
//  Copyright © 2018年 tomxiang. All rights reserved.
//

#ifndef XXManager_hpp
#define XXManager_hpp

#include <stdio.h>

class XXManager{
public:
    XXManager();
    ~XXManager();
    
    void testForEach();
    void testAutoType();
    void testLambda();
    auto testPostposition(int x, int y) -> int;
    void testPointNull();
    void testInherit();//继承
};

void testManager();

#endif /* XXManager_hpp */
