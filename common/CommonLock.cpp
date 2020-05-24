//
// Created by 秦亮 on 2020/5/24.
//

#include "CommonLock.h"
void Spinlock::Lock(){
    bool b = false;
    while(!this->flag.compare_exchange_weak(b, true)){
        b = false;
    }
}

void Spinlock::UnLock(){
    this->flag.store(false);
}

Spinlock::Spinlock(){
    this->flag.store(false);
}

Spinlock::~Spinlock(){
    this->UnLock();
}