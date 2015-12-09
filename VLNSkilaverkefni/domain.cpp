#include "domain.h"

Domain::Domain()
{

}

void Domain::sortBy(vector<CScientist> &cSciList, char child, char child2)
{

    if(child == '1') //sort by name
    {
        getName(cSciList, child2);
    }
    else if(child == '2') //sort by gender
    {
        getGender(cSciList, child2);
    }
    else if(child == '3') //sort by year born
    {
        getYear(cSciList, child2);
    }
    else if(child == '4') //sort by year of death
    {
        getYearDeath(cSciList, child2);
    }
    else
    {
        getId(cSciList, child2);
    }
}

void Domain::sortBy(vector<Computer> &cComList, char child, char child2)
{
    if(child == '1') //sort by name
    {
        getComName(cComList, child2);
    }
    else if(child == '2')//sort by type
    {
        getComType(cComList, child2);
    }
    else if(child == '3')//sort by if built
    {
        getComBuilt(cComList, child2);
    }
    else if(child == '4')//sort by year built
    {
        getComYear(cComList, child2);
    }
    else
    {
        getComId(cComList, child2);
    }
}

void Domain::restoreEntry(vector<CScientist> &cSciList)
{
    getActive(cSciList);
}

void Domain::restoreEntry(vector<Computer> &cComList)
{
    getComActive(cComList);
}

void Domain::getComName(vector<Computer> &cComList, char child2)
{
    Computer com;
    data.select(com, 1, charToInt(child2));
    cComList = data.getComVector();
}

void Domain::getComType(vector<Computer> &cComList, char child2)
{
    Computer com;
    data.select(com, 2, charToInt(child2));
    cComList = data.getComVector();
}

void Domain::getComYear(vector<Computer> &cComList, char child2)
{
    Computer com;
    data.select(com, 4, charToInt(child2));
    cComList = data.getComVector();
}

void Domain::getComBuilt(vector<Computer> &cComList, char child2)
{
    Computer com;
    data.select(com, 3, charToInt(child2));
    cComList = data.getComVector();
}

void Domain::getComId(vector<Computer> &cComList, char child2)
{
    Computer com;
    data.select(com, 5, charToInt(child2));
    cComList = data.getComVector();
}

void Domain::getComActive(vector<Computer> &cComList)
{
    data.computerToRestore();
    cComList = data.getComVector();
}

void Domain::getName(vector<CScientist> &cSciList, char child2)
{
    CScientist scientist;
    data.select(scientist, 1, charToInt(child2));
    cSciList = data.getSciVector();
}

void Domain::getGender(vector<CScientist> &cSciList, char child2)
{
    CScientist scientist;
    data.select(scientist, 2, charToInt(child2));
    cSciList = data.getSciVector();
}

void Domain::getId(vector<CScientist> &cSciList, char child2)
{
    CScientist scientist;
    data.select(scientist, 5, charToInt(child2));
    cSciList = data.getSciVector();
}

void Domain::getActive(vector<CScientist> &cSciList)
{
    data.scientistToRestore();
    cSciList = data.getSciVector();
}

void Domain::getYearDeath(vector<CScientist> &cSciList, char child2)
{
    CScientist scientist;
    data.select(scientist, 4, charToInt(child2));
    cSciList = data.getSciVector();
}

void Domain::getYear(vector<CScientist> &cSciList, char child2)
{
    CScientist scientist;
    data.select(scientist, 3, charToInt(child2));
    cSciList = data.getSciVector();
}

void Domain::search(vector<CScientist> &cSciList, CScientist cSci)
{
     data.select(cSci, 5, 1);
     cSciList = data.getSciVector();
}

void Domain::search(vector<Computer> &cComList, Computer cCom)
{
     data.select(cCom, 5, 1);
     cComList = data.getComVector();
}

void Domain::addEntry(CScientist cSci)
{
    data.insert(cSci);
}

void Domain::addEntry(Computer cCom)
{
    data.insert(cCom);
}

void Domain::editEntry(CScientist cSci)
{
    string str = cSci.getName();
    normalizeName(str);
    cSci.setName(str);
    data.update(cSci);
}

