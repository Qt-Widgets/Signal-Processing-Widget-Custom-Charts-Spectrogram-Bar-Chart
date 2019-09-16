#ifndef SPECTROGRAM_H
#define SPECTROGRAM_H

#include <QGraphicsView>

class Spectrogram : public QGraphicsView
{
public:
    Spectrogram();

private:
    QGraphicsScene* m_pSence;

};

#endif // SPECTROGRAM_H
