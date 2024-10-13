#ifndef _MYCHART_GLOBAL_H_
#define _MYCHART_GLOBAL_H_

#include <QtCore/qglobal.h>

#if defined(MYCHART_LIBRARY)
#define MYCHART_EXPORT Q_DECL_EXPORT
#else
#define MYCHART_EXPORT Q_DECL_IMPORT
#endif

#endif