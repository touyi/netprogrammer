//
// Created by 秦亮 on 2020/4/11.
//

#ifndef COLINPRJ_PROCESS_H
#define COLINPRJ_PROCESS_H

#include "../common/CommonDef.h"

class Process {
private:
    char readBuffer[MAX_BUFFER];
public:
    void SockHandle(int sockfd);
};


#endif //COLINPRJ_PROCESS_H
