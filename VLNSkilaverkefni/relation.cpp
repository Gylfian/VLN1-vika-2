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

void Relation::setComputer(Computer computerToSet)
{
    computer = computerToSet;
}

void Relation::setScientist(CScientist scientistToSet)
{
    scientist = scientistToSet;
}

void Relation::setComputerId(unsigned int computerToSet)
{
    computer.setId(computerToSet);
}

void Relation::setScientistId(unsigned int scientistToSet)
{
    scientist.setId(scientistToSet);
}
void Relation::setComputerName(string nameToSet)
{
    computer.setName(nameToSet);
}
void Relation::setScientistName(string nameToSet)
{
    scientist.setName(nameToSet);
}
