#ifndef _SQLTEST_H_
#define _SQLTEST_H_

class SqlTest
{
public:
    enum LINK_TYPE
    {
        _ODBC,
        _QDM
    };
private:
    
public:
    SqlTest(/* args */);
    ~SqlTest();

    bool initSql(LINK_TYPE type);
};

#endif