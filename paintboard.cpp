#include "paintboard.h"
#include<QDebug>
#include<QPainter>
#include<QVector>
paintBoard::paintBoard(QWidget *parent) : QWidget(parent)
{
        ThreadA = new workThread(parent->size());
        ThreadA->start();
        connect(ThreadA,&workThread::ready,this,&paintBoard::ready);
}
void paintBoard::ready(QQueue<conturLine> data)
{
    qDebug()<<"paintBoard working";
    this->data = data;
    ThreadA->quit();
    ThreadA->wait();
    update();
}
void paintBoard::paintEvent(QPaintEvent *event)
{
    // 创建 QPainter 对象，用于绘制
    QPainter painter(this);

    // 设置绘制的画笔和字体
    painter.setPen(Qt::black); // 设置画笔颜色为黑色
    QFont font("Arial", 10);   // 设置字体为 Arial，大小为 10
    painter.setFont(font);     // 应用字体设置

    // 遍历等高线数据队列
    foreach (const conturLine& line, data) {
        // 绘制等高线上的点
        for (const QPointF& point : line.points) {
            painter.drawPoint(point);
        }

        // 标注高程值
        QPointF labelPosition = line.points.back(); // 标注位置为等高线上的最后一个点
        painter.drawText(labelPosition, QString::number(line.height));

        // 绘制连线
        QVector<QPointF> polyline = line.points.toVector();
        painter.drawPolyline(polyline);
    }
}

