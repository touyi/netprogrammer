//
// Created by 秦亮 on 2020/4/29.
//

#ifndef COLINPRJ_MEPOLL_H
#define COLINPRJ_MEPOLL_H
#ifdef  EPOLL
#include "sys/epoll.h"
#endif

int socket_bind(char* address, int port);


#endif //COLINPRJ_MEPOLL_H
