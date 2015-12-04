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

void Data::sciQuery(CScientist& sci, QSqlQuery query)
{
    CScientist temp;
    unsigned int qId = query.value("ID").toUInt();
    cout << qId << endl;
    string qName = query.value("Name").toString().toStdString();
    cout << qName << endl;
    string qGender = query.value("Gender").toString().toStdString();
    cout << qGender << endl;
    string qDob = query.value("Dob").toString().toStdString();
    cout << qDob << endl;
    string qDod = query.value("Dod").toString().toStdString();
    cout << qDod << endl;
    bool qIsActive = query.value("IsActive").toBool();
    cout << qIsActive << endl;
}
