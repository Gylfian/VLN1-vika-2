#include "computerscientist.h"

CScientist::CScientist()
{
    id = -1;
    name = "";
    gender ="";
    dateBorn = "";
    dateDeath = "";
    isActive = false;
}

CScientist::CScientist(int cId, string cName, string cGender, string date1, string date2, bool cIsActive)
{
    id = cId;
    name = cName;
    gender = cGender;
    dateBorn = date1;
    dateDeath = date2;
    isActive = cIsActive;
}

int CScientist::getId() const
{
    return id;
}

string CScientist::getName() const
{
    return name;
}

string CScientist::getGender() const
{
   return gender;
}

string CScientist::getDob() const
{
   return dateBorn;
}

string CScientist::getDod() const
{
   return dateDeath;
}

bool CScientist::getIsActive() const
{
   return isActive;
}

void CScientist::setId(int idToSet)
{
    id=idToSet;
}

void CScientist::setName(string nameToSet)
{
    name=nameToSet;
}

void CScientist::setGender(string genderToSet)
{
    gender=genderToSet;
}

void CScientist::setDob(string dateToSet)
{
    dateBorn=dateToSet;
}

void CScientist::setDod(string dateToSet)
{
    dateDeath=dateToSet;
}

void CScientist::setIsActive(bool isActiveToSet)
{
    isActive=isActiveToSet;
}
