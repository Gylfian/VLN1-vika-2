#include "presentation.h"
#include "data.h"


int main()
{
    //Presentation Interface;
    //Interface.mainPage();
    Data d1;
    QSqlDatabase db=d1.addDatabase();
    db.open();
    vector <CScientist> sci;
    d1.addQuery(db, "SELECT * FROM Computerscientists", sci);

    return 0;
}

