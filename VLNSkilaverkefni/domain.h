#ifndef DOMAIN_H
#define DOMAIN_H
#include <algorithm>
#include <sstream>
#include "data.h"
class Domain
{
public:
    Domain();
    vector<CScientist> getScientistList();
    vector<CScientist> searchByName(vector<CScientist> cSciList, string name);
    vector<CScientist> searchByGender(vector<CScientist> cSciList, string gender);
    vector<CScientist> searchByDateBorn(vector<CScientist> cSciList, string dateBorn);
    vector<CScientist> searchByDateDeath(vector<CScientist> cSciList, string dateDeath);
    void sortByYear(vector<CScientist> &cSciList, bool byOldest);
    void sortByGender(vector<CScientist> &cSciList, bool byMale, bool byAscending);
    void sortByAlphabet(vector<CScientist> &cSciList, bool byAscending);
    void addToFile(vector<CScientist> &cSciList);
    void deleteScientist(vector<CScientist> &cSciList, int index);
    bool normalizeName(string &name);
private:
    vector<int> vecStrToInt(vector<CScientist> cSciList);
    int  decimalValue(char x);
    int  compareString(string str1, string str2);
    int  compareYears(int year1, int year2);
    void normalizeList(vector<CScientist>  &cSciList, vector<int> listYear);
    void reverseList(vector<CScientist> &cSciList);
    void mergeList(vector<CScientist> &cSciList, vector<CScientist> vec1, vector<CScientist> vec2);
    void swapValues(vector<CScientist> &cSciList, int index1, int index2);
    void swapIntValues(vector<int> &cSciList, int index1, int index2);
};

#endif // DOMAIN_H
