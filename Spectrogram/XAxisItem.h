#ifndef XAXISITEM_H
#define XAXISITEM_H

#include <QGraphicsItem>

class XAxisItem : public QGraphicsItem
{
public:
    XAxisItem();
    /**
     * @brief 设置描画范围(整个描画范围, 包括两边留余和单位)
     * @param drawingRect : 整个描画范围
     */
    void setDrawingRect(QRectF drawingRect) { m_drawingRect = drawingRect; }
    /**
     * @brief 设置描绘坐标轴时, 两边的留余
     * @param iLeftSpace : 左侧留余
     * @param iRightSpace : 右侧留余
     */
    void setDrawingSpace(int iLeftSpace, int iRightSpace) { m_iLeftSpace = iLeftSpace; m_iRightSpace = iRightSpace; }

    /**
     * @brief setUnit : 设置坐标轴单位
     * @param strUnit : 坐标轴单位
     * @param isShowLeft : 是否显示在左边
     */
    void setUnit(QString strUnit, bool bIsShowLeft = false) { m_strUnit = strUnit; m_bIsShowUnitLeft = bIsShowLeft; }

    /**
     * @brief 设置数据范围
     * @param dMin : 数据的最小值
     * @param dMax : 数据的最大值
     */
    void setDataRange(double dMin, double dMax);

    /**
     * @brief 设置显示范围
     * @param dMin : 显示的最小值
     * @param dMax : 显示的最大值
     */
    void setShowRange(double dMin, double dMax) { m_dShowMin = dMin; m_dShowMax = dMax; }

    /**
     * @brief 设置分割份数(将横轴分割为几份)
     * @param iSplitNum : 将显示的横轴分割为几份
     * @param iSplitNumInOnePiece : 将分割出来的份数再分割为几份
     */
    void setSplitNum(int iSplitNum, int iSplitNumInOnePiece = 2) { m_iSplitNum = iSplitNum; m_iSplitNumInOnePiece = iSplitNumInOnePiece; }
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * ,QWidget *) override;
    QRectF boundingRect() const override { return m_drawingRect; }

    /* 描画相关 */
    QRectF m_drawingRect;
    int m_iLeftSpace = 100;
    int m_iRightSpace = 100;
    QString m_strUnit = "Hz";
    bool m_bIsShowUnitLeft = false;
    double m_dDataMin = 0.0;
    double m_dDataMax = 1000000000; //1GHz
    double m_dShowMin = 0.0;
    double m_dShowMax = 1000.0;
    int m_iSplitNum = 5;
    int m_iSplitNumInOnePiece = 2;

    int m_iPrecision = 6;

    /* 颜色相关 */
    QColor m_backgroundColor = Qt::black;
    QColor m_lineColor = Qt::white;
    QColor m_dataStrColor = Qt::white;
    QColor m_unitColor = Qt::white;
};

#endif // XAXISITEM_H
