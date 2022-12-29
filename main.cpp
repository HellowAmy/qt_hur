#include "widget.h"
#include "wid_home.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();
    wid_home k;
    k.show();
    return a.exec();
}
