#include <QApplication>
#include "firstwindow.h"
#include <iostream>
#include <conio.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    firstWindow firstwindow;
    firstwindow.show();

    return app.exec();
}
