#ifndef MDIWIDGET_H
#define MDIWIDGET_H

#include <QMainWindow>
#include "TestWidget_global.h"
namespace Ui {
class MDIWidget;
}

class MyCharts;

class TESTWIDGET_EXPORT MDIWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit MDIWidget(QWidget *parent = nullptr);
    ~MDIWidget();
    
public slots:
    void slotActionOpenCharts();
private:
    Ui::MDIWidget *ui;

    MyCharts* mpCharts;
};

#endif // MDIWIDGET_H
