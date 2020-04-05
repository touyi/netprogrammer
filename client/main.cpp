#include <iostream>
#include<sys/socket.h>
#include "../lib/lib/unp.h"
#include "../common/CommonDef.h"


int main(int argn, char* arg[]) {
    sockaddr_in serverAddr;
    char buffer[MAX_BUFFER + 1];
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sock <= 0){
        TLog.Error("Socket create fail");
    }
//    if(argn <= 1){
//        TLog.Error("addr error");
//    }
    //char* addr = arg[1];
    char* addr = "127.0.0.1";

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
    while((n = read(sock, buffer, MAX_BUFFER)) > 0){
        buffer[n] = 0;
        cout << buffer << endl;
        cout << 1 << endl;
    }
    if(n < 0){
        TLog.Error("Read err");
    }
    return 0;
}