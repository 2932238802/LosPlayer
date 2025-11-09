#include "volumeTool.h"
#include "ui_volumetool.h"

VolumeTool::VolumeTool(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VolumeTool)
{
    ui->setupUi(this);
    initUi();
}

VolumeTool::~VolumeTool()
{
    delete ui;
}

void VolumeTool::initUi()
{
    LOG() << "VolumeTool::initUi()";
    setStyleSheet(VOLUME_TOOL);
    setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);

    QGraphicsDropShadowEffect * shadowEffect = new QGraphicsDropShadowEffect(this);

    shadowEffect->setBlurRadius(10);
    shadowEffect->setOffset(0,0);
    shadowEffect->setColor("#646464");

    ui->volumeBox->setGraphicsEffect(shadowEffect);

    ui->slienceBtn->setText("未静音");

    ui->volumeValue->setText("20");

    QRect rect = ui->inLine->geometry();
    int y = rect.y()+rect.height()*0.8;
    ui->outLine->setGeometry(rect.x(),y,rect.width(),rect.height()*0.2);
    ui->sliderBtn->move(ui->sliderBtn->pos().x(),y - ui->sliderBtn->geometry().height()/2);
}


////////////////////////////
/// \brief VolumeTool::paintEvent
/// \param event
///
void VolumeTool::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setPen(Qt::NoPen);

    painter.setBrush(QBrush(Qt::white));

    // 绘制三角形
    QPoint buttonPosInVolumeTool = ui->slienceBtn->mapTo(this, QPoint(0, 0));
    int x = buttonPosInVolumeTool.x();
    int y = buttonPosInVolumeTool.y();
    int height = ui->slienceBtn->height();
    int width = ui->slienceBtn->width();

    QPoint point1(x + 10, y + height + 10);
    QPoint point2(x + width - 10, y + height + 10);
    QPoint point3(x + width / 2, y + height + 30);

    QPolygon polygon;
    polygon << point1 << point2 << point3;
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(220,220,220));
    painter.drawPolygon(polygon);

}
////////////////////////////













