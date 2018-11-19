//
//  XX_Array.cpp
//  XXCPlusPlus
//
//  Created by tomxiang on 2018/11/19.
//  Copyright © 2018年 tomxiang. All rights reserved.
//

#include "XX_Array.hpp"
#include <XXTiles/XXTiles.h>
#include <array>

void testArray(){
    std::array<int,5> ai;
    std::array<double,4> ad = {1.2, 2.1, 3.1, 4.1};
    
    std::array<double,4> ad1 = ad;
    for(auto& a:ad1){
        cout << "ad1: " << a << endl;
    }
    
    ad[-2] = 0.5;//合法
    ad.at(1) = 1.1;
    for(auto& a:ad){
        cout << "ad: " << a << endl;
    }
}
