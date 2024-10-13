#include "src/TestWidget/mdiwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MDIWidget w;
    w.show();
    return a.exec();
}
