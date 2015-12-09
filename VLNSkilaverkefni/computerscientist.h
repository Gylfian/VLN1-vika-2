#ifndef CSCIENTIST_H
#define CSCIENTIST_H
#include <string>
using namespace std;

class CScientist
{
public:
    CScientist();
    CScientist(int id, string cName, string cGender, string date1, string date2, bool isActive);
    string getName() const;
    int getId() const;
    bool getIsActive() const;
    string getGender() const;
    string getDob() const;
    string getDod() const;
    void setName(string nameToSet);
    void setGender(string genderToSet);
    void setDob(string dateToSet);
    void setDod(string dateToSet);
    void setId(int idToSet);
    void setIsActive(bool isActiveToSet);

private:
    int id;
    string name;
    string gender;
    string dateBorn;
    string dateDeath;
    bool isActive;

};

#endif // CSCIENTIST_H
