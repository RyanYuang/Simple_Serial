//
// Created by Yuang Ryan on 2025/2/20.
//

#include "Thread.h"

Thread::Thread()
{
    stop_ = false;
    Suspend = false;


}

/* 线程挂起函数 */
void Thread::Thread_Suspend()
{
    qDebug()<<"Thread"<< this->currentThreadId()<<"Suspended";
    this->Lock_.lock();
    Suspend = true;
}

/* 线程恢复函数 */
void Thread::Thread_Resume()
{
    qDebug()<<"Thread"<< this->currentThreadId()<<"Resume";
    this->Lock_.unlock();
    Suspend = false;
}
