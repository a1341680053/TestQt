#include "mdiwidget.h"
#include "ui_mdiwidget.h"
#include "sqltest.h"
#include "MyChart/mycharts.h"

#include <QMdiSubWindow>
#include <QSqlDatabase>
#include <QSqlQuery>




MDIWidget::MDIWidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MDIWidget)
    , mpCharts(nullptr)
{
    ui->setupUi(this);

    SqlTest sq;
    sq.initSql(SqlTest::_ODBC);
    connect(ui->actionOpenCharts,&QAction::triggered,this,&MDIWidget::slotActionOpenCharts);
}

MDIWidget::~MDIWidget()
{
    delete ui;
}

void MDIWidget::slotActionOpenCharts()
{
    if (nullptr == mpCharts)
    {
        mpCharts = new MyCharts(ui->mdiArea);
        QMdiSubWindow* subWd = ui->mdiArea->addSubWindow(mpCharts);
        subWd->setWindowTitle("表格");
        mpCharts->show();
    }
    
}