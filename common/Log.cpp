//
// Created by 秦亮 on 2020/4/5.
//

#include "Log.h"
#include "../lib/lib/unp.h"
#include <iostream>
#include<string>
using namespace std;
void Log::Error(string err) {
    err_quit(err.c_str());
}