#include "computer.h"

Computer::Computer()
{
    id = 0;
    name = "";
    yearBuilt = "";
    type = "";
    built = false;
}

Computer::Computer(int cId,string cName, string cYear, string cType, bool cBuilt)
{
    id = cId;
    name = cName;
    yearBuilt = cYear;
    type = cType;
    built = cBuilt;
}

int Computer::getId() const
{
    return id;
}

string Computer::getName() const
{
    return name;
}

string Computer::getYear() const
{
    return yearBuilt;
}

string Computer::getType() const
{
    return type;
}

void Computer::setName(string nameToSet)
{
    name = nameToSet;
}

void Computer::setYear(string yearToSet)
{
    yearBuilt = yearToSet;
}

void Computer::setType(string typeToSet)
{
    type = typeToSet;
}

void Computer::setBuilt(bool cBuilt)
{
    built = cBuilt;
}

void Computer::setIsActive(bool cisActive)
{
    isActive = cisActive;
}

void Computer::setId(int cId)
{
    id = cId;
}
