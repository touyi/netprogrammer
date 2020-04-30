#include <iostream>
#include<sys/socket.h>
//#include "../lib/lib/unp.h"
#include "../common/CommonDef.h"


int main(int argn, char* arg[]) {
    argn = 2;
    arg = new char*[2];
    arg[1] = "127.0.0.1";
    sockaddr_in serverAddr;
    char buffer[MAX_BUFFER + 1];
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sock <= 0){
        TLog.Error("Socket create fail");
    }
    if(argn <= 1){
        TLog.Error("addr error");
    }
    char* addr = arg[1];

    bzero(buffer, sizeof(buffer));
    serverAddr.sin_addr.s_addr = inet_addr(addr);
    if(serverAddr.sin_addr.s_addr == INADDR_NONE){
        TLog.Error("ip error");
    }
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(COMMON_PORT);
    if(connect(sock, (sockaddr*)&serverAddr, sizeof(serverAddr)) < 0){
        TLog.Error("connect error");
    }
    int n = 0;
    string str;
    while(cin >> str){
        if(str == "exit"){
            break;
        }
        int strlen = str.size();
        int realLen = write(sock, str.c_str(), strlen);
        if(strlen != realLen){
            TLog.Error("Write Err");
            break;
        }
        n = read(sock, buffer, MAX_BUFFER);
        if(n<0){
            TLog.Error("Read err");
        }
        cout << buffer << endl;
    }
    return 0;
}