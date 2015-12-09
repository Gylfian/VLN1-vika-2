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
     * Parameter/s: vector<CScientist> &cSciList, CScientist cSci
     * Description: Controller for searching within list from database.
     * Usage: search(list, searchfilter)
     * Output/Return: List with applied filters.
     */

    void search(vector<CScientist> &cSciList, CScientist cSci);

    void search(vector<Computer> &cComList, Computer cCom);

    /*
     * Name: sortBy
     * Parameter/s: vector<CScientist> &cSciList or vector<Computer> &, int child, int child2
     * Description: Controller for sort decisions.
     * Usage: sortBy(cSciList, 1, 1)
     * Output/Return: Sorted scientist list by name, ascending.
     */

    void sortBy(vector<CScientist> &cSciList, char child, char child2);

    void sortBy(vector<Computer> &cComList, char child, char child2);

    void changeRelation(string sid);

    /*
     * Name: restoreEntry
     * Parameter/s: vector<CScientist> &cSciList
     * Description: Updates restore entry.
     * Usage: restoreEntry(cSciList)
     * Output/Return: ...
     */

    void restoreEntry(vector<CScientist> &cSciList);

    void restoreEntry(vector<Computer> &cSciList);

    /*
     * Name: updateEntrySci
     * Parameter/s: string sid
     * Description: Updates delete state.
     * Usage: updateEntrySci(id)
     * Output/Return: ...
    */

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
     * Parameter/s: vector<Computer> cComList or vector<CScientist> cSciList or vector<string> cStrList
     * Description: Goes through the whole list and finds the longest name, used to determine width length in console.
     * Usage: findLongestName(cSciList)
     * Output/Return: The longest scientist name.
     */
    int findLongestName(vector<Computer> cComList);

    int findLongestName(vector<string> cStrList);

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
     * Name: addEntry
     * Parameter/s: CScientist cSci or Computer cSci
     * Description: Adds an entry to database.
     * Usage: addEntry(cSci);
     * (void)Output/Return: element deleted from database.
     */
    void addEntry(CScientist cSci);
    void addEntry(Computer cSci);

    /*
     * Name: normalizeName
     * Parameter/s: string &name
     * Description: Fixes names that are badly input
     * Usage: normalizeName("jÓn bAlduRSsOn")
     * (str)Output/Return: Jón Baldursson
     */
    bool normalizeName(string &name);

    /*
     * Name: checkIfLegitId
     * Parameter/s: string sid
     * Description: Checks for legitimate Id
     * Usage: checkIfLegitId(id)
     * Output/Return: true, or false.
     */
    bool checkIfLegitId(string sid);
    /*
     * Name: convertToString
     * Parameter/s: int n
     * Description: Converts integer to a string
     * Usage: convertToString(53)
     * Output/Return: 53, in string.
     */
    string convertToString(int n);
    /*
     * Name: convertToInt
     * Description: Converts string to an integer
     * Usage: convertToInt("53")
     * Output/Return: 53, in integer.
     */
    int convertToInt(string str);

    /*
     * Name: createRelation
     * Parameter/s: string str
     * Description: Creates a relation.
     * Usage: createRelation("1", "5")
     * Output/Return: 1 and 5 are connected.
     */
    void createRelation(string scientists, string computers);
    /*
     * Name: getRelationList
     * Parameter/s: string scientists, string computers
     * Description: Fills up vector with all relations
     * Usage: getRelations(strSci, strCom)
     * Output/Return:
     */
    void getRelationList(vector<string> &strSci, vector<string> &strCom, vector<int> &idRelations);

    /*
     * Name: checkIdVector
     * Parameter/s: vector<string> &strSci, vector<string> &strCom
     * Description: Checks if an Id exists within a vector.
     * Usage: checkIdVector(cSciList, 5)
     * Output/Return: If cSciList has the ID 5, return true, else false.
     */
    bool checkIdVector(vector<CScientist> cSciList, string id);
    bool checkIdVector(vector<Computer> cComList, string id);

    /*
     * Name: editEntry
     * Parameter/s: Computer cCom or CScientist cSci
     * Description: Updates an entry by id
     * Usage: editEntry(cSci)
     * Output/Return:
     */
    void editEntry(Computer cCom);
    void editEntry(CScientist cSci);

private:
    /*
     * Name: charToInt
     * Parameter/s: char chr
     * Description: Converts char to integer
     * Usage: charToInt('5')
     * Output/Return: 5 in integer.
     */
    int charToInt(char chr);
    Data data;


    /*
     * Name: get functions
     * Parameter/s: vector<CScientist> &cSciList or vector<Computer> &cComList, char child2
     * Description: Gets list, sort.
     * Usage: getName(cSciList, 2);
     * Output/Return: ...
     */
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

    /*
     * Name: solveIdToDb
     * Parameter/s: vector<CScientist> &cSciList, vector<int> solvedIdList
     * Description: Changes vector with integer IDs into actual instances.
     * Usage: solveIdToDb(cSciLast, solvedIdList);
     * Output/Return: ...
     */
    void solveIdToDb(vector<CScientist> &cSciList, vector<int> solvedIdList);
    void solveIdToDb(vector<Computer> &cSciList, vector<int> solvedIdList);
    void addRelation(CScientist cSci, Computer cCom);

    /*
     * Name: solveString
     * Parameter/s: string str
     * Description: Makes sure right input from string is put into the vector int.
     * Usage: solveString("1,5,7");
     * Output/Return: ...
     */
    vector<int> solveString(string str);
};

#endif // DOMAIN_H
