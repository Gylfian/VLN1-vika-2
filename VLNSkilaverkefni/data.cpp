#include "data.h"
#include <QtSql>
#include <QDebug>
#include <QSqlError>
#include <sstream>

Data::Data()
{
    CScientist temp;
    Computer temp2;
    sci.push_back(temp);
    com.push_back(temp2);
    setDatabase();
    QSqlQuery query(database);
}

QSqlDatabase Data::getDatabase()
{
    return database;
}

void Data::setDatabase()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "VLN1.sqlite";
    database.setDatabaseName(dbName);
    database.open();
}

vector<CScientist> Data::getSciVector()
{
    return sci;
}

vector<Computer> Data::getComVector()
{
    return  com;
}

bool Data::fillVector(QSqlDatabase db, CScientist temp, QString command)
{
    sci.clear();
    if(!db.isOpen())
    {
        setDatabase();
    }
    QSqlQuery query(database);
    if(!query.exec(command))
    {
        return false;
    }
    while(query.next())
    {
        makeQuery(temp, query);
        sci.push_back(temp);
    }
    return true;
}

bool Data::fillVector(QSqlDatabase db, Computer temp, QString command)
{
    com.clear();
    if(!db.isOpen())
    {
        setDatabase();
    }
    QSqlQuery query(database);
    if(!query.exec(command))
    {
        return false;
    }
    while(query.next())
    {
        makeQuery(temp,query);
        com.push_back(temp);
    }
    return true;
}

bool Data::fillVector(QSqlDatabase db, Relation temp, QString command)
{
    rel.clear();
    if(!db.isOpen())
    {
        setDatabase();
    }
    QSqlQuery query(db);
    if(!query.exec(command))
    {
        return false;
    }
    while(query.next())
    {
        makeQuery(temp,query);
        rel.push_back(temp);
    }
    return true;
}

void Data::makeQuery(CScientist& temp, QSqlQuery query)
{
    unsigned int qId = query.value("ID").toUInt();
    temp.setId(qId);
    string qName = query.value("Name").toString().toStdString();
    temp.setName(qName);
    string qGender = query.value("Gender").toString().toStdString();
    temp.setGender(qGender);
    string qDob = query.value("Dob").toString().toStdString();
    temp.setDob(qDob);
    string qDod = query.value("Dod").toString().toStdString();
    temp.setDod(qDod);
    bool qIsActive = query.value("IsActive").toBool();
    temp.setIsActive(qIsActive);
}

void Data::makeQuery(Computer& temp, QSqlQuery query)
{
    int qId = query.value("ID").toUInt();
    temp.setId(qId);
    string qName = query.value("Name").toString().toStdString();
    temp.setName(qName);
    string qType = query.value("Type").toString().toStdString();
    temp.setType(qType);
    string qBuilt = query.value("Built").toString().toStdString();
    temp.setBuilt(qBuilt);
    string qYear = query.value("Year").toString().toStdString();
    temp.setYear(qYear);
    bool qIsActive = query.value("isActive").toBool();
    temp.setIsActive(qIsActive);
}

void Data::makeQuery(Relation& temp, QSqlQuery query)
{
    int qComp = query.value("ScientistID").toUInt();
    temp.setComputerId(qComp);
    int qSci = query.value("ComputerID").toUInt();
    temp.setScientistId(qSci);
}

void Data::select(CScientist cSci,int index1,int index2)
{
    QString qsql;
    string sql = "SELECT *";
    sql += " FROM Computerscientists";
    sql += " WHERE Name LIKE '%" + cSci.getName() + "%'";
    if(!cSci.getGender().empty())
    {
        if(cSci.getGender() == "Male")
            sql += " AND Gender='Male'";
        else
            sql += " AND Gender='Female'";
    }

    if(!cSci.getDob().empty())
    {
        sql += " AND Dob='" + cSci.getDob() + "'";
    }

    if(!cSci.getDod().empty())
    {
        sql += " AND Dod='" + cSci.getDod() + "'";
    }
    sql += " AND isActive=1 ";
    sortQuerySci(sql,index1,index2);
    sql += ";";
    qsql = QString::fromStdString(sql);
    fillVector(database, cSci, qsql);
}

void Data::select(Computer comp,int index1,int index2)
{
    QString qsql;
    string sql = "SELECT *";
    sql += " FROM Computers WHERE ";
    sql += "Name LIKE '%" + comp.getName() + "%'";
    cout << comp.getName() << endl;
    if(!comp.getYear().empty())
    {
        sql += " AND year=" + comp.getYear() + "$'";
    }

    if(!comp.getType().empty())
    {
        sql += " AND type LIKE '%" + comp.getType() + "%'";
    }

    if(!comp.getBuilt().empty())
    {
        sql += " AND built='" + comp.getBuilt() + "'";
    }
    sql += " AND isActive=1";
    sortQueryCom(sql,index1,index2);
    sql += ";";
    qsql = QString::fromStdString(sql);
    fillVector(database, comp, qsql);
}

