//
// Created by 秦亮 on 2020/4/11.
//

//#include "../common/threadPool/ThreadPool.h"

#include"../common/CommonDef.h"
#include"../common/Log.h"

using namespace std;


int main(){
    LogMsg(1, "this is {0}, and {1}", 12, "kk");
    return 0;
}

//Spinlock mlock;
//atomic<int> inx;
//void fun(){
//
//    for(int i = 0;i<500000;i++){
//
//        inx++;
//    }
//}
//vector<thread> threads;
//int main(){
//    threads.clear();
//    inx.store(0);
//    time_t t = clock();
//    TThreadPool pool;
//    pool.Init(3);
//    for(int i = 0;i<10;i++){
//        //threads.push_back(std::move(thread(fun)));
//        pool.AddTask(fun);
//    }
//    pool.WaitAllTaskEnd();
//
////    for(int i = 0;i<threads.size();i++){
////        threads[i].join();
////    }
//
//    //std::this_thread::sleep_for(std::chrono::seconds(1));
//    cout << "Time:" << clock() - t << endl;
//    cout << inx << endl;
//    return 0;
//}