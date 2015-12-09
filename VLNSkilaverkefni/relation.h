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
    void setComputerName(string nameToSet);
    void setScientistName(string nameToSet);
    void setId(int idToSet);
    void setIsActive(bool isAcToSet);
private:
    Computer computer;
    CScientist scientist;
    int id;
    bool isActive;
};

#endif // RELATION_H
