#ifndef SPECTROGRAM_H
#define SPECTROGRAM_H

#include <QGraphicsView>
#include "SpectrogramModel.h"

class XAxisItem;
class YAxisItem;
class CurveItem;
class BackgroundItem;
class Spectrogram : public QGraphicsView
{
public:
    Spectrogram();
    void setData(const QVector<float>& vecData);

private:
    QGraphicsScene* m_pSence;
    XAxisItem* m_pXAxis;
    YAxisItem* m_pYAxis;
    CurveItem* m_pCurve;
    BackgroundItem* m_pBackground;
    //频谱图整体的窗体大小
    QRectF m_frameRect;
    //重描画事件
    void resizeEvent(QResizeEvent* event) override;

    //分割当前窗体为各个部分
    void carveFrame();
};

#endif // SPECTROGRAM_H
