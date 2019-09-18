#include "XAxisItem.h"
#include <QPainter>

XAxisItem::XAxisItem()
{

}

void XAxisItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    //描画背景颜色
    painter->setBrush(m_backgroundColor);
    painter->drawRect(m_drawingRect);
    //描画大标尺
    double dSectionRange = m_drawingRect.width() / m_iSplitNum; //每个大标尺显示的范围
    double dStartPoint = m_drawingRect.left() + m_iLeftSpace;   //描画大标尺的起点
    double dBigLineLength = m_drawingRect.height() / 3;
    double dSmallLineLength = m_drawingRect.height() / 4;
    double dWalkX = dStartPoint;
    for (int i = 0; i < m_iSplitNum + 1; ++i)
    {
        painter->setPen(m_lineColor);
        painter->drawLine(static_cast<int>(dWalkX), static_cast<int>(m_drawingRect.top()),
                          static_cast<int>(dWalkX), static_cast<int>(m_drawingRect.top() + dBigLineLength));

        dWalkX += dSectionRange;
    }

    painter->restore();
}

