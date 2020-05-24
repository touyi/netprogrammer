//
// Created by 秦亮 on 2020/5/24.
//

#include "TThreadPool.h"
#include<iostream>
using namespace std;

void TThreadPool::Init(int initThread) {
    if(initThread < this->thread_List.size()){
        Log("size too small");
        return;
    }
    int newThreadNum = initThread - this->thread_List.size();
    for(int i = 0;i<newThreadNum;i++){
        std::function<void()> fun = std::bind(&TThreadPool::mainFunc, this);
        this->thread_List.push_back(new thread(fun));
    }
}

void TThreadPool::WaitAllTaskEnd() {
    while(wait_end_task_count.load() > 0){

    }
}

long TThreadPool::AddTask(const std::function<void()> &fun) {
    Task* newTask = new Task();
    // TODO 移动语义
    newTask->Fun = fun;
    newTask->State = TaskState::WaitRunning;
    newTask->TaskID = ++taskIDAlloctor;
    std::unique_lock<mutex> lck(this->m_mutex);
    this->m_TaskList.push_back(newTask);
    wait_end_task_count++;
    lck.unlock();
    m_cond.notify_one();
    return newTask->TaskID;
}

void TThreadPool::StopAllTask() {
    // TODO
}

TThreadPool::~TThreadPool() {
    this->StopAllTask();
    is_end.store(true);
    m_cond.notify_all();
    for(int i = 0;i<this->thread_List.size();i++){
        this->thread_List[i]->join();
        __DEBUG_LOG("End Thread");
    }
    __DEBUG_LOG("End");
}

void TThreadPool::Log(std::string msg) {
    cout << msg << endl;
}

int TThreadPool::mainFunc() {

    Task* nextTask = nullptr;
    while(!is_end && (nextTask = getOneTask()) != nullptr){
        nextTask->State = TaskState::Runing;
        nextTask->Fun();
        nextTask->State = TaskState::End;
        wait_end_task_count--;
    }
    return 0;
}

TThreadPool::Task *TThreadPool::getOneTask() {
    std::unique_lock<mutex> lck(this->m_mutex);
    while(m_TaskList.size()<=0 && !is_end.load()){
        m_cond.wait(lck);
    }
    if(is_end.load()){
        return nullptr;
    }
    Task* task = this->m_TaskList.front();
    this->m_TaskList.pop_front();
    this->m_ThreadHandleTaskList.push_back(task);
    return task;
}

TThreadPool::TThreadPool() {
    taskIDAlloctor = 0;
    wait_end_task_count = 0;
    is_end = false;
}
