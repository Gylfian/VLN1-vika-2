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
    else if(child == '2')
    {
        getGender(cSciList, child2);
    }
    else if(child == '3')
    {
        getYear(cSciList, child2);
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
        getComName(cComList, child2);
    }
    else if(child == '2')//yearbuilt
    {
        getComYear(cComList, child2);
    }
    else if(child == '3')//type
    {
        getComType(cComList, child2);
    }
    else if(child == '4')//built
    {
        getComBuilt(cComList, child2);
    }
    else
    {
        //getById();
    }
}

void Domain::getComName(vector<Computer> &cComList, int child2)
{
    Computer com;
    data.select(com, 1, child2);
    cComList = data.getComVector();
}

void Domain::getComType(vector<Computer> &cComList, int child2)
{
    Computer com;
    data.select(com, 2, child2);
    cComList = data.getComVector();
}

void Domain::getComYear(vector<Computer> &cComList, int child2)
{
    Computer com;
    data.select(com, 4, child2);
    cComList = data.getComVector();
}

void Domain::getComBuilt(vector<Computer> &cComList, int child2)
{
    Computer com;
    data.select(com, 3, child2);
    cComList = data.getComVector();
}

void Domain::getName(vector<CScientist> &cSciList, int child2)
{
    CScientist scientist;
    data.select(scientist, 1, child2);
    cSciList = data.getSciVector();
    for(int i = 0; i < cSciList.size(); i++)
    {
        cout << cSciList[i].getName();
    }
cout << "Status " << endl;
int x;
cin >> x;
}

void Domain::getGender(vector<CScientist> &cSciList, int child2)
{
    CScientist scientist;
    data.select(scientist, 2, child2);
    cSciList = data.getSciVector();
}

void Domain::getYear(vector<CScientist> &cSciList, int child2)
{
    CScientist scientist;
    data.select(scientist, 3, child2);
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


