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
    painter->setRenderHint(QPainter::Antialiasing, true);

    QVector<QLine> vecLines;
    if (m_drawingRect.width() * 2 < m_vecData.size())
    {   //输入数据量很大(大于显示像素的两倍), 所有点用最小值和最大值的竖线表示
        float fMinInSameX = 0.0f;
        float fMaxInSameX = 0.0f;
        int iLastX = -1;
        for (int i = 0; i < m_vecData.size(); ++i)
        {
            int iCurX = transDataIndexToDrawingX(i, m_vecData.size());
            if (iCurX == iLastX)
            {   //点未变, 更新最大最小值
                float fValue = m_vecData.at(i);
                if (fValue > fMaxInSameX)
                {
                    fMaxInSameX = fValue;
                }
                else if (fValue < fMinInSameX)
                {
                    fMinInSameX = fValue;
                }
            }
            else
            {   //点变更
                //生成线段
                QLine tempLine;
                tempLine.setP1(QPoint(iLastX, transDataValueToDrawingY(fMaxInSameX)));
                tempLine.setP2(QPoint(iLastX, transDataValueToDrawingY(fMinInSameX)));
                vecLines.append(tempLine);
                //开始准备记录新的线段
                fMinInSameX = m_vecData.at(i);
                fMaxInSameX = fMinInSameX;
            }
            iLastX = iCurX;
        }
    }
    else
    {   //输入数据量较少, 逐点描画
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
    }
    painter->drawLines(vecLines);
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

int CurveItem::transDataIndexToDrawingX(int iIndex, int iTotal)
{
    if (0 == iTotal)
    {
        return 0;
    }
    double dIndexRatio = static_cast<double>(iIndex) / iTotal;
    return static_cast<int>(m_drawingRect.left() + dIndexRatio * m_drawingRect.width());
}

