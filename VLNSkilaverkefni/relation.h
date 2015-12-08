#ifndef RELATION_H
#define RELATION_H
#include <iostream>
#include "computerscientist.h"
#include "computer.h"

class Relation
{
public:
    Relation();
    Relation(Computer computerToSet, CScientist scientistToSet);
    Computer getComputer();
    CScientist getScientist();
    void setComputer(Computer computerToSet);
    void setScientist(CScientist scientistToSet);
    void setComputerId(unsigned int computerIdToSet);
    void setScientistId(unsigned int scientistIdToSet);

private:
    Computer computer;
    CScientist scientist;
};

#endif // RELATION_H
