#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
#include <QtMath>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_pBarChart = new BarChart;
    QVBoxLayout* pLayout = new QVBoxLayout;
    pLayout->setMargin(0);
    m_pSpectrogram = new Spectrogram;
    m_pSpectrogram->setData(createTestData());
    pLayout->addWidget(m_pSpectrogram);
    this->setLayout(pLayout);

#if 0
    pLayout->addWidget(m_pBarChart);
    ui->groupBox_BarChart->setLayout(pLayout);
    QVector<BarChart::BarChartData> vecBarData;
    vecBarData.append(BarChart::BarChartData("First", 1));
    vecBarData.append(BarChart::BarChartData("Second", 2));
    vecBarData.append(BarChart::BarChartData("Third", 3));
    vecBarData.append(BarChart::BarChartData("Fourth", 4));
    vecBarData.append(BarChart::BarChartData("First", 7));
    vecBarData.append(BarChart::BarChartData("Second", 2));
    vecBarData.append(BarChart::BarChartData("Third", 5));
    vecBarData.append(BarChart::BarChartData("Fourth", 4));
    m_pBarChart->setData(vecBarData);
#endif
}

Widget::~Widget()
{
    delete ui;
}

QVector<float> Widget::createTestData()
{
    QVector<float> vecTestData;
    int iPointCnt = 100;
    float fMin = -170 + 1;
    float fMax = 0 - 1;
    for (int i = 0; i < iPointCnt; ++i)
    {
        float fStandardSin = static_cast<float>((qSin(2 * 3.14159265 * i / iPointCnt) + 1) / 2);
        vecTestData.append(fMin + (fMax - fMin) * fStandardSin);
    }
    return vecTestData;
}
