#include "data.h"
#include <QtSql>
#include <QDebug>
#include <QSqlError>

Data::Data()
{
    CScientist temp;
    Computer temp2;
    sci.push_back(temp);
    com.push_back(temp2);
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

QSqlDatabase Data::getDatabase()
{
    return database;
}

void Data::setDatabase()
{
    cout << "Add database function" << endl;
    //QSqlDatabase db;
    database = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "VLN1.sqlite";
    database.setDatabaseName(dbName);
    database.open();
}

bool Data::fillVector(QSqlDatabase db, Computer temp, QString command)
{
    QSqlQuery query(db);
    if(!executequery(query, command))
    query.first();
    comQuery(temp, query);
    com.push_back(temp);
    cout << "is active: " << query.isActive() << endl;
    while(query.next())
    {
        comQuery(temp,query);
        com.push_back(temp);
    }
    return true;
}

bool Data::fillVector(QSqlDatabase db, CScientist temp, QString command)
{
    QSqlQuery query(db);
    if(!executequery(query, command))
    query.first();
    sciQuery(temp,query);
    sci.push_back(temp);
    while(query.next())
    {
        sciQuery(temp, query);
        sci.push_back(temp);
    }
    return true;
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

void Data::comQuery(Computer& temp, QSqlQuery query)
{
    int qId = query.value("ID").toUInt();
    temp.setId(qId);
    cout << qId << endl;
    string qName = query.value("Name").toString().toStdString();
    temp.setName(qName);
    cout << qName << endl;
    string qType = query.value("Type").toString().toStdString();
    temp.setType(qType);
    cout << qType << endl;
    string qBuilt = query.value("Built").toString().toStdString();
    temp.setBuilt(qBuilt);
    cout << qBuilt << endl;
    bool qIsActive = query.value("isActive").toBool();
    temp.setIsActive(qIsActive);
    cout << qBuilt << endl;
}

void Data::selectScientist(CScientist cSci)
{
    QString qsql;
    string sql = "SELECT *";
    sql += " FROM Computerscientists WHERE ";
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
    qsql = QString::fromStdString(sql);
    fillVector(database, cSci, qsql);
}

void Data::insertScientist(CScientist cSci)
{
    QString qsql;
    string sql = "INSERT INTO Computerscientists Name, Gender, type, Dob, Dod VALUES ('"+ cSci.getName() +"','"+ cSci.getGender() +"','"+ cSci.getDob() +"','"+ cSci.getDod() +"')";
    qsql = QString::fromStdString(sql);
    fillVector(database, cSci, qsql);
}

void Data::deleteScientist(CScientist cSci)
{
    QString qsql;
    int id = cSci.getId();
    string sql = "UPDATE Computerscientists SET isActive=0 WHERE ID = " +id;
    qsql = QString::fromStdString(sql);
    fillVector(database, cSci, qsql);
}

void Data::selectComputer(Computer comp)
{
    QString qsql;
    string sql = "SELECT *";
    sql += " FROM Computers WHERE ";
    if(!comp.getName().empty())
    {
        sql += "name LIKE '%" + comp.getName() + "%' AND ";
    }

    if(!comp.getYear().empty())
    {
        sql += "year=" + comp.getYear() + "$' AND ";

    }

    if(!comp.getType().empty())
    {
        sql += "type='" + comp.getType() + "' AND ";
    }

    if(!comp.getBuilt().empty())
    {
        sql += "built='" + comp.getBuilt() + "' AND ";
    }
    if (sql.size () > 0)  sql.resize (sql.size () - 5);
    sql += ";";
    qsql = QString::fromStdString(sql);
    fillVector(database, comp, qsql);
}

void Data::insertComputer(Computer comp)
{
    QString qsql;
    string sql = "INSERT INTO computers (name, yearbuilt, type, built) VALUES ('"+ comp.getName() +"','"+ comp.getYear() +"','"+ comp.getType() + "')";
    qsql = QString::fromStdString(sql);
    fillVector(database, comp, qsql);
}

void Data::deleteComputer(Computer comp)
{
    QString qsql;
    int id = comp.getId();
    string sql = "UPDATE Computer SET isActive=0 WHERE ID = " +id;
    qsql = QString::fromStdString(sql);
    fillVector(database, comp, qsql);
}

void Data::updateComputerScientits(CScientist cSci)
{
    QString qsql;
    string sql = "UPDATE Computers SET ";
    if(!cSci.getName().empty())
    {
        sql += "name ='" + cSci.getName() + "%' AND ";
    }

    if(!cSci.getGender().empty())
    {
        sql += "gender='" + cSci.getGender() + "%' AND ";;
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
    qsql = QString::fromStdString(sql);
    fillVector(database, cSci, qsql);
}

void Data::updateComputer(Computer comp)
{
    QString qsql;
    string sql = "UPDATE Computers SET ";
    if(!comp.getName().empty())
    {
        sql += "name ='" + comp.getName() + "%' AND ";
    }

    if(!comp.getYear().empty())
    {
        sql += "year='" + comp.getYear() + "$' AND ";

    }

    if(!comp.getType().empty())
    {
        sql += "type='" + comp.getType() + "' AND ";
    }

    if(!comp.getBuilt().empty())
    {
        sql += "built='" + comp.getBuilt() + "' AND ";
    }
    if (sql.size () > 0)  sql.resize (sql.size () - 5);
    sql += ";";
    qsql = QString::fromStdString(sql);
    fillVector(database, comp, qsql);
}

bool Data::executequery(QSqlQuery query,QString command)
{
    if (!query.exec(command))
    {
        return false;
    }
    return true;
}

void Data::setRelations(Computer comp, CScientist cSci,QSqlDatabase db)
{
    QString qsql;
    string sql = "INSERT INTO Relation (ScientistID, ComputerID) VALUES ("+comp.getId();+","+cSci.getId();+" )";
    qsql = QString::fromStdString(sql);
    QSqlQuery query;
    fillVector(database, cSci, qsql);
    //execute query
}
