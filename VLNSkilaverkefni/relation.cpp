#include "relation.h"

Relation::Relation()
{

}

Relation::Relation(Computer computerToSet, CScientist scientistToSet)
{
    computer = computerToSet;
    scientist = scientistToSet;
}

Computer Relation::getComputer()
{
    return computer;
}

CScientist Relation::getScientist()
{
    return scientist;
}

bool Relation::getIsActive()
{
    return isActive;
}

int Relation::getId()
{
    return id;
}

void Relation::setComputerName(string nameToSet)
{
    computer.setName(nameToSet);
}

void Relation::setScientistName(string nameToSet)
{
    scientist.setName(nameToSet);
}

void Relation::setIsActive(bool isAcToSet)
{
    isActive = isAcToSet;
}

void Relation::setId(int idToSet)
{
    id = idToSet;
}
