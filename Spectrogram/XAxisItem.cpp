#include "XAxisItem.h"
#include <QPainter>

XAxisItem::XAxisItem()
{

}

void XAxisItem::setDataRange(double dMin, double dMax)
{
    m_dDataMin = dMin;
    m_dDataMax = dMax;
    static bool bIsFirstSetDataRange = true;
    if (bIsFirstSetDataRange)
    {
        setShowRange(dMin, dMax);
        bIsFirstSetDataRange = false;
    }
}

void XAxisItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    //描画背景颜色
    painter->setPen(m_backgroundColor);
    painter->setBrush(m_backgroundColor);
    painter->drawRect(m_drawingRect);

    //计算基本参数
    double dSectionRange = (m_drawingRect.width() - m_iLeftSpace - m_iRightSpace) / m_iSplitNum; //每个大标尺显示的范围
    double dSectionDataRange = (m_dShowMax - m_dShowMin) / m_iSplitNum; //一个大标尺范围跨越的数据范围
    double dStartPoint = m_drawingRect.left() + m_iLeftSpace;   //描画大标尺的起点
    double dBigLineLength = m_drawingRect.height() / 3;
    double dSmallLineLength = m_drawingRect.height() / 4;
    double dTextRectHeight = m_drawingRect.height() - dBigLineLength;   //标尺数值字符串的描画范围高度
    double dWalkX = dStartPoint;
    double dWalkNum = m_dShowMin;
    //画横轴
    painter->setPen(m_lineColor);
    painter->drawLine(static_cast<int>(dStartPoint),
                      static_cast<int>(m_drawingRect.top() + 1),
                      static_cast<int>(m_drawingRect.right() - m_iRightSpace),
                      static_cast<int>(m_drawingRect.top() + 1));
    //描画大标尺
    for (int i = 0; i < m_iSplitNum + 1; ++i)
    {
        painter->drawLine(static_cast<int>(dWalkX), static_cast<int>(m_drawingRect.top()),
                          static_cast<int>(dWalkX), static_cast<int>(m_drawingRect.top() + dBigLineLength));
        //描画小标尺
        if (m_iSplitNumInOnePiece > 1 && i != m_iSplitNum)
        {   //需要画小标尺, 并且不是最后一个大标尺(最后一个大标尺已经是最后, 不需要再画小标尺)
            double dSmallLineInterval = dSectionRange / m_iSplitNumInOnePiece;
            for (int j = 1; j < m_iSplitNumInOnePiece; ++j)
            {
                painter->drawLine(static_cast<int>(dWalkX + j * dSmallLineInterval),
                                  static_cast<int>(m_drawingRect.top()),
                                  static_cast<int>(dWalkX + j * dSmallLineInterval),
                                  static_cast<int>(m_drawingRect.top() + dSmallLineLength));
            }
        }
        //描画此大标尺处的刻度
        QRectF textRect = QRectF(0, 0, dSectionRange, dTextRectHeight);
        QPointF textRectCenter(dWalkX, m_drawingRect.top() + dBigLineLength + dTextRectHeight / 2);
        textRect.moveCenter(textRectCenter);
        QString strText = QString::number(dWalkNum, 'f', m_iPrecision);
        painter->drawText(textRect, Qt::AlignCenter, strText);

        dWalkX += dSectionRange;
        dWalkNum += dSectionDataRange;
    }

    painter->restore();
}

