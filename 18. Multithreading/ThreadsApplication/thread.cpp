#include "thread.h"

#include <iostream>

using namespace std;

Thread::Thread()
    : m_stopped(false)
{

}

Thread::~Thread()
{

}

void Thread::stop()
{
    m_stopped = true;
}

void Thread::run()
{
    while (!m_stopped) {
        cerr << qPrintable(m_messageStr);
    }
    m_stopped = false;
    cerr << endl;

}

