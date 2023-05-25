#ifndef PAINTBOARD_H
#define PAINTBOARD_H

#include <QWidget>
#include"mapobject.h"
#include<workthread.h>
class paintBoard : public QWidget
{
    Q_OBJECT
public:
    explicit paintBoard(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    ~paintBoard()
    {
        delete ThreadA;
    }
private:
    QQueue<conturLine> data;
    workThread *ThreadA;
public slots:
    void ready(QQueue<conturLine> data);
};

#endif // PAINTBOARD_H
