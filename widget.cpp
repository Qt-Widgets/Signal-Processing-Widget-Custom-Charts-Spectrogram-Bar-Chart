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
    pLayout->addWidget(m_pBarChart);
    ui->groupBox_BarChart->setLayout(pLayout);
    QVector<BarChart::BarChartData> vecBarData;
    vecBarData.append(BarChart::BarChartData("First", 1));
    vecBarData.append(BarChart::BarChartData("Second", 2));
    vecBarData.append(BarChart::BarChartData("Third", 3));
    m_pBarChart->setData(vecBarData);
}

Widget::~Widget()
{
    delete ui;
}