void Domain::editEntry(Computer cCom)
{
    string str = cCom.getName();
    string type = cCom.getType();
    normalizeName(type);
    normalizeName(str);
    cCom.setName(str);
    cCom.setType(type);
    data.update(cCom);
}

void Domain::updateEntrySci(string sid)
{
    CScientist cSci;
    cSci.setId(convertToInt(sid));
    data.select(cSci, 1, 1);
    vector<CScientist> cSciList = data.getSciVector();
    for(unsigned int i = 0; i < cSciList.size(); i++)
    {
        if(cSciList[i].getId() == cSci.getId())
        {
            cSci = cSciList[i];
        }
    }
    data.updateStatus(cSci);
}

void Domain::updateEntryCom(string sid)
{
    Computer cCom;
    cCom.setId(convertToInt(sid));
    data.select(cCom, 1, 1);
    vector<Computer> cComList = data.getComVector();
    for(unsigned int i = 0; i < cComList.size(); i++)
    {
        if(cComList[i].getId() == cCom.getId())
        {
            cCom = cComList[i];
        }
    }
    data.updateStatus(cCom);
}

void Domain::getRelationList(vector<string> &strSci, vector<string> &strCom, vector<int> &idRelations)
{
    vector<Relation> cRelList;
    CScientist sci;
    Computer com;
    Relation rel;
    data.select(rel);
    cRelList = data.getRelVector();
    for(unsigned int i = 0; i < cRelList.size(); i++)
    {
         sci = cRelList[i].getScientist();
         com = cRelList[i].getComputer();
         string sstr = sci.getName();
         string cstr = com.getName();
         int id = cRelList[i].getId();
         idRelations.push_back(id);
         strSci.push_back(sstr);
         strCom.push_back(cstr);
    }
}

void Domain::changeRelation(string sid)
{
    Relation rel;
    int id = convertToInt(sid);
    rel.setId(id);
    data.updateStatus(rel);
}

bool Domain::checkOption(char child)
{
    if(child == '1')
        return true;

    return false;
}

int Domain::findLongestType(vector<Computer> cComList)
{
    unsigned int length = 0;
    for(unsigned int i = 0; i < cComList.size(); i++)
    {
        if(i+1 > cComList.size())
            break;

        if(length < cComList[i].getType().length())
        {
           length = cComList[i].getType().length();
        }
    }
    return length;
}

bool Domain::checkIdVector(vector<CScientist> cSciList, string sid)
{
    int id = convertToInt(sid);
    for(unsigned int i = 0; i < cSciList.size(); i++)
    {
        if(cSciList[i].getId() == id)
        {
            return true;
        }
    }
    return false;
}

bool Domain::checkIdVector(vector<Computer> cComList, string sid)
{
    int id = convertToInt(sid);
    for(unsigned int i = 0; i < cComList.size(); i++)
    {
        if(cComList[i].getId() == id)
        {
            return true;
        }
    }
    return false;
}

int Domain::charToInt(char chr)
{
    return (int)chr - 48;

}

int Domain::findLongestName(vector<CScientist> cSciList)
{
    unsigned int length = 0;
    for(unsigned int i = 0; i < cSciList.size(); i++)
    {
        if(i+1 > cSciList.size())
            break;

        if(length < cSciList[i].getName().length())
        {
           length = cSciList[i].getName().length();
        }
    }
    return length;
}

int Domain::findLongestName(vector<string> cStrList)
{
    unsigned int length = 0;
    for(unsigned int i = 0; i < cStrList.size(); i++)
    {
        if(i+1 > cStrList.size())
            break;

        if(length < cStrList[i].length())
        {
           length = cStrList[i].length();
        }
    }
    return length;
}

int Domain::findLongestName(vector<Computer> cComList)
{
    unsigned int length = 0;
    for(unsigned int i = 0; i < cComList.size(); i++)
    {
        if(i+1 > cComList.size())
            break;

        if(length < cComList[i].getName().length())
        {
           length = cComList[i].getName().length();
        }
    }
    return length;
}

