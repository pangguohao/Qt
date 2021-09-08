#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsSceneDragDropEvent>

class MyScene : public QGraphicsScene
{

private:
    bool dragOver;
public:
    MyScene(QObject *object);

    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;
    //void dragMoveEvent(QGraphicsSceneDragDropEvent *event) override;
};

#endif // MYSCENE_H
