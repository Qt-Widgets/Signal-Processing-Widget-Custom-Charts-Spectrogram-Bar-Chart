#include "BarItem.h"
#include <QPainter>

BarItem::BarItem()
{
    m_barRect = QRectF(-10, 0, 20, 40);
}

void BarItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawRect(m_barRect);
}
