#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_pBarChart = new BarChart;
    QVBoxLayout* pLayout = new QVBoxLayout;

    m_pSpectrogram = new Spectrogram;
    pLayout->addWidget(m_pSpectrogram);

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
