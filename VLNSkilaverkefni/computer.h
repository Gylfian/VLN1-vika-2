#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>
using namespace std;

class Computer
{
public:
    Computer();
    Computer(int cId,string cName, string cYear, string cType, string cBuilt);
    int getId() const;
    string getName() const;
    string getYear() const;
    string getType() const;
    string getBuilt() const;
    bool getIsActive() const;
    void setId(int idToSet);
    void setName(string nameToSet);
    void setYear(string yearToSet);
    void setType(string typeToSet);
    void setBuilt(string cBuilt);
    void setIsActive(bool cisActive);

private:
    int id;
    string name;
    string yearBuilt;
    string type;
    string built;
    bool isActive;
};

#endif // COMPUTER_H
