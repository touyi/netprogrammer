//
// Created by 秦亮 on 2020/4/5.
//

#ifndef COLINPRJ_LOG_H
#define COLINPRJ_LOG_H

#include "SingletonBase.h"
#include <iostream>
#include<string>
#include<sstream>
class Log : public SingletonBase<Log>{
private:

public:
    void Error(std::string err);
};


void LogMsgInner(int level, std::string msg, int seq);

template<class T, class...Args>
void LogMsgInner(int level, std::string msg, int seq, T arg, Args...args) {

    std::string tmpMsg = msg;
    try {
        std::stringstream strStream;
        strStream.str("");
        strStream << "{" << seq << "}";
        std::string targetStr = strStream.str();
        strStream.str("");
        strStream << arg;

        std::string replaceStr = strStream.str();

        tmpMsg = msg.replace(msg.find(targetStr), targetStr.length(), replaceStr, 0, targetStr.length());
    }
    catch (std::exception e){
        std::cout << e.what() << std::endl;
    }
    LogMsgInner(level, tmpMsg, seq + 1, args...);
}

template<class...Args>
void LogMsg(int level, std::string msg, Args... args) {
    LogMsgInner(level, msg, 0, args...);
}

#endif //COLINPRJ_LOG_H
