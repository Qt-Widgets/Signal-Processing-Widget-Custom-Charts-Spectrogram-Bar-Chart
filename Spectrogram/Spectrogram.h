#ifndef SPECTROGRAM_H
#define SPECTROGRAM_H

#include <QGraphicsView>
#include "SpectrogramModel.h"

class Spectrogram : public QGraphicsView
{
public:
    Spectrogram();
    void setModel(SpectrogramModel* pModel);    //设置数据模型

private:
    QGraphicsScene* m_pSence;

};

#endif // SPECTROGRAM_H