bool Domain::checkIfLegitId(string sid)
{
    if(sid == "")
        return false;

    for(unsigned int i = 0; i < sid.length(); i++)
    {
        if(!isdigit(sid[i]))
            return false;
    }

    return true;
}

int Domain::convertToInt(string str)
{
    int n = 0;
    istringstream buffer(str);
    buffer >> n;
    return n;
}

int Domain::checkStrInput(string str)
{
    int n = 0;
    if(str == "")
        return -1;

    n = convertToInt(str);
    return n;
}

void Domain::solveIdToDb(vector<CScientist> &cSciList, vector<int> solvedIdList)
{
    vector<CScientist> allScientists;
    CScientist empty;
    data.select(empty, 5, 1);
    allScientists = data.getSciVector();
    for(unsigned int i = 0; i < allScientists.size(); i++)
    {
        for(unsigned int j = 0; j < solvedIdList.size(); j++)
        {
            if(solvedIdList[j] == allScientists[i].getId())
            {
                CScientist cSci = allScientists[i];
                cSciList.push_back(cSci);
            }
        }
    }
}

void Domain::createRelation(string scientists, string computers)
{
    vector<int> sciId = solveString(scientists);
    vector<int> comId = solveString(computers);
    vector<CScientist> cSciList;
    solveIdToDb(cSciList, sciId);
    vector<Computer> cComList;
    solveIdToDb(cComList, comId);

    for(unsigned int i = 0; i < cSciList.size(); i++)
    {
        for(unsigned int j = 0; j < cComList.size(); j++)
        {
            addRelation(cSciList[i], cComList[j]);
        }
    }
}

void Domain::solveIdToDb(vector<Computer> &cComList, vector<int> solvedIdList)
{
    vector<Computer> allComputers;
    Computer empty;
    data.select(empty, 5, 1);
    allComputers = data.getComVector();
    for(unsigned int i = 0; i < allComputers.size(); i++)
    {
        for(unsigned int j = 0; j < solvedIdList.size(); j++)
        {
            if(solvedIdList[j] == allComputers[i].getId())
            {
                Computer cCom = allComputers[i];
                cComList.push_back(cCom);
            }
        }
    }
}

void Domain::addRelation(CScientist cSci, Computer cCom)
{
    data.insert(cCom, cSci);
}

vector<int> Domain::solveString(string str)
{
    vector<int> vect;
    stringstream ss(str);
    int i;
    while (ss >> i)
    {
        vect.push_back(i);

        if (ss.peek() == ',')
            ss.ignore();
    }
    return vect;
}

bool Domain::verifyBirthyear(string year)
{
    istringstream buffer(year);
    int value;
    buffer >> value;
    for(unsigned int i = 0; i < year.length(); i++)
    {
        if(!isdigit(year[i]))
            return false;
    }
    if(value < 0 || value > 3000)
    {
        return false;
    }
    return true;
}

bool Domain::normalizeYear(string born, string death)
{
    int yearBorn = convertToInt(born);
    int yearDeath = convertToInt(death);
    if(yearBorn > yearDeath)
        return false;

    for(unsigned int i = 0; i < born.length(); i++)
    {
        if(!isdigit(born[i]))
            return false;
    }
    for(unsigned int j = 0; j < death.length(); j++)
    {
        if(!isdigit(death[j]))
            return false;
    }
    if(yearBorn < 0 || yearBorn > 3000)
    {
        return false;
    }
    if(yearDeath < 0 || yearDeath > 3000)
    {
        return false;
    }
    return true;
}

bool Domain::normalizeName(string &name)
{
    if(name.length() <= 0)
    {
        return false;
    }
    for(unsigned int i = 0; i < name.length(); i++)
    {
        name[i] = tolower(name[i]);
    }
    name[0] = toupper(name[0]);
    for(unsigned int j = 0; j < name.length(); j++)
    {
        if(name[j] == ' ')
        {
            if(name[j+1] != ' ')
            {
               name[j+1] = toupper(name[j+1]);
            }
        }
    }
    return true;
}
