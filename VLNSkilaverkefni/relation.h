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
    int getId();
    bool getIsActive();
    void setComputer(Computer computerToSet);
    void setScientist(CScientist scientistToSet);
    void setComputerId(unsigned int computerIdToSet);
    void setScientistId(unsigned int scientistIdToSet);
    void setComputerName(string nameToSet);
    void setScientistName(string nameToSet);

private:
    Computer computer;
    CScientist scientist;
    int id;
    bool isActive;
};

#endif // RELATION_H
