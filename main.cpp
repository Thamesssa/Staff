#include "gui.h"
#include <QPushButton>

#include <QApplication>
#include <QLocale>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    gui w;
    QPushButton* pb = new QPushButton("Process2",&w);


    w.show();
    return a.exec();
}
