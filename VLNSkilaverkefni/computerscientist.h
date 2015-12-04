#ifndef CSCIENTIST_H
#define CSCIENTIST_H
#include <string>
using namespace std;

class CScientist
{
public:

    CScientist();

    /*
     * Name: CScientist
     * Parameter/s: string cName, string cGender, string date1, string date2
     * Description: Constructor for the CScientist class
     * Usage: scientist1(George Bush, Female, 2000, 2015);
     * (int)Output/Return: The scientist is is now resgistered as Gerge Bush, female, born in 2000 and died in 2015
     */
    CScientist(int id, string cName, string cGender, string date1, string date2, bool isActive);

    /*
     * Name: getName
     * Parameter/s: None
     * Description: Returns name of the scientist
     * Usage: cout << scientist.getName();
     * (int)Output/Return: The scientist name is written out to console
     */
    string getName() const;
    int getId() const;
    bool getIsActive() const;

    /*
     * Name: getGender
     * Parameter/s: None
     * Description: Returns gender of the scientist
     * Usage: cout << scientist.getGender();
     * (int)Output/Return: The scientist gender is written out to console
     */
    string getGender() const;

    /*
     * Name: getDob
     * Parameter/s: None
     * Description: Returns bith year of the scientist
     * Usage: cout << scientist.getDob();
     * (int)Output/Return: The scientist bith year is written out to console
     */

    string getDob() const;

    /*
     * Name: getDod
     * Parameter/s: None
     * Description: Returns the scientists' year of death
     * Usage: cout << scientist.getDod();
     * (int)Output/Return: The scientist death year is written out to console
     */
    string getDod() const;

    /*
     * Name: setName
     * Parameter/s: string nameToSet
     * Description: Sets the parameter nameToSet as the scientists' name
     * Usage: scientist1.setName(Charlie Brown);
     * (int)Output/Return: The scientist name is now Charlie Brown
     */
    void setName(string nameToSet);

    /*
     * Name: setGender
     * Parameter/s: string genderToSet
     * Description: Sets the parameter genderToSet as the scientists' gender
     * Usage: scientist1.setGender(Female);
     * (int)Output/Return: The scientist gender os now female
     */
    void setGender(string genderToSet);

    /*
     * Name: setDob
     * Parameter/s: string dateToSet
     * Description: Sets the parameter dateToSet as the scientists' birth year
     * Usage: scientist1.setDob(1992);
     * (int)Output/Return: The scientists' birth year is now 1992
     */
    void setDob(string dateToSet);

    /*
     * Name: setDod
     * Parameter/s: string dateToSet
     * Description: Sets the parameter dateToSet as the scientists' year of death
     * Usage: scientist1.setDod(2015);
     * (int)Output/Return: The scientists' year of death is now 2015
     */
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
