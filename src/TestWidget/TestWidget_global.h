#ifndef TESTWIDGET_GLOBAL_H
#define TESTWIDGET_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TESTWIDGET_LIBRARY)
#define TESTWIDGET_EXPORT Q_DECL_EXPORT
#else
#define TESTWIDGET_EXPORT Q_DECL_IMPORT
#endif

#endif // TESTWIDGET_GLOBAL_H
