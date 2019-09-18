#include "Spectrogram.h"
#include "XAxisItem.h"

Spectrogram::Spectrogram()
{
    m_pSence = new QGraphicsScene();
    this->setScene(m_pSence);
    m_pXAxis = new XAxisItem;
    m_pXAxis->setDrawingRect(QRectF(0, 0, 500, 100));
    m_pSence->addItem(m_pXAxis);
}
