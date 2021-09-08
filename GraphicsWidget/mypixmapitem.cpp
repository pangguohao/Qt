#include "mypixmapitem.h"
#include <QApplication>
#include <QPixmap>
#include <QBitmap>
#include <QDebug>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QState>
#include <QStateMachine>
#include <QSignalTransition>

MyPixmapItem::MyPixmapItem():color(QRandomGenerator::global()->bounded(256), QRandomGenerator::global()->bounded(256), QRandomGenerator::global()->bounded(256))
{
    QStateMachine *pMachine = new QStateMachine(this);
    QState *state1 = new QState(pMachine);
    QState *state2 = new QState(pMachine);

    state1->assignProperty( this, "x", 400 );
    state2->assignProperty( this, "x", 0 );

    QSignalTransition *trans1 = state1->addTransition(this, &MyPixmapItem::clisked,state2);
    QSignalTransition *trans2 = state2->addTransition(this, &MyPixmapItem::clisked,state1);

    QPropertyAnimation *animation = new QPropertyAnimation(this, "x");
    animation->setDuration(5000);
    trans1->addAnimation(animation);
    trans2->addAnimation(animation);
    animation->setEasingCurve(QEasingCurve::Linear);

    pMachine->setInitialState(state1);
    pMachine->start();

    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
    qDebug() << "MyPixmapItem::" << "init";
}

void MyPixmapItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkGray);
    painter->drawEllipse(-12, -12, 30, 30);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(QBrush(color));
    painter->drawEllipse(-15, -15, 30, 30);
}

//! [3]
void MyPixmapItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{


    qDebug() << "MyPixmapItem::" << "mousePressEvent";

    emit clisked();
//    QGraphicsItem::mousePressEvent(event);
//    return;
    setCursor(Qt::ClosedHandCursor);
}
//! [3]

//! [5]
void MyPixmapItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
//    QGraphicsItem::mouseMoveEvent(event);
//    return;
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton))
        .length() < QApplication::startDragDistance()) {
        return;
    }

    qDebug() << "MyPixmapItem::" << "mouseMoveEvent";
    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;
    drag->setMimeData(mime);
//! [5]

//! [6]
    {
        mime->setColorData(color);
        mime->setText(QString("#%1%2%3")
                      .arg(color.red(), 2, 16, QLatin1Char('0'))
                      .arg(color.green(), 2, 16, QLatin1Char('0'))
                      .arg(color.blue(), 2, 16, QLatin1Char('0')));

        QPixmap pixmap(34, 34);
        pixmap.fill(Qt::red);

        QPainter painter(&pixmap);
        painter.translate(15, 15);
        painter.setRenderHint(QPainter::Antialiasing);
        paint(&painter, nullptr, nullptr);
        painter.end();

        pixmap.setMask(pixmap.createHeuristicMask());

        drag->setPixmap(pixmap);
        drag->setHotSpot(QPoint(15, 20));
    }
////! [7]

////! [8]
    drag->exec();
    setCursor(Qt::OpenHandCursor);
}
//! [8]

//! [4]
void MyPixmapItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    return;

    QPropertyAnimation *animation1 = new QPropertyAnimation(this,"x");
    animation1->setDuration(10000);  //设置动画完成的时间长度
    animation1->setKeyValueAt(0, 20);
    animation1->setKeyValueAt(4000, 25);
    animation1->setKeyValueAt(8000, 300);
    animation1->setKeyValueAt(10000, 600);
    animation1->setEasingCurve(QEasingCurve::OutElastic);
//    animation1->setDuration(1000);  //设置动画完成的时间长度
//    animation1->setStartValue(20); //设置动画的开始值
    animation1->setEndValue(600); //设置动画的结束值

    QPropertyAnimation *animation2 = new QPropertyAnimation(this,"x");
    animation2->setDuration(1000);  //设置动画完成的时间长度
    animation2->setStartValue(600); //设置动画的开始值
    animation2->setEndValue(20); //设置动画的结束值

    QPropertyAnimation *animation3 = new QPropertyAnimation(this,"y");
    animation3->setDuration(1000);  //设置动画完成的时间长度
    animation3->setStartValue(20); //设置动画的开始值
    animation3->setEndValue(600); //设置动画的结束值

    QPropertyAnimation *animation4 = new QPropertyAnimation(this,"y");
    animation4->setDuration(1000);  //设置动画完成的时间长度
    animation4->setStartValue(600); //设置动画的开始值
    animation4->setEndValue(20); //设置动画的结束值

    QPropertyAnimation *animation5 = new QPropertyAnimation(this,"z");
    animation5->setDuration(1000);  //设置动画完成的时间长度
    animation5->setStartValue(20); //设置动画的开始值
    animation5->setEndValue(600); //设置动画的结束值

    QPropertyAnimation *animation6 = new QPropertyAnimation(this,"z");
    animation6->setDuration(1000);  //设置动画完成的时间长度
    animation6->setStartValue(600); //设置动画的开始值
    animation6->setEndValue(20); //设置动画的结束值

    QSequentialAnimationGroup*group = new QSequentialAnimationGroup;
    group->addAnimation(animation1);
    group->addAnimation(animation2);
    group->addAnimation(animation3);
    group->addAnimation(animation4);
    group->addAnimation(animation5);
    group->addAnimation(animation6);
    group->setLoopCount(-1); //-1表示不断循环动画
    group->start();
    qDebug() << "MyPixmapItem::" << "mouseReleaseEvent";
    setCursor(Qt::OpenHandCursor);
}

QRectF MyPixmapItem::boundingRect() const
{
    return QRectF(-15.5, -15.5, 34, 34);
}
