#ifndef XAXISITEM_H
#define XAXISITEM_H

#include <QGraphicsItem>

class XAxisItem : public QGraphicsItem
{
public:
    XAxisItem();
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * ,QWidget *) override;
    QRectF boundingRect() const override;
};

#endif // XAXISITEM_H
