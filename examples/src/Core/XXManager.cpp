//
//  XXManager.cpp
//  XXCPlusPlus
//
//  Created by tomxiang on 2018/11/13.
//  Copyright © 2018年 tomxiang. All rights reserved.
//

#include "XXManager.h"
#include <XXTiles/XXTiles.h>

XXManager::XXManager(){
    printf(__func__);
}
XXManager::~XXManager(){
    printf(__func__);
    printf("\n");
}

void XXManager::testForEach(){
    int nArr[5] = {1,2,3,4,5};
    int sum = 1;
    for(int x : nArr){
        sum *= x;   //数组中每个元素倍乘
    }
    printf("testForEach结果:%d\n",sum);
}
