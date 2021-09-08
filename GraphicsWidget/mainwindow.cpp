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
    m_item->setFlag(QGraphicsItem::ItemIsSelectable, true);//����ѡ��
    m_scene->addItem(m_item);
    ui->graphicsView->setScene(m_scene);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
//    ui->graphicsView->setBackgroundBrush(QColor(230, 200, 167));
//    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
//    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->graphicsView->setAcceptDrops(true);
    qDebug() << "MainWindow::" << "init";



    QTimeLine *timeline = new QTimeLine(5000); //������ʱ�������
    timeline->setFrameRange(0,5);//5 ֡
    timeline->setDirection(QTimeLine::Forward);//���Ӷ�����ǰ����ʱ��ʱ������Ϊ0
    connect(timeline,SIGNAL(frameChanged(int)),this,SLOT(frameSlot(int)));//ÿһ֡�ı仯������һ���ź�
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
         // ִ�����Ĵ�
        qDebug()<<"frame is"<<frame<<endl;
        if (frame == 5)
        {
            qDebug()<<"time over later animationFinish";
        }

}
// �����������ʱ�ᷢ��һ��finish�ź�
void MainWindow::animationFinish()
{
    QPropertyAnimation *animation;
    animation = new QPropertyAnimation(m_item,"x",this);

    animation->setDuration(3000);
    animation->setStartValue(20);
    animation->setEndValue(1000);

    animation->start();
}

