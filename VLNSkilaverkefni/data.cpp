#include "data.h"
#include <QtSql>
#include <QDebug>
#include <QSqlError>

Data::Data()
{

}

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
        CScientist scientist(6, name, gender, dob, dod, false);
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

QSqlDatabase Data::addDatabase()
{
    cout << "Add database function" << endl;
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "VLN1.sqlite";
    db.setDatabaseName(dbName);
    return db;

}

void Data::addQuery(QSqlDatabase db, const QString& command, vector<Computer>& sci)
{
    QSqlQuery query(db);
    if (!query.exec(command)) {
        cout << "exec returns false: " << endl;
        qDebug() << query.lastError().text();
    }
    query.first();
    cout << "is active: " << query.isActive() << endl;
    while(query.next())
    {
        Computer temp;
        comQuery(temp,query);
        sci.push_back(temp);
    }
}

void Data::addQuery(QSqlDatabase db, const QString& command, vector<CScientist>& sci)
{
    QSqlQuery query(db);
    if (!query.exec(command))
    {
        cout << "exec returns false: " << endl;
        qDebug() << query.lastError().text();
    }
    query.first();
    cout << "is active: " << query.isActive() << endl;
    while(query.next())
    {
        CScientist temp;
        sciQuery(temp, query);
        sci.push_back(temp);
    }
}

void Data::sciQuery(CScientist& temp, QSqlQuery query)
{
    unsigned int qId = query.value("ID").toUInt();
    temp.setId(qId);
    cout << temp.getId() << endl;
    string qName = query.value("Name").toString().toStdString();
    temp.setName(qName);
    cout << temp.getName() << endl;
    string qGender = query.value("Gender").toString().toStdString();
    temp.setGender(qGender);
    cout << temp.getName() << endl;
    string qDob = query.value("Dob").toString().toStdString();
    temp.setDob(qDob);
    cout << temp.getDob() << endl;
    string qDod = query.value("Dod").toString().toStdString();
    temp.setDob(qDob);
    cout << temp.getDob() << endl;
    bool qIsActive = query.value("IsActive").toBool();
    temp.setIsActive(qIsActive);
    cout << temp.getIsActive() << endl;

}

void Data::comQuery(Computer & comp, QSqlQuery query)
{
    Computer temp;
    unsigned int qID = query.value("ID").toUInt();
    cout << qID << endl;
    string qName = query.value("Name").toString().toStdString();
    cout << qName << endl;
    string qType = query.value("Type").toString().toStdString();
    cout << qType << endl;
    string qBuilt = query.value("Built").toString().toStdString();
    cout << qBuilt << endl;
}
