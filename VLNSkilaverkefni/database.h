#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <string>
#include <QVariant>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
using namespace std;


class database
{
public:
    database();
    void addQuery();
    void addDatabase();
};

#endif // DATABASE_H
