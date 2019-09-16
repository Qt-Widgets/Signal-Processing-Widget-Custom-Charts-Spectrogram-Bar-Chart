#ifndef CURVEITEM_H
#define CURVEITEM_H

#include <QGraphicsItem>

class CurveItem : public QGraphicsItem
{
public:
    CurveItem();
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * ,QWidget *) override;
    QRectF boundingRect() const override;
};

#endif // CURVEITEM_H
