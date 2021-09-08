#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myscene.h"
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QDebug>
#include <QTimeLine>
#include <QPropertyAnimation>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_scene = new MyScene(this);
    //QPixmap pixMap = QPixmap(50, 50);
    //pixMap.fill(Qt::red);
    m_item = new MyPixmapItem;
    m_item->setFlag(QGraphicsItem::ItemIsMovable, true);
    m_item->setFlag(QGraphicsItem::ItemIsSelectable, true);//可以选中
    m_scene->addItem(m_item);
    ui->graphicsView->setScene(m_scene);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
//    ui->graphicsView->setBackgroundBrush(QColor(230, 200, 167));
//    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
//    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->graphicsView->setAcceptDrops(true);
    qDebug() << "MainWindow::" << "init";



    QTimeLine *timeline = new QTimeLine(5000); //动画的时间控制线
    timeline->setFrameRange(0,5);//5 帧
    timeline->setDirection(QTimeLine::Forward);//增加动画当前进行时间时，返回为0
    connect(timeline,SIGNAL(frameChanged(int)),this,SLOT(frameSlot(int)));//每一帧的变化将发出一个信号
    //timeline->start();
    connect(timeline,SIGNAL(finished()),this,SLOT(animationFinish()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::signalsSlotsCon()
{
}

void MainWindow::frameSlot(int frame)
{
         // 执行了四次
        qDebug()<<"frame is"<<frame<<endl;
        if (frame == 5)
        {
            qDebug()<<"time over later animationFinish";
        }

}
// 将动画线完成时会发出一个finish信号
void MainWindow::animationFinish()
{
    QPropertyAnimation *animation;
    animation = new QPropertyAnimation(m_item,"x",this);

    animation->setDuration(3000);
    animation->setStartValue(20);
    animation->setEndValue(1000);

    animation->start();
}

