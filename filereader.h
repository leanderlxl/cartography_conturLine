#ifndef FILEREADER_H
#define FILEREADER_H

#include <QObject>
#include<QString>
#include<QFile>
#include<QSize>
#include"mapobject.h"
class fileReader:public QObject
{
    Q_OBJECT
public:
    fileReader() = default;
    fileReader(QString fileUrl,QSize s);
    void read();
    ~fileReader()
    {
        fs->close();
        delete fs;
        fs = nullptr;
    }
public:
    QQueue<conturLine> data;
private:
    QFile* fs;
    QSize s;
};

#endif // FILEREADER_H
