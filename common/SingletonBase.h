//
// Created by 秦亮 on 2020/4/5.
//

#ifndef COLINPRJ_SINGLETONBASE_H
#define COLINPRJ_SINGLETONBASE_H

template <class T>
class SingletonBase {
protected:
    static T* instance;
    SingletonBase() = default;
public:
    static T GetInstance();

};

template <class T>
T* SingletonBase<T>::instance = nullptr;

template <class T>
T SingletonBase<T>::GetInstance() {
    if(SingletonBase<T>::instance == nullptr){
        SingletonBase<T>::instance = new T();
    }
    return *SingletonBase<T>::instance;
}


#endif //COLINPRJ_SINGLETONBASE_H
