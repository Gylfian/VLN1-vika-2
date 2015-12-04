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
    db.open();
    return db;

}

void Data::addQuery(QSqlDatabase db)
{
    cout << "virkar";
    QSqlQuery query(db);
    if (!query.exec("SELECT * FROM Computerscientists")) {
        cout << "exec returns false: " << endl;
        qDebug() << query.lastError().text();
    }

    query.first();
    cout << "is active: " << query.isActive() << endl;

    cout << query.value(1).toString().toStdString() << endl;

    while(query.next())
    {
        int fff = query.value("ID").toUInt();
        cout << fff << endl;
        string bla = query.value("Name").toString().toStdString();
        cout << bla << endl;
        string fla = query.value("Gender").toString().toStdString();
        cout << fla << endl;
        string zla = query.value("Dob").toString().toStdString();
        cout << zla << endl;
        string dla = query.value("Dod").toString().toStdString();
        cout << dla << endl;
    }
    cout << query.size();
    cout << query.isValid();

    //int employeeId = query.value(0).toInt();
    //cout << employeeId;
}
