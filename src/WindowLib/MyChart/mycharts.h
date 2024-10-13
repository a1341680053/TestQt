#ifndef _MYCHARTS_H_
#define _MYCHARTS_H_

#include "MyChart_global.h"
#include <QWidget>

class QVBoxLayout;
class QChartView;
class QChart;

class MYCHART_EXPORT MyCharts : public QWidget 
{
     Q_OBJECT
private:
    QChartView*     mpChartView;
    QChart*         mpChart;
    QVBoxLayout*    mpVlayout;
public:
    MyCharts(QWidget* parent = nullptr);
    ~MyCharts();

    void init();
};


#endif