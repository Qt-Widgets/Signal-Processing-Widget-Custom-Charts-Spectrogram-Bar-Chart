#ifndef BARITEM_H
#define BARITEM_H

#include <QGraphicsItem>

class BarItem : public QGraphicsItem
{
public:
    BarItem();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem * ,QWidget *) override;
    QRectF boundingRect() const override
    {
        return m_barRect;
    }
private:
    QRectF m_barRect;   //bar的矩形
};

#endif // BARITEM_H
