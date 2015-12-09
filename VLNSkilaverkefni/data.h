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
    * Name: getDatabase
    * Parameter/s: None
    * Description: represents a connection to the database.
    * Usage: getDatabase()
    * Output/Return: database
    */
    //QSqlDatabase getDatabase();

   /*
    * Name: setDatabase
    * Parameter/s: None
    * Description: Opens the database so the user can access it.
    * Usage: setDatabase()
    */
    void setDatabase();

    /*
    * Name: select
    * Parameter/s: CScientist cSci, int index1, int index2
    * Description: Makes search command for the user.
    * Usage: select(CScientist cSci, int index1, int index2)
    * Output/Return: **
    */
    void select(CScientist cSci, int index1, int index2);
    void select(Computer comp, int index1, int index2);

   /*
    * Name: updateStatus
    * Parameter/s: CScientist cSci
    * Description: Changes the isActive status to either 1 or 0.
    * Usage: updateStatus(CScientist cSci)
    * Output/Return: if the scientist isActive = 0, it returns isActive = 1
    */
    void updateStatus(CScientist cSci);
    void updateStatus(Computer comp);

   /*
    * Name: insert
    * Parameter/s: CScientist cSci
    * Description: The user is able to add scientists to the list.
    * Usage: The user answers all informaitions quiestions.
    * Output/Return: The new scientist/s.
    */
    void insert(CScientist cSci);
    void insert(Computer comp);

   /*
    * Name: update
    * Parameter/s: CScientist cSci
    * Description: The user can make changes to the list.
    * Usage: When selected "Edit the lists", the user can change the informations in the lists.
    * Output/Return: the new informaitions that the user inputs.
    */
    void update(CScientist cSci);
    void update(Computer comp);
    vector<CScientist> getSciVector();
    vector<Computer> getComVector();
    vector<Relation> getRelVector();

   /*
    * Name: scientistToRestore
    * Parameter/s: None
    * Description: If the scientists is not active, the user can restore them.
    * Usage: **
    * Output/Return: **
    */
    void scientistToRestore();
    void computerToRestore();
    void relationToRestore();
    /*
     * Name: setRelations
     * Parameter/s: Computer comp, CScientist cSci
     * Description:
     * Usage:
     * Output/Return:
     */
    void setRelations(Computer comp, CScientist cSci);

    void select(Relation Rel);
private:
   vector<CScientist> sci;
   vector<Computer> com;
   vector<Relation> rel;
   QSqlDatabase database;

   /*
    * Name: fillVector
    * Parameter/s: QSqlDatabase db, CScientist sci, QString command
    * Description: Fills the vector with informaition.
    * Usage: fillVector(database, cSci, qsql)
    * Output/Return: **
    */
   bool fillVector(QSqlDatabase db, CScientist sci, QString command);
   bool fillVector(QSqlDatabase db, Computer com, QString command);
   bool fillVector(QSqlDatabase db, Relation rel, QString command);

   /*
    * Name: makeQuery
    * Parameter/s: CScientist sci, QSqlQuery query
    * Description: Makes the query for the scientists
    * Usage: **
    * Output/Return: **
    */
   void makeQuery(CScientist& sci, QSqlQuery query);
   void makeQuery(Computer & comp, QSqlQuery query);
   void makeQuery(Relation & rel, QSqlQuery query);
   void sortQuerySci(string & sql,int index1, int index2);
   void sortQueryCom(string & sql,int index1, int index2);

   string convertId(int id);
};

#endif // DATA_H
