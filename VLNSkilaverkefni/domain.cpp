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

string Domain::createSelectQuery(CScientist cSci, string tableName)
{
    string sql = "SELECT *";
    sql += " FROM " + tableName + " WHERE ";
    if(!cSci.getName().empty())
    {
        sql += "name LIKE '%" + cSci.getName() + "%' AND ";
    }

    if(!cSci.getGender().empty())
    {
        if(cSci.getGender() == "Male")
            sql += "gender='Male' AND ";
        else
            sql += "gender='Female' AND ";
    }

    if(!cSci.getDob().empty())
    {
        sql += "dob='" + cSci.getDob() + "' AND ";
    }

    if(!cSci.getDod().empty())
    {
        sql += "dod='" + cSci.getDod() + "' AND ";
    }
    if (sql.size () > 0)  sql.resize (sql.size () - 5);
    sql += ";";
    return sql;
}

int Domain::findLongestName(vector<CScientist> cSciList)
{
    int length = 0;
    for(int i = 0; i < cSciList.size(); i++)
    {
        if(i+1 > cSciList)
            break;

        if(length > cSciList[i].getName().length())
        {
           length = cSciList[i].getName().length();
        }
    }
    return length;
}

string Domain::createInsertQuery(CScientist cSci, string tableName)
{
    string insertValues = " (name, gender, dob, dod) ";
    if(tableName == "computers")
        insertValues = " (name, yearbuilt, type, built) ";

    string sql = "INSERT INTO " + tableName + insertValues + "VALUES ('"+ cSci.getName() +"','"+ cSci.getGender() +"','"+ cSci.getDob() +"','"+ cSci.getDod() +"')";
    return sql;
}

string Domain::createDeleteQuery(CScientist cSci, string tableName)
{
    string sql = "DELETE FROM " + tableName + " WHERE name='" + cSci.getName() + "' AND gender='" + cSci.getGender() +
            "' AND dob='" + cSci.getDob() + "' AND dod='" + cSci.getDod() + "';";
    return sql;
}

vector<CScientist> Domain::search(CScientist cSci, string tableName)
{
    vector<CScientist> searchResults;
    string searchQuery = createSelectQuery(cSci, tableName);
    //Data data;
    //searchResults = data.executeQuery(search);
    return searchResults;
}

void Domain::addScientist(CScientist cSci, string tableName)
{
    string insertQuery = createInsertQuery(cSci, tableName);
    //Data data;
    //insertQuery = data.executeQuery(search);
}

void Domain::deleteScientist(CScientist cSci, string tableName)
{
    string deleteQuery = createDeleteQuery(cSci, tableName);
    //Data data;
    //deleteQuery = data.executeQuery(search);
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
