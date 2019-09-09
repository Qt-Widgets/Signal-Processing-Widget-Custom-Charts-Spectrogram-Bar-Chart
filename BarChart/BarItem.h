#ifndef BARITEM_H
#define BARITEM_H

#include <QGraphicsItem>

class BarItem : public QGraphicsItem
{
public:
    BarItem();
    //设置bar的标签
    void setLabel(QString strLabel);
    //设置bar的宽高
    void setBarHeight(double dH);
    void setBarWidth(int iWidth);
    //设置颜色
    void setColor(QColor barColor, QColor labelColor);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem * ,QWidget *) override;
    QRectF boundingRect() const override
    {
        return m_barRect;
    }

private:
    QString m_strLabel;  //bar的标签
    QRectF m_barRect;   //bar的矩形
    QRect m_labelRect; //bar的标签矩形
    QColor m_labelColor;    //标签文字的颜色
    QColor m_barColor;      //bar本体颜色
    QColor m_barFrameColor; //bar边框颜色
};

#endif // BARITEM_H
