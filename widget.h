#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "BarChart/BarChart.h"
#include "Spectrogram/Spectrogram.h"

namespace Ui {
class Widget;
}

class SpectrogramFeedThread;
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    BarChart* m_pBarChart;
    Spectrogram* m_pSpectrogram;
    SpectrogramFeedThread* m_pThread;

    QVector<float> createTestData();

};

#endif // WIDGET_H
