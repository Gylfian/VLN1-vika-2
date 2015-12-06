#include "relation.h"

Relation::Relation()
{
    computer = "";
    scientist = "";
}

Relation(Computer computerToSet, CScientist scientistToSet)
{
    computer = computerToSet;
    scientist = scientistToSet;
}

Computer getComputer()
{
    return computer;
}

CScientist getScientist()
{
    return scientist;
}

void setComputer(Computer computerToSet)
{
    computer = computerToSet
}

void setScientist(CScientist scientistToSet)
{
    scientist = scientistToSet;
}
