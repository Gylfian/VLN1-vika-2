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
    else if(child == '2') //gender
    {
        getGender(cSciList, child2);
    }
    else if(child == '3') //year
    {
        getYear(cSciList, child2);
    }
    else if(child == '4') //yeardeath
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
    else if(child == '2')//type
    {
        getComType(cComList, child2);
    }
    else if(child == '3')//year
    {
        getComBuilt(cComList, child2);
    }
    else if(child == '4')//ya
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


void Domain::search(CScientist cSci)
{
   // data.select(cSci);
}

void Domain::search(Computer cCom)
{
    //data.select(cCom);
}

void Domain::addScientist(CScientist cSci)
{
    data.insert(cSci);
}

void Domain::updateEntry(CScientist cSci)
{
    data.updateStatus(cSci);
}

void Domain::updateEntry(Computer cCom)
{
    data.updateStatus(cCom);
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

    convertToInt(str);
    return n;
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
    if(yearBorn <= yearDeath)
        return true;
    return false;
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


