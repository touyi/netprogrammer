#include <iostream>
#include<sys/socket.h>
#include "../lib/lib/unp.h"
#include "../common/CommonDef.h"

int main() {
    int listenfd, connefd;
    sockaddr_in serveraddr;
    char buffer[MAX_BUFFER + 1];
    listenfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(COMMON_PORT);

    if(bind(listenfd,(sockaddr*)&serveraddr, sizeof(serveraddr)) < 0){
        TLog.Error("bind err");
    }

    if(listen(listenfd, 1) < 0){
        TLog.Error("listen err");
    }

    while(1){
        connefd = accept(listenfd, nullptr, nullptr);
        cout << "Connet Success" << endl;
        time_t t = time(0);
        cout << ctime(&t) << endl;
        sprintf(buffer,"%.24s", ctime(&t));
        write(connefd, buffer, sizeof(buffer));
        close(connefd);
    }

    return 0;
}