#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "BarChart/BarChart.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    BarChart* m_pBarChart;
};

#endif // WIDGET_H
