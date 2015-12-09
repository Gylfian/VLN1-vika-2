#ifndef DATA_H
#define DATA_H
#include "computerscientist.h"
#include "computer.h"
#include "relation.h"
#include <QDebug>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QtSql>
#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>
#include <QVariant>
using namespace std;

class Data
{
public:

    Data();

   /*
    * Name: setDatabase
    * Parameter/s: None
    * Description: Opens the database so the user can access it.
    * Usage: setDatabase();
    */
    void setDatabase();

    /*
    * Name: select
    * Parameter/s: (CScientist cSci or Computer Comp, int index1, int index2) or (Relation Rel)
    * Description: Creates a SELECT query needed for search and display.
    * Usage: select(CScientist cSci or Computer comp, int index1, int index2) or select(Relation Rel);
    */
    void select(CScientist cSci, int index1, int index2);
    void select(Computer comp, int index1, int index2);
    void select(Relation Rel);

   /*
    * Name: updateStatus
    * Parameter/s: CScientist cSci or Computer comp
    * Description: Changes the isActive status of an entry so deleted entries are restored and entries that are not deleted are deleted
    * Usage: updateStatus(CScientist cSci or Computer comp);
    */
    void updateStatus(CScientist cSci);
    void updateStatus(Computer comp);

   /*
    * Name: insert
    * Parameter/s: (CScientist cSci or Computer comp) or (Computer comp, CScientist cSci)
    * Description: Creates an INSERT query neccesary to add entries to the list
    * Usage: insert(CScientist cSci or Computer comp); or insert(Computer comp, CScientist cSci);
    */
    void insert(CScientist cSci);
    void insert(Computer comp);
    void insert(Computer comp, CScientist cSci);

   /*
    * Name: update
    * Parameter/s: CScientist cSci or Computer comp
    * Description: Creates a SET query necessary to edit entries in the list
    * Usage: update(CScientist cSci); or update(CScientist cSci);
    */
    void update(CScientist cSci);
    void update(Computer comp);

   /*
    * Name: ToRestore
    * Parameter/s: None
    * Description: Creates a SELECT query for entries that have been deleted
    * Usage: scientistToRestore(); or computerToRestore(); or relationToRestore();
    */
    void scientistToRestore();
    void computerToRestore();
    void relationToRestore();

    vector<CScientist> getSciVector();
    vector<Computer> getComVector();
    vector<Relation> getRelVector();
    void updateStatus(Relation rel);
private:
   vector<CScientist> sci;
   vector<Computer> com;
   vector<Relation> rel;
   QSqlDatabase database;

   /*
    * Name: fillVector
    * Parameter/s: (QSqlDatabase db, CScientist sci or Computer or Relation Rel, QString command)
    * Description: Executes the query and fills up the private vector
    * Usage: fillVector(QSqlDatabase db,CScientis sci or Computer com or Relation rel,Qstring command);
    * Output/Return: true or false
    */
   bool fillVector(QSqlDatabase db, CScientist sci, QString command);
   bool fillVector(QSqlDatabase db, Computer com, QString command);
   bool fillVector(QSqlDatabase db, Relation rel, QString command);

   /*
    * Name: makeQuery
    * Parameter/s: (CScientist & sci or Computer &  comp or Relation & rel, QSql query
    * Description: Used in fillvector to add the variables from the query table into a variable to be pushed back in the vector
    * Usage: makeQuery(CScientist sci or Computer comp or Relation Rel,QSqlQuery query);
    */
   void makeQuery(CScientist& sci, QSqlQuery query);
   void makeQuery(Computer & comp, QSqlQuery query);
   void makeQuery(Relation & rel, QSqlQuery query);
   /*
    * Name: sortQuery
    * Parameter/s: (string & sql,int index1,int index2)
    * Description: adds ORDER BY to the SELECT string created  in select
    * Usage: sortQuerySci(string & sql,int index1, int index2);
    */
   void sortQuerySci(string & sql,int index1, int index2);
   void sortQueryCom(string & sql,int index1, int index2);
   /*
    * Name: convertID
    * Parameter/s: (int id)
    * Description: Converts an id from an integer to a string so it can be added to a query string easily
    * Usage: convertID(int id;
    * Output/Return: the id as a string
    */
   string convertId(int id);
};

#endif // DATA_H
