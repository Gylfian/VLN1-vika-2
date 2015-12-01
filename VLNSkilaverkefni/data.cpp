#include "presentation.h"

Data::Data()
{
}

void Data::readFromFile(string docName)
{
    ifstream inStream;
    vector <CScientist> scientists;
    inStream.open(docName.c_str());
    string name, gender, dob,dod;
    while(!inStream.eof())
    {
        getline(inStream, name, '/');
        getline(inStream, gender);
        getline(inStream, dob);
        getline(inStream, dod);
        CScientist scientist(name, gender, dob, dod);
        scientists.push_back(scientist);

    }
    inStream.close();
}

ostream& operator <<(ostream& stream, const CScientist& scientist)
{
    stream << scientist.getName() << "/";
    stream << scientist.getGender() << " ";
    stream << scientist.getDob() << " ";
    stream << scientist.getDod() << endl;
    return stream;
}

void Data::writeToFile(string docName, vector <CScientist>& scientists)
{
    ofstream outStream;
    outStream.open(docName.c_str(), ios::app);
    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        outStream << scientists[i];
    }
}
