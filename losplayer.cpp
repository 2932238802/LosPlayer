#include "losplayer.h"
#include "ui_losplayer.h"

LosPlayer::LosPlayer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LosPlayer)
{
    ui->setupUi(this);
}

LosPlayer::~LosPlayer()
{
    delete ui;
}
