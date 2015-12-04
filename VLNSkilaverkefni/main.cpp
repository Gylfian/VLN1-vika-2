#include "presentation.h"
#include "database.h"

int main()
{
    //Presentation Interface;
    //Interface.mainPage();
    Data d1;
    QSqlDatabase db=d1.addDatabase();
    d1.addQuery(db);

    return 0;
}

