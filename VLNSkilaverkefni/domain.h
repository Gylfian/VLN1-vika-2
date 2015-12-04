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

    vector<CScientist> search(CScientist cSci, string tableName);

    void sortBy(vector<CScientist> &cSciList, char pChoice, char cChoice);

    int findLongestName(vector<CScientist> cSciList);

    /*
     * Name: deleteScientist
     * Parameter/s: CScientist cSci
     * Description: Deletes a specific scientist from the list
     * Usage: deleteScientist(cSci);
     * (vector<CScientist>)Output/Return: element deleted from database.
     */
    void deleteScientist(CScientist cSci, string tableName);

    void addScientist(CScientist, string tableName);

    /*
     * Name: normalizeName
     * Description: Fixes names that are badly input
     * Usage: normalizeName("jÓn bAlduRSsOn")
     * (str)Output/Return: Jón Baldursson
     */
    bool normalizeName(string &name);

private:

    string createSelectQuery(CScientist cSci, string tableName);

    string createDeleteQuery(CScientist cSci, string tableName);

    string createInsertQuery(CScientist cSci, string tableName);


};

#endif // DOMAIN_H
