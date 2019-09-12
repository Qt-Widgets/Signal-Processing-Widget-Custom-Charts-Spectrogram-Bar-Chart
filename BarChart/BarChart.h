#ifndef BARCHART_H
#define BARCHART_H

#include <QGraphicsView>
#include "BarItem.h"

#define HIGHEST_BAR_PROP (1.0 / 10)  //最高的柱距离图表顶端的距离占总高度的比例

class FrameItem : public QGraphicsItem
{
public:
    FrameItem(QRectF rect) { m_rect = rect; }
    void setRect(QRectF rect) { QMutexLocker locker(&m_mutex); m_rect = rect; }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * ,QWidget *) override
    {
        QMutexLocker locker(&m_mutex);
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
    QMutex m_mutex;
};

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
    void resizeEvent(QResizeEvent* event) override;

private:
    QGraphicsScene *m_pGraphicsScene;   //场景
    QVector<BarChartData> m_vecData;   //当前的柱状图数据
    QMutex m_mutex;
    QVector<BarItem*> m_vecBarItemList;    //场景中的图元列表
    FrameItem* m_pBackgroundItem; //背景框
    QRectF m_frameRect; //柱状图的范围
    //重新构建bar
    void rebuildBars(const QVector<BarChartData>& vecData);
};

#endif // BARCHART_H
