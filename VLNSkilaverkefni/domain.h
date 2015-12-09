#ifndef DOMAIN_H
#define DOMAIN_H
#include <algorithm>
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
     * Name: search
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

    /*
     * Name: findLongestName
     * Parameter/s: vector<CScientist> cSciList
     * Description: Goes through the whole list and finds the longest name.
     * Usage: **
     * Output/Return: The longest scientist name.
     */
    int findLongestName(vector<CScientist> cSciList);

    /*
     * Name: findLongestName
     * Parameter/s: vector<Computer> cComList
     * Description: Goes through the whole list and finds the longest name.
     * Usage: **
     * Output/Return: The longest computer name.
     */
    int findLongestName(vector<Computer> cComList);

    /*
     * Name:findLongestType
     * Parameter/s: vector<Computer> cComList
     * Description: Goes through the whole list and finds the longest type name.
     * Usage: **
     * Output/Return: The longest type.
     */
    int findLongestType(vector<Computer> cComList);
    int checkStrInput(string str);
    bool normalizeYear(string born, string death);
    void editEntry(string id);
    /*
     * Name: verifyBirthyear
     * Parameter/s: string year
     * Description: Makes sure that the input is in correct form and is accurrate.
     * Usage: verifyBirthyear(-1993)
     * Output/Return: false
     */
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
    bool checkIfLegitId(string sid);
    string convertToString(int n);
    int convertToInt(string str);
    void createRelation(string scientists, string computers);
    void getRelationList(vector<string> &strSci, vector<string> &strCom);
    bool checkIdVector(vector<CScientist> cSciList, string id);
    bool checkIdVector(vector<Computer> cComList, string id);
    void editEntry(Computer cCom);
    void editEntry(CScientist cSci);
    void analyze(CScientist cSci, vector<Computer> &comConnect);
    void analyze(Computer cCom, vector<CScientist> &sciConnect);
private:
    int charToInt(char chr);
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

    void solveIdToDb(vector<CScientist> &cSciList, vector<int> solvedIdList);
    void solveIdToDb(vector<Computer> &cSciList, vector<int> solvedIdList);
    void addRelation(CScientist cSci, Computer cCom);
    vector<int> solveString(string str);
};

#endif // DOMAIN_H
