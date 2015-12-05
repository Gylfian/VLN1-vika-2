#include "domain.h"

Domain::Domain()
{

}

void Domain::sortBy(vector<CScientist> &cSciList, char pChoice, char cChoice)
{
    switch(pChoice)
    {
        case('1'): //alphabet
            if(cChoice == '1') //ascend
            {

            }
            else
            {

            }
            break;
        case('2')://gender
            if(cChoice == '1')//male first
            {

            }
            else
            {

            }
            break;
        case('3')://year
            if(cChoice == '1')
            {

            }
            else
            {


            }
            break;

    }
}


vector<CScientist> Domain::search(CScientist cSci, string tableName)
{
    vector<CScientist> searchResults;
    QString searchQuery = data.createSelectQuery(cSci);
    //Data data;
    //searchResults = data.executeQuery(search);
    return searchResults;
}

void Domain::addScientist(CScientist cSci, string tableName)
{
    QString insertQuery = data.createInsertQuery(cSci);
    //Data data;
    //insertQuery = data.executeQuery(search);
}

void Domain::deleteScientist(CScientist cSci, string tableName)
{
    QString deleteQuery = data.createDeleteQuery(cSci);
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

int Domain::checkStrInput(string str)
{
    int n = 0;
    if(str == "")
        return -1;

    istringstream buffer(str);
    buffer >> n;
    return n;
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


