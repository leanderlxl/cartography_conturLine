#include "workthread.h"
#include<QDebug>
workThread::workThread(QSize s)
{
    rd = new fileReader("D:\\QtProject\\contur_line\\data.txt",s);
}
void workThread::run()
{
   rd->read();
   qDebug()<<"file ready signal released";
   emit ready(rd->data);
}
workThread::~workThread()
{
    delete rd;
    rd = nullptr;
}
