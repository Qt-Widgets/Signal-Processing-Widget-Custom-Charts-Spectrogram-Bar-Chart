#include "Spectrogram.h"
#include "XAxisItem.h"
#include "BackgroundItem.h"

Spectrogram::Spectrogram()
{
    m_pSence = new QGraphicsScene();
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏横向滚动条
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏纵向滚动条

    this->setScene(m_pSence);
    m_pXAxis = new XAxisItem;
    m_pSence->addItem(m_pXAxis);
    m_pBackground = new BackgroundItem;
    m_pSence->addItem(m_pBackground);
}

void Spectrogram::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)

    m_frameRect = QRectF(0, 0, this->width(), this->height());
    this->setSceneRect(m_frameRect);
    carveFrame();
    update();
}

void Spectrogram::carveFrame()
{
    int iXAxisHeight = 75;
    int iYAxisWidth = 75;
    QRectF backgroundFrame = QRectF(m_frameRect.left() + iYAxisWidth,
                                    0,
                                    m_frameRect.width() - 2 * iYAxisWidth,
                                    m_frameRect.height() - iXAxisHeight);
    m_pBackground->setDrawingRect(backgroundFrame);
    QRectF xAxisFrame = QRectF(m_frameRect.left(),
                              m_frameRect.top() + m_frameRect.height() - iXAxisHeight,
                              m_frameRect.width(),
                              iXAxisHeight);
    m_pXAxis->setDrawingRect(xAxisFrame);
}
