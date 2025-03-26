#include "mywidget.h"
#include <iostream>
#include <QApplication>//应用程序
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //窗口对象，父类是QWighet
    myWidget w;

    w.show();
    return a.exec();
}
