#ifndef DOMAIN_H
#define DOMAIN_H

#include "main.h"
#include "computerscientist.h"
class Domain
{
public:
    Domain();
    vector<CScientist> sortByYear(bool byOldest, vector<CScientist> cSciList);

    //Alphabet functions
    void sortByAlphabet(vector<CScientist> &cSciList, bool byAscending);
private:
    void swapValues(vector<CScientist> &cSciList, int index1, int index2);
    int decimalValue(char x);
    int compareString(string str1, string str2);
    void reverseList(vector<CScientist> &cSciList);
};

#endif // DOMAIN_H
