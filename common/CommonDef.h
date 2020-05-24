//
// Created by 秦亮 on 2020/4/5.
//

#ifndef COLINPRJ_COMMONDEF_H
#define COLINPRJ_COMMONDEF_H

#define COMMON_PORT 2020
#define MAX_BUFFER 1024
#include<sys/wait.h>
#include <netinet/in.h>
#include<string.h>
#include <arpa/inet.h>
#include "Tools.h"
#include "Log.h"
#include <netinet/in.h>
#include <sys/unistd.h>
#include<iostream>
using std::cout;
using std::endl;
using std::cin;

#define TLog Log::GetInstance()

#endif //COLINPRJ_COMMONDEF_H

