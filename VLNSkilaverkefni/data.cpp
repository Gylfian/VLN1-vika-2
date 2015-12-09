#include "data.h"

Data::Data()
{
    CScientist temp;
    Computer temp2;
    sci.push_back(temp);
    com.push_back(temp2);
    setDatabase();
    QSqlQuery query(database);
}

//QSqlDatabase Data::getDatabase()
//{
//    return database;
//}

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

vector<Relation> Data::getRelVector()
{
    return rel;
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
    //int qComp = query.value("scientistID").toUInt();
    //temp.setComputerId(qComp);
    //int qSci = query.value("computerID").toUInt();
    //temp.setScientistId(qSci);
    string qSci = query.value("SName").toString().toStdString();
    temp.setScientistName(qSci);
    string qComp = query.value("CName").toString().toStdString();
    temp.setComputerName(qComp);
}

void Data::select(CScientist cSci,int index1,int index2)
{
    QString qsql;
    int id = cSci.getId();
    string sciId = convertId(id);
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
    if(cSci.getId() > 0)
    {
        sql += " AND ID= " + sciId;

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
    int id = comp.getId();
    string compId = convertId(id);
    string sql = "SELECT *";
    sql += " FROM Computers WHERE ";
    sql += "Name LIKE '%" + comp.getName() + "%'";
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
    if(comp.getId() > 0)
    {
        sql += " AND ID = " + compId;
    }
    sql += " AND isActive=1";
    sortQueryCom(sql,index1,index2);
    sql += ";";
    qsql = QString::fromStdString(sql);
    fillVector(database, comp, qsql);
}

void Data::select(Relation Rel)
{
    QString qsql;
    string sql = "SELECT Computerscientists.Name as 'SName', Computers.Name as 'CName' FROM Computerscientists INNER JOIN scientists_computers ";
    sql+= "ON Computerscientists.ID = scientists_computers.scientistID ";
    sql+= "INNER JOIN Computers ON Computers.ID = scientists_computers.computerID; ";
    qsql = QString::fromStdString(sql);
    fillVector(database, Rel, qsql);
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
    string sciId = convertId(id);
    if(cSci.getIsActive() == 1)
    {
        sql = "UPDATE Computerscientists SET isActive=0 WHERE ID =  " +sciId;
    }
    else
    {
        sql = "UPDATE Computerscientists SET isActive=1 WHERE ID =  " +sciId;
    }
    qsql = QString::fromStdString(sql);
    fillVector(database, cSci, qsql);
}

void Data::updateStatus(Computer comp)
{
    QString qsql;
    string sql;
    int id = comp.getId();
    string comId = convertId(id);
    if(comp.getIsActive() == 1)
    {
        sql = "UPDATE Computers SET isActive=0 WHERE ID = " +comId;
    }
    else
    {
        sql = "UPDATE Computers SET isActive=1 WHERE ID = " +comId;
    }
    qsql = QString::fromStdString(sql);
    fillVector(database, comp, qsql);
}

void Data::insert(CScientist cSci)
{
    QString qsql;
    string deathStatus;
    if(cSci.getDod().length()==0)
    {
     deathStatus = "Alive";
    }
    else
    {
     deathStatus = cSci.getDod();
    }
    string sql = "INSERT INTO Computerscientists (Name, Gender, Dob, Dod) VALUES ('"+ cSci.getName() +"','"+ cSci.getGender() +"','"+ cSci.getDob() +"','"+deathStatus+"')";
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
    int id = cSci.getId();
    string sciId = convertId(id);
    string sql = "UPDATE Computerscientist SET ID " +sciId;
    if(!cSci.getName().empty())
    {
        sql += ", Name ='" + cSci.getName() + "'";
    }

    if(!cSci.getGender().empty())
    {
        sql += ", Gender='" + cSci.getGender() + "'";
    }

    if(!cSci.getDob().empty())
    {
        sql += ", Dob='" + cSci.getDob() + "'";
    }

    if(!cSci.getDod().empty())
    {
        sql += ", Dod='" + cSci.getDod() + "'";
    }
    sql += " WHERE ID=" + sciId;
    sql += ";";
    qsql = QString::fromStdString(sql);
    fillVector(database, cSci, qsql);
}

void Data::update(Computer comp)
{
    QString qsql;
    int id = comp.getId();
    string comId = convertId(id);
    string sql = "UPDATE Computers SET id " + comId;
    if(!comp.getName().empty())
    {
        sql += " AND name ='" + comp.getName() + "'";
    }
    if(!comp.getYear().empty())
    {
        sql += " AND year='" + comp.getYear() + "'";
    }
    if(!comp.getType().empty())
    {
        sql += " AND type='" + comp.getType() + "'";
    }
    if(!comp.getBuilt().empty())
    {
        sql += " AND built='" + comp.getBuilt() + "'";
    }
    sql += ";";
    qsql = QString::fromStdString(sql);
    fillVector(database, comp, qsql);
}

void Data::setRelations(Computer comp, CScientist cSci)
{
    QString qsql;
    int id = cSci.getId();
    string sciId = convertId(id);
    id = comp.getId();
    string compId = convertId(id);
    string sql = "INSERT INTO scientists_computers (scientistID, computerID, isActive) VALUES (" + sciId + "," + compId + ",1);";
    qsql = QString::fromStdString(sql);
    QSqlQuery query;
    query.exec(qsql);
    fillVector(database, cSci, qsql);
}

string Data::convertId(int id)
{
    stringstream ss;
    ss << id;
    string converted = ss.str();
    return converted;
}
