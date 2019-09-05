#ifndef BARCHART_H
#define BARCHART_H

#include <QGraphicsView>
#include "BarItem.h"

class BarChart : public QGraphicsView
{
public:
    typedef struct _BarChartData
    {
        QString strName;    //该数据的名称
        double data;        //数值大小
    }
    BarChartData;
public:
    BarChart();
    virtual ~BarChart() {}
    void setData(const QVector<BarChartData>& vecData);

private:
    QGraphicsScene *m_pGraphicsScene;   //场景
    QVector<BarItem*> m_vecBarItemList;    //场景中的图元列表
};

#endif // BARCHART_H
