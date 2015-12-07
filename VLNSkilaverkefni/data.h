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
    bool fillVector(QSqlDatabase db, Relation rele, QString command);
    void makeQuery(CScientist& sci, QSqlQuery query);
    void makeQuery(Computer & comp, QSqlQuery query);
    void makeQuery(Relation & comp, QSqlQuery query);
    void select(CScientist cSci, int index1, int index2);
    void select(Computer comp, int index1, int index2);
    void deleteEntry(CScientist cSci);
    void deleteEntry(Computer comp);
    void insert(CScientist cSci);
    void insert(Computer comp);
    void update(CScientist cSci);
    void update(Computer comp);
    void sortQuerySci(string & sql,int index1, int index2);
    void sortQueryCom(string & sql,int index1, int index2);
    bool executeQuery(QSqlQuery query, QString command);
    void setRelations(Computer comp, CScientist cSci);
    vector<CScientist> getSciVector();
    vector<Computer> getComVector();
private:
   vector<CScientist> sci;
   vector<Computer> com;
   vector<Relation> rele;
   QSqlDatabase database;


};

#endif // DATA_H
