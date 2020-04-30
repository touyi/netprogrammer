//
// Created by 秦亮 on 2020/4/5.
//

#ifndef COLINPRJ_TOOLS_H
#define COLINPRJ_TOOLS_H


#include "SingletonBase.h"
#include<string>
using std::string;
class Tools: public SingletonBase<Tools> {
public:
    int Add(int a,int b);
    string IntToString(int n);
};


#endif //COLINPRJ_TOOLS_H
