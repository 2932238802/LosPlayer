#include "musicslider.h"
#include "ui_musicslider.h"

MusicSlider::MusicSlider(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MusicSlider)
{
    ui->setupUi(this);
    initUi();
}

MusicSlider::~MusicSlider()
{
    delete ui;
}

void MusicSlider::initUi()
{
    setStyleSheet(MUSIC_SLIDER);


}
