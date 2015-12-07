#ifndef DATA_H
#define DATA_H
#include <fstream>
#include <vector>
#include "computerscientist.h"
#include "computer.h"
#include "relation.h"
#include <iostream>
#include <string>
#include <QVariant>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
using namespace std;

class Data
{
public:

    Data();
    QSqlDatabase getDatabase();
    void setDatabase();
    bool editDatabase(QSqlDatabase db, const QString& command);
    bool fillVector(QSqlDatabase db, CScientist sci, QString command);
    bool fillVector(QSqlDatabase db, Computer com, QString command);
    bool fillVector(QSqlDatabase db, Relation rel, QString command);
    void makeQuery(CScientist& sci, QSqlQuery query);
    void makeQuery(Computer & comp, QSqlQuery query);
    void makeQuery(Relation & rel, QSqlQuery query);
    void select(CScientist cSci);
    void select(Computer comp);
    void deleteEntry(CScientist cSci);
    void deleteEntry(Computer comp);
    void insert(CScientist cSci);
    void insert(Computer comp);
    void update(CScientist cSci);
    void update(Computer comp);
    bool executeQuery(QSqlQuery query, QString command);
    void setRelations(Computer comp, CScientist cSci);

private:
   vector<CScientist> sci;
   vector<Computer> com;
   vector<Relation> rel;
   QSqlDatabase database;


};

#endif // DATA_H
