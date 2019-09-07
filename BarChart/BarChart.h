#ifndef BARCHART_H
#define BARCHART_H

#include <QGraphicsView>
#include "BarItem.h"

class BarChart : public QGraphicsView
{
public:
    typedef struct _BarChartData
    {
        _BarChartData(QString name = "", double data = 0) { strName = name; dData = data; }
        QString strName;    //该数据的名称
        double dData;        //数值大小
    }
    BarChartData;
public:
    BarChart();
    virtual ~BarChart();
    void setData(const QVector<BarChartData>& vecData);

private:
    QGraphicsScene *m_pGraphicsScene;   //场景
    QVector<BarItem*> m_vecBarItemList;    //场景中的图元列表
    QRectF m_frameRect; //柱状图的范围
};

#endif // BARCHART_H
