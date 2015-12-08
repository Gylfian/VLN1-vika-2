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
    void select(CScientist cSci, int index1, int index2);
    void select(Computer comp, int index1, int index2);
    void updateStatus(CScientist cSci);
    void updateStatus(Computer comp);
    void insert(CScientist cSci);
    void insert(Computer comp);
    void update(CScientist cSci);
    void update(Computer comp);
    vector<CScientist> getSciVector();
    vector<Computer> getComVector();
    void scientistToRestore();
    void computerToRestore();
    void relationToRestore();

private:
   vector<CScientist> sci;
   vector<Computer> com;
   vector<Relation> rel;
   QSqlDatabase database;
   bool fillVector(QSqlDatabase db, CScientist sci, QString command);
   bool fillVector(QSqlDatabase db, Computer com, QString command);
   bool fillVector(QSqlDatabase db, Relation rel, QString command);
   void makeQuery(CScientist& sci, QSqlQuery query);
   void makeQuery(Computer & comp, QSqlQuery query);
   void makeQuery(Relation & rel, QSqlQuery query);
   void sortQuerySci(string & sql,int index1, int index2);
   void sortQueryCom(string & sql,int index1, int index2);
   void setRelations(Computer comp, CScientist cSci);
};

#endif // DATA_H
