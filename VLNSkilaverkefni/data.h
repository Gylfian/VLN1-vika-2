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

    /*
     * Name: operator <<
     * Parameter/s: ostream& stream, const CScientist& scientist
     * Description: Overloads the << operator so it writes out instance of the CScientist class correctly
     * Usage: outStream << scientist; (outStream is some previously declared of stream and scientist is an instance of the CScientist class)
     * (void)Output/Return: Name gender yearBorn deathyear
     */
    friend ostream& operator <<(ostream& stream, const CScientist& scientist);

    /*
     * Name: readFromFile
     * Parameter/s: string docName
     * Description: Reads data from text file whose name is passed by value to the function
     * Usage: vector<CScientist> vec = data.readFromFile("scientists.txt");
     * (void)Output/Return: the vector vec is filled with data from the text file scientists.txt
     */
    vector<CScientist> readFromFile(string docName);

    /*
     * Name: writeToFile
     * Parameter/s: string docName, vector <CScientist>& scientists
     * Description: Writes data from a vector, passed by value to the function, to a text file whose name is passed by value
     * Usage: data.writeToFile("scientists.txt", cSciList);
     * (void)Output/Return: The text file scientists.txt is filled with data from the vector cSciList
     */
    void writeToFile(string docName, vector <CScientist>& scientists, bool overwrite);
    Data();
    bool fillVector(QSqlDatabase db, CScientist sci, QString command);
    bool fillVector(QSqlDatabase db, Computer com, QString command);
    bool fillVector(QSqlDatabase db, Relation rele, QString command);
    QSqlDatabase getDatabase();
    void sciQuery(CScientist& sci, QSqlQuery query);
    void comQuery(Computer & comp, QSqlQuery query);
    void releQuery(Relation & comp, QSqlQuery query);
    bool editDatabase(QSqlDatabase db, const QString& command);
    void setDatabase();
    void selectScientist(CScientist cSci);
    void deleteScientist(CScientist cSci);
    void insertScientist(CScientist cSci);
    void selectComputer(Computer comp);
    void deleteComputer(Computer comp);
    void insertComputer(Computer comp);
    void updateComputer(Computer comp);
    void updateComputerScientits(CScientist cSci);
    bool executequery(QSqlQuery query, QString command);
    void setRelations(Computer comp, CScientist cSci,QSqlDatabase db);

private:
   vector<CScientist> sci;
   vector<Computer> com;
   vector<Relation> rele;
   QSqlDatabase database;

};

#endif // DATA_H
