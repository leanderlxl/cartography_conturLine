#ifndef WORKTHREAD_H
#define WORKTHREAD_H
#include<QObject>
#include<QThread>
#include"mapobject.h"
#include"filereader.h"
class workThread:public QThread
{
    Q_OBJECT
public:
    workThread() = default;
    workThread(QSize s);
    ~workThread();
    void run();
private:

    fileReader *rd;
signals:
    void ready(QQueue<conturLine> data);

};

#endif // WORKTHREAD_H
