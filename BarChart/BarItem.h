#ifndef BARITEM_H
#define BARITEM_H

#include <QGraphicsItem>

class BarItem : public QGraphicsItem
{
public:
    BarItem();
    void setBarHeight(double dH) { m_barRect.setY(dH * (-1)); m_barRect.setHeight(dH); }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem * ,QWidget *) override;
    QRectF boundingRect() const override
    {
        return m_barRect;
    }

private:
    QRectF m_barRect;   //bar的矩形
};

#endif // BARITEM_H