void Data::sortQuerySci(string & sql,int index1, int index2)
{
    if(index1 == 1)
    {
        sql += " ORDER BY Name";
    }
    if(index1 == 2)
    {
        sql += " ORDER BY Gender";
    }
    if(index1 == 3)
    {
        sql += " ORDER BY Dob";
    }
    if(index1 == 4)
    {
        sql += " ORDER BY Dod";
    }
    if(index1 == 5)
    {
        sql += " ORDER BY ID";
    }
    if(index2 ==1)
    {
        sql += " ASC";
    }
    if(index2 ==2)
    {
        sql += " DESC";
    }
}

void Data::sortQueryCom(string & sql,int index1, int index2)
{
    if(index1 == 1)
    {
        sql += " ORDER BY Name";
    }
    if(index1 == 2)
    {
        sql += " ORDER BY Type";
    }
    if(index1 == 3)
    {
        sql += " ORDER BY Built";
    }
    if(index1 == 4)
    {
        sql += " ORDER BY year";
    }
    if(index1 == 5)
    {
        sql += " ORDER BY ID";
    }
    if(index2 ==1)
    {
        sql += " ASC";
    }
    if(index2 ==2)
    {
        sql += " DESC";
    }
}

void Data::scientistToRestore()
{
    QString qsql;
    string sql = "SELECT * FROM Computerscientists WHERE isActive ='0';";
    qsql = QString::fromStdString(sql);
    CScientist temp;
    fillVector(database, temp, qsql);
}

void Data::computerToRestore()
{
    QString qsql;
    string sql = "SELECT * FROM Computers WHERE isActive ='0';";
    qsql = QString::fromStdString(sql);
    Computer temp;
    fillVector(database, temp, qsql);
}

void Data::relationToRestore()
{
    QString qsql;
    string sql = "SELECT * FROM Relations WHERE isActive ='0';";
    qsql = QString::fromStdString(sql);
    Relation temp;
    fillVector(database, temp, qsql);
}

void Data::updateStatus(CScientist cSci)
{
    QString qsql;
    string sql;
    int id = cSci.getId();
    stringstream ss;
    ss << id;
    string SciId = ss.str();
    if(cSci.getIsActive() == 1)
    {
        sql = "UPDATE Computerscientists SET isActive=0 WHERE ID =  " +SciId;
    }
    else
    {
        sql = "UPDATE Computerscientists SET isActive=1 WHERE ID =  " +SciId;
    }
    qsql = QString::fromStdString(sql);
    fillVector(database, cSci, qsql);
}

void Data::updateStatus(Computer comp)
{
    QString qsql;
    string sql;
    int id = comp.getId();
    stringstream ss;
    ss << id;
    string ComId = ss.str();
    if(comp.getIsActive() == 1)
    {
        sql = "UPDATE Computers SET isActive=0 WHERE ID = " +ComId;
    }
    else
    {
        sql = "UPDATE Computers SET isActive=1 WHERE ID = " +ComId;
    }
    qsql = QString::fromStdString(sql);
    fillVector(database, comp, qsql);
}

void Data::insert(CScientist cSci)
{
    QString qsql;
    string deathstatus;
    if(cSci.getDod().length()==0)
    {
     deathstatus = "Alive";
    }
    else
    {
     deathstatus = cSci.getDod();
    }
    string sql = "INSERT INTO Computerscientists (Name, Gender, Dob, Dod) VALUES ('"+ cSci.getName() +"','"+ cSci.getGender() +"','"+ cSci.getDob() +"','"+deathstatus+"')";
    qsql = QString::fromStdString(sql);
    fillVector(database, cSci, qsql);
}

void Data::insert(Computer comp)
{
    QString qsql;
    string sql = "INSERT INTO Computers (Name, Type, Built, Year) VALUES ('"+ comp.getName() +"','"+ comp.getType() +"','"+ comp.getBuilt() + "','"+ comp.getYear() + "')";
    qsql = QString::fromStdString(sql);
    fillVector(database, comp, qsql);
}

void Data::update(CScientist cSci)
{
    QString qsql;
    string sql = "UPDATE Computerscientist SET ";
    if(!cSci.getName().empty())
    {
        sql += "name ='" + cSci.getName() + "%' AND ";
    }

    if(!cSci.getGender().empty())
    {
        sql += "gender='" + cSci.getGender() + "%' ";
    }

    if(!cSci.getDob().empty())
    {
        sql += "AND dob='" + cSci.getDob() + "'";
    }

    if(!cSci.getDod().empty())
    {
        sql += "AND dod='" + cSci.getDod() + "'";
    }
    if (sql.size () > 0)  sql.resize (sql.size () - 5);
    sql += ";";
    qsql = QString::fromStdString(sql);
    fillVector(database, cSci, qsql);
}

void Data::update(Computer comp)
{
    QString qsql;
    string sql = "UPDATE Computers SET ";
    if(!comp.getName().empty())
    {
        sql += "name ='" + comp.getName() + "%' AND ";
    }

    if(!comp.getYear().empty())
    {
        sql += "year='" + comp.getYear() + "' AND ";

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

void Data::setRelations(Computer comp, CScientist cSci)
{
    QString qsql;
    string sql = "INSERT INTO sciectists_computers (scientistID, computerID, isActive) VALUES (" + to_string(cSci.getId()) + "," + to_string(comp.getId()) + ",1);";
    qsql = QString::fromStdString(sql);
    QSqlQuery query;
    query.exec(qsql);
    fillVector(database, cSci, qsql);
}
