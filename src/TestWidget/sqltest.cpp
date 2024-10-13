#include "sqltest.h"

#include <QSqlDatabase>
#include <QApplication>
#include <QSqlQuery>
#include <QSettings>
#include <QDebug>
#include <iostream>

QSqlDatabase db;

SqlTest::SqlTest()
{
    
}

SqlTest::~SqlTest()
{
}

bool SqlTest::initSql(LINK_TYPE type)
{
    QSettings sett(QApplication::applicationDirPath()+"/../Data/sql.ini",QSettings::IniFormat);
    if (LINK_TYPE::_ODBC == type)
    {
        db = QSqlDatabase::addDatabase("QODBC");
        sett.beginGroup("SQL_ODBC");
        db.setPort(sett.value("PORT").toInt());
        db.setHostName(sett.value("IP").toString());
        db.setDatabaseName(sett.value("DSN").toString());
        db.setUserName(sett.value("UID").toString());
        db.setPassword(sett.value("PWD").toString());
        
    }
    else if (LINK_TYPE::_QDM == type)
    {
        return false;
    }
    else
    {
        return false;
    }
    if (db.open())
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}
