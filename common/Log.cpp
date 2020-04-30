//
// Created by 秦亮 on 2020/4/5.
//

#include "Log.h"
#include <iostream>
#include<string>
using namespace std;
void Log::Error(string err) {
    cout << err << endl;
    exit(-1);
}