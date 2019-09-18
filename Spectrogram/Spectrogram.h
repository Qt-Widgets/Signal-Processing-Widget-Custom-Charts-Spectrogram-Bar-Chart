#ifndef SPECTROGRAM_H
#define SPECTROGRAM_H

#include <QGraphicsView>
#include "SpectrogramModel.h"

class XAxisItem;
class YAxisItem;
class CurveItem;
class Spectrogram : public QGraphicsView
{
public:
    Spectrogram();

private:
    QGraphicsScene* m_pSence;
    XAxisItem* m_pXAxis;
    YAxisItem* m_pYAxis;
    CurveItem* m_pCurve;
};

#endif // SPECTROGRAM_H
