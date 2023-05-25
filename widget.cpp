#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    pb = new paintBoard(this);
    pb->setGeometry(0,0,this->width(),this->height());
    qDebug()<<this->width()<<" "<<this->height();
}

Widget::~Widget()
{
    delete ui;
    delete pb;
}

