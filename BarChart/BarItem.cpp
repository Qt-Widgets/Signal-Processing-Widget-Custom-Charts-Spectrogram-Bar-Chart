#include "BarItem.h"
#include <QPainter>
#include <QApplication>
#include <QDebug>

BarItem::BarItem()
{
    m_barRect = QRectF(-10, -40, 20, 40);
    m_barColor = QColor(0, 255, 0);
    m_labelColor = QColor(0, 0, 255);
    m_barFrameColor = QColor(100, 255, 100);
}

void BarItem::setLabel(QString strLabel)
{
    m_strLabel = strLabel;
    QFontMetrics metrics(qApp->font());
    QRect labelRect = metrics.boundingRect(strLabel);
    labelRect.moveCenter(QPoint(0, labelRect.height()));
    m_labelRect = labelRect;
}

void BarItem::setBarHeight(double dH)
{
    m_barRect.setY(dH * (-1));
    m_barRect.setHeight(dH);
}

void BarItem::setColor(QColor barColor, QColor labelColor)
{
    m_barColor = barColor;
    m_barFrameColor = barColor;
    m_labelColor = labelColor;
}

void BarItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(m_barColor);
    painter->setPen(m_barFrameColor);
    painter->drawRect(m_barRect);
    painter->setPen(m_labelColor);
    painter->drawText(m_labelRect, m_strLabel);
}
