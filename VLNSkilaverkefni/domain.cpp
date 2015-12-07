#include "domain.h"

Domain::Domain()
{

}

void Domain::sortBy(vector<CScientist> &cSciList, char child, char child2)
{

    if(child == '1') //sort by name
    {
        bool ascending = checkOption(child2);
        getName(ascending);
    }
    else if(child == '2')
    {
        bool male = checkOption(child2);
        getGender(male);
    }
    else if(child == '3')
    {
        bool youngest = checkOption(child2);
        getYear(youngest);
    }
    else
    {
        //getById();
    }

}
void Domain::sortBy(vector<Computer> &cComList, char child, char child2)
{
    if(child == '1') //sort by name
    {
        bool ascending = checkOption(child2);
        getComName(ascending);
    }
    else if(child == '2')//yearbuilt
    {
        bool youngest = checkOption(child2);
        getComYear(youngest);
    }
    else if(child == '3')//type
    {
        bool ascending = checkOption(child2);
        getComType(ascending);
    }
    else if(child == '4')//built
    {
        bool built = checkOption(child2);
        getComType(built);
    }
    else
    {
        //getById();
    }
}

void Domain::getComName(bool ascending)
{
    if(ascending)
    {

    }
    else
    {

    }
}

void Domain::getComType(bool ascending)
{
    if(ascending)
    {

    }
    else
    {

    }
}

void Domain::getComYear(bool youngest)
{
    if(youngest)
    {

    }
    else
    {

    }
}

void Domain::getComBuilt(bool built)
{
    if(built)
    {

    }
    else
    {

    }
}

void Domain::getName(bool ascending)
{
    if(ascending)
    {

    }
    else
    {

    }
}

void Domain::getGender(bool male)
{
    if(male)
    {

    }
    else
    {

    }
}

void Domain::getYear(bool youngest)
{
    if(youngest)
    {

    }
    else
    {

    }
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
    //Data data;
    //insertQuery = data.executeQuery(search);
}

void Domain::deleteScientist(CScientist cSci)
{
    data.deleteEntry(cSci);
    //Data data;
    //deleteQuery = data.executeQuery(search);
}


bool Domain::checkOption(char child)
{
    if(child == '1')
        return true;

    return false;
}


int Domain::findLongestName(vector<CScientist> cSciList)
{
    unsigned int length = 0;
    for(unsigned int i = 0; i < cSciList.size(); i++)
    {
        if(i+1 > cSciList.size())
            break;

        if(length > cSciList[i].getName().length())
        {
           length = cSciList[i].getName().length();
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

bool Domain::verifyBirthyear(int year)
{
    if(year <= 3000 || year >= 0)
    {
        return true;
    }
    return false;
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


