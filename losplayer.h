#ifndef LOSPLAYER_H
#define LOSPLAYER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class LosPlayer;
}
QT_END_NAMESPACE

class LosPlayer : public QMainWindow
{
    Q_OBJECT

public:
    LosPlayer(QWidget *parent = nullptr);
    ~LosPlayer();

private:
    Ui::LosPlayer *ui;
};
#endif // LOSPLAYER_H
