#ifndef SPECTROGRAMMODEL_H
#define SPECTROGRAMMODEL_H

#include <QObject>
#include <QVector>
#include <QMap>
#include <QColor>
#include <QRectF>

typedef struct _SLineData
{
    QVector<float> vecData;
    QColor lineColor;
}
SLineData;

class SpectrogramModel : public QObject
{
    Q_OBJECT
public:
    SpectrogramModel();
    //get/set数据范围
    QRectF getDataRange() { return m_dataRange; }
    void setDataRange(QRectF dataRange) { m_dataRange = dataRange; }
    void setXDataRange(qreal minX, qreal maxX);
    void setYDataRnage(qreal minY, qreal maxY);
    //get/set显示范围
    QRectF getShowRange() { return m_showRange; }
    void setShowRange(QRectF showRange) { m_showRange = showRange; }
    void setXShowRange(qreal minX, qreal maxX);
    void setYShowRange(qreal minY, qreal maxY);
    int setData(QString, SLineData);

private:
    QMap<QString, SLineData> m_mapLineData;
    QRectF m_dataRange; //存储数据范围
    QRectF m_showRange; //存储显示范围, 显示范围不可大于数据范围
};

#endif // SPECTROGRAMMODEL_H
