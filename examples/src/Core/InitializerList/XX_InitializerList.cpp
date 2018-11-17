//
//  XX_InitializerList.cpp
//  XXCPlusPlus
//
//  Created by tomxiang on 2018/11/17.
//  Copyright © 2018年 tomxiang. All rights reserved.
//

#include "XX_InitializerList.hpp"
#include <XXTiles/XXTiles.h>

class MyNumber{
public:
    MyNumber(const std::initializer_list<int> &v){
        for (auto itm:v) {
            mVec.push_back(itm);
        }
    }
    void print(){
        for (auto item:mVec) {
            cout << item << " " ;
        }
    }
private:
    vector<int> mVec;
};

void testIntialzerList(){
    MyNumber myNumber = {1,2,3,4};
    myNumber.print();
    cout << endl;
}
