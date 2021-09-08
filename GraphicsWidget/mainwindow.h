#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "mypixmapitem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *m_scene;
    MyPixmapItem *m_item;
    void signalsSlotsCon();

signals:

private slots:
    void frameSlot(int frame);
    void animationFinish();
};
#endif // MAINWINDOW_H
