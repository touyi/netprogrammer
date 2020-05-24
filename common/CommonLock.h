//
// Created by 秦亮 on 2020/5/24.
//

#ifndef COLINPRJ_COMMONLOCK_H
#define COLINPRJ_COMMONLOCK_H

#include <atomic>
class ILock{
public:
    virtual void Lock() = 0;

    virtual void UnLock() = 0;
    virtual ~ILock() = default;
};

class Spinlock : public ILock {
private:
    std::atomic<bool> flag;
public:
    void Lock();
    void UnLock();
    Spinlock();
    virtual ~Spinlock();
};




#endif //COLINPRJ_COMMONLOCK_H
