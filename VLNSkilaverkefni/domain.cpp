#include "domain.h"

Domain::Domain()
{

}

void Domain::sortBy(char parent, char child, char child2)
{
    switch(parent)
    {
        case('1'): //scientist
        {
            if(child == '1') //sort by name
            {
                getName(child2);
            }
            else if(child == '2')
            {
                //getGender();
            }
        }
            break;
        case('2')://computer
            if(child == '1')//male first
            {

            }
            else
            {

            }
            break;
    }
}

void Domain::getName(char child)
{

}

vector<CScientist> Domain::search(CScientist cSci, string tableName)
{
    vector<CScientist> searchResults;
    data.selectScientist(cSci);
    //Data data;
    //searchResults = data.executeQuery(search);
    return searchResults;
}

void Domain::addScientist(CScientist cSci, string tableName)
{
    data.insertScientist(cSci);
    //Data data;
    //insertQuery = data.executeQuery(search);
}

void Domain::deleteScientist(CScientist cSci, string tableName)
{
    data.deleteScientist(cSci);
    //Data data;
    //deleteQuery = data.executeQuery(search);
}

//void Domain::requestSciSql(QSqlDatabase db, QString sql, vector<CScientist> &cSciList)
//{
  //  data.addQuery(db, sql, cSciList);
//}

//void Domain::requestComSql(QSqlDatabase db, QString sql, vector<Computer> &cComList)
//{
  //  Data d1;
    //d1.addQuery(db, sql, cComList);
//}


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

bool Domain::normalizeYear(string born, string death)
{
    int yearBorn = convertToInt(born);
    int yearDeath = convertToInt(death);
    if(yearBorn < yearDeath)
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


