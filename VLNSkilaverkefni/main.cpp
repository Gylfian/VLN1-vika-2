#include "presentation.h"
#include "data.h"


int main()
{
    //Presentation Interface;
    //Interface.mainPage();
    Data d1;
    QSqlDatabase db=d1.addDatabase();
    db.open();
    CScientist sci;
    d1.addQuery(db, sci);

    return 0;
}

