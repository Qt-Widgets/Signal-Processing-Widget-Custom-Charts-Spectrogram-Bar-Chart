#ifndef BACKGROUNDITEM_H
#define BACKGROUNDITEM_H

#include <QGraphicsItem>

class BackgroundItem : public QGraphicsItem
{
public:
    BackgroundItem();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * ,QWidget *) override;
    QRectF boundingRect() const override { return m_drawingRect; }
    void setDrawingRect(QRectF rect) { m_drawingRect = rect; }

private:
    QRectF m_drawingRect;
    QColor m_backgroundColor;
    QColor m_splitLineColor;
    int m_iXSplitNum = 5;       //将屏幕横向分割为几份
    int m_iYSplitNum = 4;       //将屏幕纵向分割为几份
};

#endif // BACKGROUNDITEM_H
