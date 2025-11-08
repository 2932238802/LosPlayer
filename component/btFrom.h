#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <style/style.h>
#include<qpropertyanimation.h>
#include<QSequentialAnimationGroup>
#include<QRect>
namespace Ui {
class BtFrom;
}

class BtFrom : public QWidget
{
    Q_OBJECT

public:
    explicit BtFrom(QWidget *parent = nullptr);
    void setSelfStyle(const QString&label,const QString&text);
    void setPageId(int page_id);
    void showLineBox(bool is_true);
    ~BtFrom();

protected:
    void mousePressEvent(QMouseEvent* event) override;

signals:
    void _pageId(int id);

private:
    QPropertyAnimation* line1Animation;
    QPropertyAnimation* line2Animation;
    QPropertyAnimation* line3Animation;
    QPropertyAnimation* line4Animation;
    Ui::BtFrom *ui;
    int pageId;
};


