//
// Created by 秦亮 on 2020/4/5.
//

#include "Tools.h"
#include<sstream>
int Tools::Add(int a, int b) {
    return a+b;
}

string Tools::IntToString(int n) {
    std::stringstream ss;
    ss << n;
    return ss.str();
}
