//
// Created by 秦亮 on 2020/5/24.
//

#ifndef COLINPRJ_TTHREADPOOL_H
#define COLINPRJ_TTHREADPOOL_H
#include<functional>
#include<vector>
#include<thread>
#include<string>
#include<mutex>
#include<condition_variable>
#include<deque>

#define __DEBUG_LOG(msg)
class TThreadPool {
private:
    enum class TaskState{
        WaitRunning,
        Runing,
        End,
    };

    class Task{
    public:
        std::function<void()> Fun;
        TaskState State;
        long TaskID;
    };
    int taskIDAlloctor;

    std::deque<Task*> m_TaskList;

private:
    // 队列及其锁
    std::deque<const Task*> m_ThreadHandleTaskList;
    std::vector<std::thread*> thread_List;
    std::mutex m_mutex;
    std::condition_variable m_cond;
private:
    std::atomic<int> wait_end_task_count;
    std::atomic<bool> is_end;
private:
    int mainFunc();

    Task *getOneTask();
private:
    // log
    void Log(std::string msg);
public:

    void Init(int initThread = 3);
    long AddTask(const std::function<void()> &);
    void WaitAllTaskEnd();
    void StopAllTask();
    TThreadPool();
    ~TThreadPool();
};


#endif //COLINPRJ_TTHREADPOOL_H
