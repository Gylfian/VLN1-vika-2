#include "presentation.h"
#include "data.h"


int main()
{
    //Presentation Interface;
    //Interface.mainPage();
    Data d1;
    CScientist sci;
    d1.setDatabase();
    QString command = "SELECT * FROM Computerscientists";
    QSqlDatabase db = d1.getDatabase();
    d1.fillVector(db, sci, command);
    return 0;
}

