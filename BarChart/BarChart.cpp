#include "BarChart.h"

BarChart::BarChart()
{

}

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
    //获取输入的数据的最大值
    double dMax = 0;
    foreach (BarChartData data, vecData)
    {
        if (dMax < data.data)
        {
            dMax = data.data;
        }
    }
    //计算缩放因子
    int iChartHeight = this->height();
    double dFactor = dMax / iChartHeight;
    //对每一个柱进行定位
    foreach (BarItem* pBarItem, m_vecBarItemList)
    {
        ;//TODO
    }
}
