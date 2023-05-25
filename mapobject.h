#ifndef MAPOBJECT_H
#define MAPOBJECT_H
#include<QPointF>
#include<QQueue>
#include<QString>
#include<QRgb>
class mapObject
{
public:
    mapObject();
};
struct conturLine
{
    conturLine() {}
    QQueue<QPointF> points;
    QString label;
    int height;
};
#endif // MAPOBJECT_H
