//
// Created by 秦亮 on 2020/4/5.
//

#ifndef COLINPRJ_LOG_H
#define COLINPRJ_LOG_H

#include "SingletonBase.h"
#include<string>
class Log : public SingletonBase<Log> {
public:
    void Error(std::string err);

};


#endif //COLINPRJ_LOG_H
