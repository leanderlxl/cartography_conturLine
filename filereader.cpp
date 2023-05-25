#include "filereader.h"
#include<QDebug>
#include<QTextStream>
#include<QStringList>

fileReader::fileReader(QString fileUrl,QSize s)
{
    fs = new QFile(fileUrl);
    if(!fs->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"file not open! check url or File exist!";
    }
//    qDebug()<<s.height()<<" "<<s.width(); //600 800
    this->s = s;
}
void fileReader::read()
{
    QTextStream in(fs);
    QPointF max;
    QPointF min;

    //skip the first two lines
    in.readLine();
    in.readLine();



    //read the extent and write max and min
    QString line = in.readLine();
    QStringList strList = line.split(',');
           //set the max
    QString item = strList[0];
    float var = item.toFloat();
    max.setY(var);
    item = strList[1];
    var = item.toFloat();
    max.setX(var);
          //set the min
     item = strList[2];
     var = item.toFloat();
    min.setY(var);
    item = strList[3];
    var = item.toFloat();
    min.setX(var);
    conturLine cl;
    cl.points.push_back(min);
    cl.points.push_back(max);
    line = in.readLine();
    cl.label = line;
    line = in.readLine();
    cl.height = line.toFloat();
//    data.push_back(cl);
    while(!in.atEnd())
    {
        line = in.readLine();
        if(line == "END")break;
        int count = line.toInt();
        conturLine cl_;
        for (int i = 0; i < count; ++i) {
           line = in.readLine();
           strList = line.split(',');
           item = strList[0];
           var = item.toFloat();
           QPointF p;
           double screenX = (var - min.x()) / (max.x() - min.x()) * s.width();
           p.setX(screenX);
           item = strList[1];
           var = item.toFloat();
           double screenY = s.height() - (var - min.y()) / (max.y() - min.y()) * s.height();
           p.setY(screenY);
           cl_.points.push_back(p);
        }
        line = in.readLine();
        cl_.label = line;
        line = in.readLine();
        cl_.height = line.toInt();
        data.push_back(cl_);
    }


}
