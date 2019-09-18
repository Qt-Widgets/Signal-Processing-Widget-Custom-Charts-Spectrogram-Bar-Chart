#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
#include <QtMath>
#include <QThread>

class CreateTestData
{
public:
    static QVector<float> createTestData()
    {
        static int iCount = 0;
        int iVelocity = 100;    //多少次走一个周期(2PI)
        double dPhaseOffset = 2 * M_PI * iCount / iVelocity;  //相位偏移
        QVector<float> vecTestData;
        int iPointCnt = 100;
        float fMin = -170 + 1;
        float fMax = 0 - 1;
        for (int i = 0; i < iPointCnt; ++i)
        {
            float fStandardSin = static_cast<float>((qSin(dPhaseOffset + 2 * 3.14159265 * i / iPointCnt) + 1) / 2);
            vecTestData.append(fMin + (fMax - fMin) * fStandardSin);
        }
        ++iCount;
        return vecTestData;
    }
};

class SpectrogramFeedThread : public QThread
{
public:
    void setSpectrogram(Spectrogram* pSpec) { m_pSpec = pSpec; }
    void stop() { m_bIsRunning = false; }
    virtual void run() override
    {
        m_bIsRunning = true;
        while (m_bIsRunning)
        {
            if (nullptr != m_pSpec)
            {
                m_pSpec->setData(CreateTestData::createTestData());
            }
            msleep(50);
        }
    }
private:
    Spectrogram* m_pSpec;
    bool m_bIsRunning;
};

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_pBarChart = new BarChart;
    QVBoxLayout* pLayout = new QVBoxLayout;
    pLayout->setMargin(0);
    m_pSpectrogram = new Spectrogram;
    pLayout->addWidget(m_pSpectrogram);
    m_pThread = new SpectrogramFeedThread;
    m_pThread->setSpectrogram(m_pSpectrogram);
    m_pThread->start();
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
    m_pThread->stop();
    m_pThread->wait();
    delete m_pThread;
    m_pThread = nullptr;
    delete ui;
}


