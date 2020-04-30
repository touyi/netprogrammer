#include <iostream>
#include<sys/socket.h>
//#include "../lib/lib/unp.h"
#include "../common/CommonDef.h"
#include "Process.h"
#include "../common/Mepoll.h"

#define POLLSIZE 10
void child_ctl(int signo){
    int stat = 0;
    int pid = 0;
    while((pid = waitpid(-1, &stat, WNOHANG))>0){
        cout << "Child terminal pid:" << pid << endl;
    }
    return;
}

int main() {
    signal(SIGCHLD, child_ctl);
    int listenfd = socket_bind("0.0.0.0",COMMON_PORT);

    int pollfd = epoll_create(POLLSIZE);

    if(pollfd < 0){
        TLog.Error("epoll_create error");
    }

    epoll_event ev;
    ev.events = EPOLLIN;
    ev.data.fd = listenfd;
    epoll_ctl(pollfd,EPOLL_CTL_ADD, listenfd, &ev);
    epoll_event events[POLLSIZE];
    int ret = 0;
    while(ret = epoll_wait(pollfd, events, POLLSIZE, -1)){
        for(int i = 0;i<ret;i++){
            cout << "have" << endl;
            epoll_event e = events[i];
            if(e.data.fd == listenfd){
                int ac = accept(listenfd, nullptr, nullptr);
                char *buffer = "ni hao";
                cout << "ac" << endl;
                write(ac, buffer, sizeof(buffer));
                close(ac);
            }
        }
    }
    return 0;
}