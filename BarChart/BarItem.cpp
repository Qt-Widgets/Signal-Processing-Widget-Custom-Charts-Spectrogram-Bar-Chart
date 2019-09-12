#include "BarItem.h"
#include <QPainter>
#include <QApplication>
#include <QDebug>

BarItem::BarItem()
{
    //计算当前系统默认字体的高度
    QFontMetrics metrics(qApp->font());
    QRect labelRect = metrics.boundingRect("test font");
    m_iFontH = labelRect.height();
    m_iFontW = 20;
    m_iBarH = 40;
    m_iBarW = 20;

    updateRect();
    m_barColor = QColor(0, 255, 0);
    m_labelColor = QColor(0, 0, 255);
    m_barFrameColor = QColor(100, 255, 100);
}

void BarItem::setLabel(QString strLabel)
{
    m_strLabel = strLabel;
    QFontMetrics metrics(qApp->font());
    QRect labelRect = metrics.boundingRect(strLabel);
    m_iFontW = labelRect.width();
    updateRect();
}

void BarItem::setBarHeight(double dH)
{
    m_iBarH = static_cast<int>(dH);
    updateRect();
}

void BarItem::setBarWidth(int iWidth)
{
    m_iBarW = static_cast<int>(iWidth);
    updateRect();
}

void BarItem::setColor(QColor barColor, QColor labelColor)
{
    QMutexLocker locker(&m_mutex);
    m_barColor = barColor;
    m_barFrameColor = barColor;
    m_labelColor = labelColor;
}

void BarItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QMutexLocker locker(&m_mutex);
    painter->setBrush(m_barColor);
    painter->setPen(m_barFrameColor);
    painter->drawRect(m_barRect);
    painter->setPen(m_labelColor);
    painter->drawText(m_labelRect, m_strLabel);
}

void BarItem::updateRect()
{
    QMutexLocker locker(&m_mutex);
    m_barRect = QRect((-1) * m_iBarW / 2, (-1) * (m_iBarH + m_iFontH), m_iBarW, m_iBarH);
    m_labelRect = QRect((-1) * m_iFontW / 2, (-1) * m_iFontH, m_iFontW, m_iFontH);
}
