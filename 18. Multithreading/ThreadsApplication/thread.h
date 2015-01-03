#ifndef THREAD_H
#define THREAD_H

#include <QThread>



class Thread : public QThread
{
    Q_OBJECT

public:
    Thread();
    ~Thread();
    void setMessage(const QString& message) {m_messageStr = message;}
    void stop();

protected:
    void run();

private:
    QString m_messageStr;
    volatile bool m_stopped;
};

#endif // THREAD_H
