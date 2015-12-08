#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>
using namespace std;

class Computer
{
public:
    Computer();

    /*
     * Name: Computer
     * Parameter/s: string cName, string cYear, string cType, string cBuilt
     * Description: Constructor for the Computer class
     * Usage: computer1(BINAC, 1949, electronic computer, built);
     * Output/Return: The computer is is now resgistered as BINAC, built in 1949, is a electronic computer and was built.
     */
    Computer(int cId,string cName, string cYear, string cType, string cBuilt);
    int getId() const;

    /*
     * Name: getName
     * Parameter/s: None
     * Description: Returns name of the computer
     * Usage: cout << computer.getName();
     * (int)Output/Return: The computer name is written out to console
     */
    string getName() const;

    /*
     * Name: getYear
     * Parameter/s: None
     * Description: Returns the year that the computer was built
     * Usage: cout << computer.getYear();
     * (int)Output/Return: The computer built year is written out to console
     */
    string getYear() const;

    /*
     * Name: getType
     * Parameter/s: None
     * Description: Returns the type of the computer.
     * Usage: cout << computer.getType();
     * Output/Return: The computer type is written out to console
     */
    string getType() const;

    /*
     * Name: getBuilt
     * Parameter/s: None
     * Description: Returns if the computer was built or not.
     * Usage: cout << computer.getBuilt();
     * Output/Return: The result is written out to console
     */
    string getBuilt() const;
    bool getIsActive() const;
    void setId(int idToSet);

    /*
     * Name: setName
     * Parameter/s: string nameToSet
     * Description: Sets the parameter nameToSet as the computers name
     * Usage: computer1.setName(EDVAC);
     * (int)Output/Return: The computer name is now EDVAC.
     */
    void setName(string nameToSet);

    /*
     * Name: setYear
     * Parameter/s: string yearToSet
     * Description: Sets the parameter yearToSet as the computers built year
     * Usage: computer1.setYear(2001);
     * Output/Return: The computer built year is now 2001.
     */
    void setYear(string yearToSet);

    /*
     * Name: setType
     * Parameter/s: string typeToSet
     * Description: Sets the parameter typeToSet as the computers type
     * Usage: computer1.setType(electronic);
     * Output/Return: The computer type is now electronic
     */
    void setType(string typeToSet);

    /*
     * Name: setBuilt
     * Parameter/s: string cBuilt
     * Description: Sets the parameter cBuilt as the result of if it was built or not
     * Usage: computer1.setBuilt(was built);
     * Output/Return: The computer was built
     */
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
