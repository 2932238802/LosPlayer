#pragma once
#include <QWidget>
#include"style/style.h"
namespace Ui {
class MusicSlider;
}

class MusicSlider : public QWidget
{
    Q_OBJECT

public:
    explicit MusicSlider(QWidget *parent = nullptr);
    ~MusicSlider();


private:
    void initUi();

private:
    Ui::MusicSlider *ui;
};
