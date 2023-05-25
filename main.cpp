#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qRegisterMetaType<QQueue<conturLine>>("QQueue<conturLine>");
    Widget w;
    w.show();
    return a.exec();
}
