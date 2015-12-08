#include "computer.h"

Computer::Computer()
{
    id = -1;
    name = "";
    yearBuilt = "";
    type = "";
    built = "";
}

Computer::Computer(int cId,string cName, string cYear, string cType, string cBuilt)
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

string Computer::getBuilt() const
{
    return built;
}

bool Computer::getIsActive() const
{
    return isActive;
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

void Computer::setBuilt(string cBuilt)
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
