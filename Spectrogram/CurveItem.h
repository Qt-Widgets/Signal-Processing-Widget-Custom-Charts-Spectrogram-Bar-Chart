#ifndef CURVEITEM_H
#define CURVEITEM_H

#include <QGraphicsItem>

class CurveItem : public QGraphicsItem
{
public:
    CurveItem();
    void setData(const QVector<float>& vecData);
    void setLineColor(const QColor& color) { QMutexLocker locker(&m_mutex); m_lineColor = color; }
    void setDrawingRect(QRectF rect) { QMutexLocker locker(&m_mutex); m_drawingRect = rect; }
    void setShowMinMax(double dShowMin, double dShowMax);
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * ,QWidget *) override;
    QRectF boundingRect() const override;

    QMutex m_mutex;
    QRectF m_drawingRect;
    QVector<float> m_vecData;
    QColor m_lineColor;

    double m_dShowMin = -170.0;
    double m_dShowMax = 0.0;
    //将一个数值转换为显示的纵轴坐标值
    int transDataValueToDrawingY(float fDataValue);
    //将数据位置转换为显示的横轴坐标值
    int transDataIndexToDrawingX(int iIndex, int iTotal);
};

#endif // CURVEITEM_H
