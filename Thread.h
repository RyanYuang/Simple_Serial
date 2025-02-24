//
// Created by Yuang Ryan on 2025/2/20.
//

#ifndef SIMPLE_SERIALL_THREAD_H
#define SIMPLE_SERIALL_THREAD_H

#include "QThread"
#include "QMutex"
#include "QDebug"
class Thread :public QThread
{
public:
    Thread();
    virtual void run(){};
    void Thread_Suspend();
    void Thread_Resume();
    volatile bool stop_;
    bool Suspend;
    QMutex Lock_;


};

#endif //SIMPLE_SERIALL_THREAD_H
