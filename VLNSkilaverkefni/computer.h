#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>
using namespace std;

class Computer
{
public:
    Computer();
    Computer(string cName, string cYear, string cType, bool cBuilt);
    string getName() const;
    string getYear() const;
    string getType() const;
    bool getBuilt() const;
    void setId(int idToSet);
    void setName(string nameToSet);
    void setYear(string yearToSet);
    void setType(string typeToSet);
    void setBuilt(bool cBuilt);
    void setIsActive(bool cisActive);

private:
    int id;
    string name;
    string yearBuilt;
    string type;
    bool built;
    bool isActive;
};

#endif // COMPUTER_H
