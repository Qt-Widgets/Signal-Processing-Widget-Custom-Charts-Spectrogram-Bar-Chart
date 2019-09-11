#include "BarChart.h"
#include <QDebug>

class ColorTheme
{
public:
    ColorTheme()
    {
        m_iCurrentColorIdx = 0;
        m_backgroundColor = QColor(50, 50, 50);
        m_vecThemeColor.append(QColor(65, 11, 94));
        m_vecThemeColor.append(QColor(216, 0, 89));
        m_vecThemeColor.append(QColor(241, 50, 58));
        m_vecThemeColor.append(QColor(249, 214, 90));
        m_vecThemeColor.append(QColor(241, 50, 58));
        m_vecThemeColor.append(QColor(216, 0, 89));
    }
    QColor getBackgroundColor() { return m_backgroundColor; }
    QColor getNextColor()
    {
        if (m_vecThemeColor.size() == 0)
        {   //主题中没有颜色, 直接返回黑色
            return Qt::black;
        }

        if (m_iCurrentColorIdx < m_vecThemeColor.size())
        {
            QColor color = m_vecThemeColor[m_iCurrentColorIdx];
            ++m_iCurrentColorIdx;
            return color;
        }
        else
        {
            m_iCurrentColorIdx = 1;
            return m_vecThemeColor[0];
        }
    }

private:
    int m_iThemeIdx;    //后备使用, 标记哪种主题
    int m_iCurrentColorIdx; //当前取到第几个颜色
    QColor m_backgroundColor;
    QVector<QColor> m_vecThemeColor;
};

class FrameItem : public QGraphicsItem
{
public:
    FrameItem(QRectF rect) { m_rect = rect; }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * ,QWidget *) override
    {
        painter->save();
        painter->setPen(Qt::red);
//        painter->setBrush(QBrush(Qt::red));
        painter->drawRect(m_rect);
        painter->restore();
    }
    QRectF boundingRect() const override
    {
        return m_rect;
    }
private:
    QRectF m_rect;
};

BarChart::BarChart()
{
    m_frameRect = QRectF(0, 0, this->width(), this->height());
    m_pGraphicsScene = new QGraphicsScene();
    this->setSceneRect(m_frameRect);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏横向滚动条
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏纵向滚动条
    this->setScene(m_pGraphicsScene);//添加场景

    //在场景中加入一个边框
    FrameItem* pFrameItem = new FrameItem(m_frameRect);
    m_pGraphicsScene->addItem(pFrameItem);
}

BarChart::~BarChart() {}

void BarChart::setData(const QVector<BarChartData>& vecData)
{
    if (vecData.size() <= 0)
    {   //输入数据无效
        return;
    }
    if (vecData.size() != m_vecBarItemList.size())
    {   //新输入的数据bar的数量发生了变更
        if (vecData.size() > m_vecBarItemList.size())
        {   //这次输入的比之前多, 增加新的bar
            while (m_vecBarItemList.size() < vecData.size())
            {
                BarItem* pBarItem = new BarItem();
                m_vecBarItemList.append(pBarItem);
                m_pGraphicsScene->addItem(pBarItem);
            }
        }
        else
        {   //这次输入的比之前少, 删除多余的bar
            while (m_vecBarItemList.size() > vecData.size())
            {
                BarItem* pBarItem = m_vecBarItemList.at(0);
                m_vecBarItemList.removeAt(0);
                m_pGraphicsScene->removeItem(pBarItem);
                delete pBarItem;
                pBarItem = nullptr;
            }
        }
    }
    if (vecData.size() != m_vecBarItemList.size())
    {   //发生异常, item数量仍然和输入不一致
        return;
    }
    //获取输入的数据的最大值
    double dMax = 0;
    foreach (BarChartData data, vecData)
    {
        if (dMax < data.dData)
        {
            dMax = data.dData;
        }
    }
    //计算缩放因子
    double dChartHeight = m_frameRect.height() * (1.0 - HIGHEST_BAR_PROP);
    double dFactor = dMax / dChartHeight;
    //计算柱状图水平偏移步长
    double dHOffset = m_frameRect.width() / static_cast<double>(vecData.size());
    //对每一个柱进行定位
    double dWalk = dHOffset / 2;
    ColorTheme theme;
    for (int i = 0; i < m_vecBarItemList.size(); ++i)
    {
        BarItem* pBarItem = m_vecBarItemList[i];
        pBarItem->setColor(theme.getNextColor(), Qt::white);
        pBarItem->setBarHeight(vecData[i].dData / dFactor);
        pBarItem->setBarWidth(static_cast<int>(dHOffset / 2));
        pBarItem->setLabel(vecData[i].strName);
        pBarItem->setPos(dWalk, m_frameRect.height() - 1); //height() - 1防止压底线
        dWalk += dHOffset;
    }
}

void BarChart::resizeEvent(QResizeEvent *event)
{
    qDebug() << "resize";
    m_frameRect = QRectF(0, 0, this->width(), this->height());
    this->setSceneRect(m_frameRect);
    //this->setV
}
