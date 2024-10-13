#include "mycharts.h"
#include <QtCharts>
#include <QVBoxLayout>

MyCharts::MyCharts(QWidget *parent)
    :QWidget(parent)
{
    init();
}

MyCharts::~MyCharts()
{
}

void MyCharts::init()
{
    mpVlayout = new QVBoxLayout(this);
    mpChartView = new QChartView(this);
    mpChart = new QChart();
    
    mpChart->setTitle("简单的函数曲线");
    mpChartView->setChart(mpChart);
    mpVlayout->addWidget(mpChartView);
    this->setLayout(mpVlayout);

    //创建曲线序列
    QLineSeries* series0 = new QLineSeries();
    QLineSeries* series1 = new QLineSeries();
    series0->setName("Sin曲线");
    series1->setName("Cos曲线");
    mpChart->addSeries(series0);
    mpChart->addSeries(series1);
    //序列添加数值
    qreal t=0,y1,y2,intv=0.1;
    int cnt = 100;
    for (size_t i = 0; i < cnt; ++i)
    {
        y1 = qSin(t);
        series0->append(t,y1);
        y2 = qSin(t+20);
        series1->append(t,y2);
        t += intv;
    }

    //创建坐标轴
    QValueAxis* axisX = new QValueAxis;
    axisX->setRange(0,10);
    axisX->setTitleText("时间(秒)");
    QValueAxis* axisY = new QValueAxis;
    axisY->setRange(-2,2);
    axisY->setTitleText("数值");

    mpChart->addAxis(axisX,Qt::AlignBottom);
    mpChart->addAxis(axisY,Qt::AlignLeft);
    series0->attachAxis(axisX);
    series0->attachAxis(axisY);
    series1->attachAxis(axisX);
    series1->attachAxis(axisY);
}
