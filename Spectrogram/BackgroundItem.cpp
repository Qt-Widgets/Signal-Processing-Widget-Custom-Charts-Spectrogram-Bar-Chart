#include "BackgroundItem.h"
#include <QPainter>

BackgroundItem::BackgroundItem()
{
    m_backgroundColor = QColor(0, 0, 0);
    m_splitLineColor = QColor(255, 255, 255);
}

void BackgroundItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    //描画背景颜色
    painter->setPen(m_backgroundColor);
    painter->setBrush(m_backgroundColor);
    painter->drawRect(m_drawingRect);
    //描画分割线
    QPen pen;
    pen.setColor(m_splitLineColor);
    pen.setStyle(Qt::DashDotDotLine);
    painter->setPen(pen);
    //描画水平分割线
    double dSpan = m_drawingRect.width() / m_iXSplitNum;
    if (m_iXSplitNum > 2)
    {
        for (int i = 1; i < m_iXSplitNum; ++i)
        {
            QPointF startPoint(m_drawingRect.left() + i * dSpan, m_drawingRect.top());
            QPointF endPoint(m_drawingRect.left() + i * dSpan, m_drawingRect.bottom());
            painter->drawLine(startPoint, endPoint);
        }
    }
    //描画垂直分割线
    dSpan = m_drawingRect.height() / m_iYSplitNum;
    if (m_iYSplitNum > 2)
    {
        for (int i = 1; i < m_iYSplitNum; ++i)
        {
            QPointF startPoint(m_drawingRect.left(), m_drawingRect.top() + i * dSpan);
            QPointF endPoint(m_drawingRect.right(), m_drawingRect.top() + i * dSpan);
            painter->drawLine(startPoint, endPoint);
        }
    }

    painter->restore();
}
