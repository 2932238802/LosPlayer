#include "losplayer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LosPlayer w;
    w.show();
    return a.exec();
}
