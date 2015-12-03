#include "presentation.h"
#include <QtSql>

vector<CScientist> Data::readFromFile(string docName)
{
    ifstream inStream;
    vector <CScientist> scientists;
    inStream.open(docName.c_str());
    string name, gender, dob,dod;
    while(!inStream.eof())
    {
        getline(inStream, name, '/');
        if(name == "")
            break;
        getline(inStream, gender, '/');
        getline(inStream, dob, '/');
        getline(inStream, dod);
        CScientist scientist(name, gender, dob, dod);
        scientists.push_back(scientist);

    }
    inStream.close();
    return scientists;
}

ostream& operator <<(ostream& stream, const CScientist& scientist)
{
    stream << scientist.getName() << "/";
    stream << scientist.getGender() << "/";
    stream << scientist.getDob() << "/";
    stream << scientist.getDod() << endl;
    return stream;
}

void Data::writeToFile(string docName, vector <CScientist>& scientists, bool overwrite)
{
    ofstream outStream;
    if(overwrite)
        outStream.open(docName.c_str());
    else
        outStream.open(docName.c_str(), ios::app);
    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        outStream << scientists[i];
    }
}
