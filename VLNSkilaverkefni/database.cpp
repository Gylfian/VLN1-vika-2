#include "database.h"
#include <QDebug>
#include <QSqlError>

database::database()
{

}

void database::addDatabase()
{
    cout << "Add database function" << endl;
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "VLN1.sqlite";
    db.setDatabaseName(dbName);
    db.open();
    addQuery(db);

}

void database::addQuery(QSqlDatabase db)
{
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
