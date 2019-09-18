#include "CurveItem.h"
#include <QPainter>

CurveItem::CurveItem()
{
    m_lineColor = Qt::red;
}

void CurveItem::setData(const QVector<float> &vecData)
{
    QMutexLocker locker(&m_mutex);
    m_vecData = vecData;
}

void CurveItem::setShowMinMax(double dShowMin, double dShowMax)
{
    QMutexLocker locker(&m_mutex);
    m_dShowMin = dShowMin;
    m_dShowMax = dShowMax;
}

void CurveItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QMutexLocker locker(&m_mutex);
    painter->save();
    painter->setPen(m_lineColor);
    if (m_drawingRect.width() * 2 < m_vecData.size())
    {   //输入数据量很大(大于显示像素的两倍), 所有点用最小值和最大值的竖线表示
        painter->drawLine(m_drawingRect.topLeft(), m_drawingRect.bottomRight());
    }
    else
    {   //输入数据量较少, 逐点描画
        QVector<QLine> vecLines;
        double dPointXInterval = m_drawingRect.width() / (m_vecData.size() - 1);
        QLine tempLine;
        //第一个点先计算出来
        if (m_vecData.size() > 0)
        {
            tempLine.setP1(QPoint(static_cast<int>(m_drawingRect.left()),
                                  transDataValueToDrawingY(m_vecData.at(0))));
            tempLine.setP2(QPoint(static_cast<int>(m_drawingRect.left() + dPointXInterval),
                                  transDataValueToDrawingY(m_vecData.at(1))));
            vecLines.append(tempLine);
        }
        //之后每一条线的第一个点都是上次的第二个点
        for (int i = 1; i < m_vecData.size() - 1; ++i)
        {
            tempLine.setP1(tempLine.p2());
            tempLine.setP2(QPoint(static_cast<int>(m_drawingRect.left() + (i + 1) * dPointXInterval),
                                  transDataValueToDrawingY(m_vecData.at(i + 1))));
            vecLines.append(tempLine);
        }
        painter->drawLines(vecLines);
    }
    painter->restore();
}

QRectF CurveItem::boundingRect() const
{
    return QRectF();
}

int CurveItem::transDataValueToDrawingY(float fDataValue)
{
    double dPixelPerValue = m_drawingRect.height() / (m_dShowMax - m_dShowMin);
    //转化为像素点的高度
    double dPixelHeight = (static_cast<double>(fDataValue) - m_dShowMin) * dPixelPerValue;
    double dPosInDrawingArea = m_drawingRect.height() - dPixelHeight;
    return static_cast<int>(dPosInDrawingArea);
}

