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

    void search(vector<CScientist> &cSciList, CScientist cSci);

    void search(vector<Computer> &cComList, Computer cCom);

    void sortBy(vector<CScientist> &cSciList, char child, char child2);

    void sortBy(vector<Computer> &cComList, char child, char child2);

    void restoreEntry(vector<CScientist> &cSciList);

    void restoreEntry(vector<Computer> &cSciList);

    void updateEntrySci(string sid);

    void updateEntryCom(string sid);

    int findLongestName(vector<CScientist> cSciList);

    int findLongestName(vector<Computer> cComList);

    int findLongestType(vector<Computer> cComList);

    int checkStrInput(string str);

    bool normalizeYear(string born, string death);

    bool verifyBirthyear(string year);

    /*
     * Name: deleteScientist
     * Parameter/s: CScientist cSci
     * Description: Deletes a specific scientist from the list
     * Usage: deleteScFFFFFFFFFFFFientist(cSci);
     * (vector<CScientist>)Output/Return: element deleted from database.
     */
    void addEntry(CScientist cSci);

    void addEntry(Computer cSci);

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
    int charToInt(char chr);
    int convertToInt(string str);
    Data data;
    void getName(vector<CScientist> &cSciList, char child2);
    void getGender(vector<CScientist> &cSciList, char child2);
    void getYear(vector<CScientist> &cSciList, char child2);
    void getYearDeath(vector<CScientist> &cSciList, char child2);
    void getId(vector<CScientist> &cSciList, char child2);
    void getActive(vector<CScientist> &cSciList);

    void getComName(vector<Computer> &cComList, char child2);
    void getComYear(vector<Computer> &cComList, char child2);
    void getComType(vector<Computer> &cComList, char child2);
    void getComBuilt(vector<Computer> &cComList, char child2);
    void getComId(vector<Computer> &cComList, char child2);
    void getComActive(vector<Computer> &cComList);

    bool checkOption(char child);
};

#endif // DOMAIN_H
