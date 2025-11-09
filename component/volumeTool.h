#pragma once
#include "style/style.h"
#include "common/myLog.h"
#include <QWidget>
#include<QGraphicsDropShadowEffect>
#include <QPainter>

namespace Ui {
class VolumeTool;
}

class VolumeTool : public QWidget
{
    Q_OBJECT

public:
    explicit VolumeTool(QWidget *parent = nullptr);
    ~VolumeTool();

private:
    void initUi();
    void paintEvent(QPaintEvent* event) override;


private:
    Ui::VolumeTool *ui;
};


