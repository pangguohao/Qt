#ifndef MYPIXMAPITEM_H
#define MYPIXMAPITEM_H

#include <QGraphicsObject>
#include <QGraphicsItem>
#include <QDrag>
#include <QGraphicsSceneMouseEvent>
#include <QMimeData>
#include <QPainter>
#include <QColor>
#include <QRandomGenerator>
#include <QWidget>


class MyPixmapItem : public QGraphicsObject
{
    Q_OBJECT
public:
    MyPixmapItem();

    void setColor(QColor _color){color = _color;}
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
signals:
    void clisked();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QColor color;
};

#endif // MYPIXMAPITEM_H
