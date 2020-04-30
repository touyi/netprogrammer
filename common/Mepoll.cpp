//
// Created by 秦亮 on 2020/4/29.
//

#include "Mepoll.h"
#include<sys/socket.h>
#include "CommonDef.h"
int socket_bind(char* address, int port){
    int fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(fd < 0){
        TLog.Error("socket_bind error");
    }
    sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    addr.sin_addr.s_addr = inet_addr(address);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    if(bind(fd, (sockaddr*)(&addr), sizeof(sockaddr)) < 0){
        TLog.Error("bind error");
    }

    listen(fd, 10);
    return fd;
}