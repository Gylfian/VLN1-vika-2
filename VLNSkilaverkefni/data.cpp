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

bool Data::fillVector(QSqlDatabase db, Computer temp, QString command)
{
    if(!db.isOpen())
    {
        setDatabase();
    }
    QSqlQuery query(db);
    if(!executeQuery(query, command))
    {
        //eitthvad exit
    }
    query.first();
    makeQuery(temp, query);
    com.push_back(temp);
   // cout << "is active: " << query.isActive() << endl;
    while(query.next())
    {
        makeQuery(temp,query);
        com.push_back(temp);
    }
    return true;
}

bool Data::fillVector(QSqlDatabase db, CScientist temp, QString command)
{
    if(!db.isOpen())
    {
        setDatabase();
    }
    QSqlQuery query(db);
    if(!executeQuery(query, command))
    {
        //eitthvad exit
    }
    query.first();
    makeQuery(temp,query);
    sci.push_back(temp);
    while(query.next())
    {
        makeQuery(temp, query);
        sci.push_back(temp);
    }
    return true;
}

bool Data::fillVector(QSqlDatabase db, Relation temp, QString command)
{
    if(!db.isOpen())
    {
        setDatabase();
    }
    QSqlQuery query(db);
    if(!executeQuery(query, command))
    {
        //eitthvad exit
    }
    query.first();
    makeQuery(temp, query);
    rele.push_back(temp);
    //cout << "is active: " << query.isActive() << endl;
    while(query.next())
    {
        makeQuery(temp,query);
        rele.push_back(temp);
    }
    return true;
}

void Data::makeQuery(CScientist& temp, QSqlQuery query)
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

void Data::makeQuery(Computer& temp, QSqlQuery query)
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

void Data::makeQuery(Relation& temp, QSqlQuery query)
{
    int qComp = query.value("ScientistID").toUInt();
    temp.setComputerId(qComp);
    cout << qComp << endl;
    int qSci = query.value("ComputerID").toUInt();
    temp.setScientistId(qSci);
    cout << qSci << endl;
}

void Data::select(CScientist cSci,int index1,int index2)
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
        sql += "isActive=1";
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
    sql += ";";
    qsql = QString::fromStdString(sql);
    fillVector(database, cSci, qsql);
}

void Data::select(Computer comp,int index1,int index2)
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

    sql += "isActive=1";

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
    sql += ";";
    qsql = QString::fromStdString(sql);
    fillVector(database, comp, qsql);
}

void Data::deleteEntry(CScientist cSci)
{
    QString qsql;
    int id = cSci.getId();
    string sql = "UPDATE Computerscientists SET isActive=0 WHERE ID = " +id;
    qsql = QString::fromStdString(sql);
    fillVector(database, cSci, qsql);
}

void Data::deleteEntry(Computer comp)
{
    QString qsql;
    int id = comp.getId();
    string sql = "UPDATE Computer SET isActive=0 WHERE ID = " +id;
    qsql = QString::fromStdString(sql);
    fillVector(database, comp, qsql);
}

void Data::insert(CScientist cSci)
{
    QString qsql;
    string sql = "INSERT INTO Computerscientists (Name, Gender, type, Dob, Dod) VALUES ('"+ cSci.getName() +"','"+ cSci.getGender() +"','"+ cSci.getDob() +"','"+ cSci.getDod() +"')";
    qsql = QString::fromStdString(sql);
    fillVector(database, cSci, qsql);
}

void Data::insert(Computer comp)
{
    QString qsql;
    string sql = "INSERT INTO computers (Name, Type, Built, Year) VALUES ('"+ comp.getName() +"','"+ comp.getType() +"','"+ comp.getBuilt() + "','"+ comp.getYear() + "')";
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

bool Data::executeQuery(QSqlQuery query,QString command)
{
    if (!query.exec(command))
    {
        return false;
    }
    return true;
}

void Data::setRelations(Computer comp, CScientist cSci)
{
    QString qsql;
    string sql; //= "INSERT INTO Relation (ScientistID, ComputerID) VALUES (" + comp.getId() + "," + cSci.getId() + " )";
    qsql = QString::fromStdString(sql);
    QSqlQuery query;
    executeQuery(query,qsql);
    fillVector(database, cSci, qsql);
}
