#ifndef DOMAIN_H
#define DOMAIN_H
#include <algorithm>
#include <sstream>
#include "data.h"
class Domain
{
public:

    /*
     * Name: Domain
     * Parameter/s: None
     * Description: Default constructor for Domain class
     * Usage:
     *
     */
    Domain();

    /*
     * Name: getScientistList
     * Parameter/s: none
     * Description: Returns a list of scientists from text file
     * Usage: vector<CScientist> list = getScientistList()
     * Output/Return: list = allScientists
     */

    void search(CScientist cSci);

    void search(Computer cCom);

    void requestSciSql(QSqlDatabase db, QString sql, vector<CScientist> &cSciList);

    void requestComSql(QSqlDatabase db, QString sql, vector<Computer> &cComList);

    void sortBy(vector<CScientist> &cSciList, char child, char child2);

    void sortBy(vector<Computer> &cComList, char child, char child2);

    int findLongestName(vector<CScientist> cSciList);

    int checkStrInput(string str);

    bool normalizeYear(string born, string death);

    bool verifyBirthyear(int year);

    /*
     * Name: deleteScientist
     * Parameter/s: CScientist cSci
     * Description: Deletes a specific scientist from the list
     * Usage: deleteScientist(cSci);
     * (vector<CScientist>)Output/Return: element deleted from database.
     */
    void deleteScientist(CScientist cSci);

    void addScientist(CScientist cSci);

    /*
     * Name: normalizeName
     * Description: Fixes names that are badly input
     * Usage: normalizeName("jÓn bAlduRSsOn")
     * (str)Output/Return: Jón Baldursson
     */
    bool normalizeName(string &name);

private:
    QString createSelectQuery(CScientist cSci);
    QString createDeleteQuery(CScientist cSci);
    QString createInsertQuery(CScientist cSci);
    int convertToInt(string str);
    Data data;
    void getName(bool ascending);
    void getGender(bool male);
    void getYear(bool youngest);

    void getComName(bool ascending);
    void getComYear(bool youngest);
    void getComType(bool ascending);
    void getComBuilt(bool built);

    bool checkOption(char child);
};

#endif // DOMAIN_H
