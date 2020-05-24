//
// Created by 秦亮 on 2020/4/5.
//

#include "Log.h"
#include <iostream>
#include<string>
using namespace std;

void Log::Error(std::string err) {
    std::cout << err << std::endl;
    exit(-1);
}

void LogMsgInner(int level, std::string msg, int seq) {
    std::cout << "Level[" << "0" << "]:" << msg << std::endl;
}


