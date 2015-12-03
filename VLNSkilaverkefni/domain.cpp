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

string Domain::search(CScientist cSci)
{
    string sql = "SELECT *";
        sql += " FROM WHERE ";
        if(!cSci.getName().empty())
        {
            sql += "name LIKE '%" + cSci.getName() + "%' AND ";
        }

        if(!cSci.getGender().empty())
        {
            if(cSci.getGender() == "Male")
                sql += "gender LIKE 'Male' AND ";
            else
                sql += "gender LIKE 'Female' AND ";
        }

        if(!cSci.getDob().empty())
        {
            sql += "dob LIKE '" + cSci.getDob() + "' AND ";
        }

        if(!cSci.getDod().empty())
        {
            sql += "dod LIKE '" + cSci.getDod() + "' AND ";
        }
        if (sql.size () > 0)  sql.resize (sql.size () - 5);

        return sql;
}


void Domain::deleteScientist(CScientist indexToDelete, vector<CScientist> &cSciList)
{
    for(unsigned int j = 0; j < cSciList.size(); j++)
    {
        if(cSciList[j].getName() == indexToDelete.getName())
        {
            cSciList.erase(cSciList.begin()+j);
        }

    }
    Data data;
    data.writeToFile("scientists.txt", cSciList, true);
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


void Domain::addToFile(vector<CScientist> &cSciList)
{
    Data data;
    data.writeToFile("scientists.txt", cSciList, false);
}

vector<CScientist> Domain::readFile()
{
    Data data;
    vector<CScientist> vec = data.readFromFile("scientists.txt");
    return vec;
}
