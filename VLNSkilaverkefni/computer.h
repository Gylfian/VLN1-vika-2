#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>
using namespace std;

class Computer
{
public:
    Computer();
    Computer(int cId,string cName, string cYear, string cType, bool cBuilt);
    int getId() const;
    string getName() const;
    string getYear() const;
    string getType() const;
    bool getBuilt() const;
    void setName(string nameToSet);
    void setYear(string yearToSet);
    void setType(string typeToSet);
    void setBuilt(bool cBuilt);
private:
    int Id;
    string name;
    string yearBuilt;
    string type;
    bool built;
};

#endif // COMPUTER_H
