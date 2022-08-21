#include "calculate.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    calculate w;
    w.show();
    return a.exec();
}
