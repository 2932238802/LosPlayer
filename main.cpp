#include "losplayer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LosPlayer w;
    w.show();
    return a.exec();
}

// 1. commonPage 非常需要 外界的 musicList 这个可以优化
// 2.
