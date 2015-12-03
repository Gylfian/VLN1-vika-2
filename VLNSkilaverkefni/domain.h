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

    string search(CScientist cSci);

    void sortBy(vector<CScientist> &cSciList, char pChoice, char cChoice);

    /*
     * Name: addToFile
     * Parameter/s: vector<CScientist> &cSciList
     * Description: Takes in choice of sorting method from user and salls appropriate sorting function
     * Usage: vector<CScientist> vec = searchByDateDeath(cSciList, "1905"):
     * (vector<CScientist>)Output/Return: Retrieves everyone with specific death date, in this case 1905
     */
    void addToFile(vector<CScientist> &cSciList);

    /*
     * Name: readFile
     * Parameter/s: None
     * Description: Takes in choice of sorting method from user and salls appropriate sorting function
     * Usage: vector<CScientist> vec = searchByDateDeath(cSciList, "1905"):
     * (vector<CScientist>)Output/Return: Retrieves everyone with specific death date, in this case 1905
     */
    vector<CScientist> readFile();

    /*
     * Name: deleteScientist
     * Parameter/s: vector<CScientist> &cSciList, int index
     * Description: Deletes a specific scientist from the list
     * Usage: deleteScientist(cSciList, 5);
     * (vector<CScientist>)Output/Return: 5th element deleted.
     */
    void deleteScientist(CScientist indexToDelete, vector<CScientist> &cSciList);


    /*
     * Name: normalizeName
     * Description: Fixes names that are badly input
     * Usage: normalizeName("jÓn bAlduRSsOn")
     * (str)Output/Return: Jón Baldursson
     */
    bool normalizeName(string &name);

private:


};

#endif // DOMAIN_H
