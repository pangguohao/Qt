#include "myscene.h"
#include "mypixmapitem.h"
#include <QMimeData>
#include <QString>
#include <QDebug>

MyScene::MyScene(QObject *parent) : QGraphicsScene(parent)
{
    dragOver = false;
}


void MyScene::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
//    QGraphicsScene::dragEnterEvent(event);
//    return;
    if (event->mimeData()->hasColor()) {
        event->setAccepted(true);
        dragOver = true;
        update();
    } else {
        event->setAccepted(false);
    }

}

void MyScene::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
//    QGraphicsScene::dragLeaveEvent(event);
//    return;
    Q_UNUSED(event);
    dragOver = false;
    MyPixmapItem *item;
    item = new MyPixmapItem;
    item->setColor(qvariant_cast<QColor>(event->mimeData()->colorData()));
    item->setPos(event->scenePos());
    item->update();
    qDebug() << QString("pos:x-%1 y-%2").arg(event->scenePos().x()).arg(event->scenePos().y());
    this->addItem(item);
    update();


}

//void MyScene::dropEvent(QGraphicsSceneDragDropEvent *event)
//{
//    dragOver = false;
//    if (event->mimeData()->hasColor())
//        color = qvariant_cast<QColor>(event->mimeData()->colorData());
//    update();
//}
