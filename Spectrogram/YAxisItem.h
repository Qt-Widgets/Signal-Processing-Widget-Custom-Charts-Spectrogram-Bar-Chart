#ifndef YAXISITEM_H
#define YAXISITEM_H

#include <QGraphicsItem>

class YAxisItem : public QGraphicsItem
{
public:
    YAxisItem();
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * ,QWidget *) override;
    QRectF boundingRect() const override;
};

#endif // YAXISITEM_H
