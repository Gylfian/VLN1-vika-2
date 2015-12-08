#ifndef PRESENTATION_H
#define PRESENTATION_H
#include <conio.h>
#include <iomanip>
#include <cstdlib>
#include "domain.h"

class Presentation
{
public:
    void mainPage();
private:
    Domain dom;

    /*
     * Name: addScientist
     * Parameter/s: None
     * Description:
     * Usage:
     * Output/Return:
     */
    void addScientist();

    /*
     * Name: options
     * Parameter/s: None
     * Description: When the user selects an option.
     * Usage: The user selects an option 3
     * Output/Return: Now the user can add to the list.
     */
    void options();
    bool another(string word);
    void listOptions(char which);
    void printListText();
    void deleteFromList();
    void whichOrderSci(char which, char pChoice);
    CScientist getScientistData();
    string getInputGender();
    string getInputName();
    string getInputDob();
    string getInputDod(string Dob);
    void printListOptions();
    void searchOptions();
    string getNameSearch();
    string getGenderSearch();
    string getYearSearch();
    void anotherText(string word);
    void listOptionsText(char which);
    void genderOrderText();
    void yearBornText();
    void ascendingDecendingText();

    void sciOrCom();
    void addComputer();
    Computer getComputerData();
    string getComName();
    string getComYear();
    string getComType();
    string getComBuilt();
    void sciOrComText(char which);

    /*
     * Name: addSciOrCom
     * Parameter/s: None
     * Description: The user can choose witch list he wants to add to.
     * Usage: User selects number 1
     * Output/Return: Now the user can add a scientist
     */
    void addSciOrCom();

    /*
     * Name: printSciOrCom
     * Parameter/s: None
     * Description: The user can choose what list he wants to print out on the screen
     * Usage: User selects option number 2
     * Output/Return: Now the user can choose how he wants to display the list
     */
    void printSciOrCom();

    /*
     * Name: deleteSciOrCom
     * Parameter/s: None
     * Description: Chooses between deleting a scientist or a computer
     * Usage: The user chooses to delete scientist
     * Output/Return: Now the user can choose what scientist to delete
     */
    void deleteSciOrCom();
    void searchSciOrCom();

    /*
     * Name: searchSci
     * Parameter/s: None
     * Description: Searches in the list
     * Usage: The user inserts the search word or number
     * Output/Return: Finds the scientist
     */
    void searchSci();

    /*
     * Name: searchCom
     * Parameter/s: None
     * Description: Searches in the list
     * Usage: The user inserts the search word or number
     * Output/Return: Finds the computer
     */
    void searchCom();

    /*
     * Name: getSearchId
     * Parameter/s: None
     * Description: Gets the Id the user wants to search
     * Usage: The user enters the Id of the scientist
     * Output/Return: **
     */
    int getSearchId();

    /*
     * Name: getSearchGender
     * Parameter/s: None
     * Description: Gets the gender the user wants to search
     * Usage: The user enters the gender of the scientist
     * Output/Return: gender
     */
    string getSearchGender();

    /*
     * Name: getSearchName
     * Parameter/s: None
     * Description: Gets the name the user wants to search
     * Usage: The user enters a name (Jón)
     * Output/Return: Jón
     */
    string getSearchName();

    /*
     * Name: getSearchBuilt
     * Parameter/s: None
     * Description:  Gets informaition about if the computer was built or not
     * Usage: The user enters if it was built or not
     * Output/Return: Built
     */
    string getSearchBuilt();
    bool getInputAlive();
    void whichOrderCom(char which, char pChoice);
    void yearDeathText();
    void ifBuiltText();
    void buildYearText();

    /*
     * Name: editSciOrCom
     * Parameter/s: None
     * Description: User chooses what he wants to edit.
     * Usage: The user selects option number 2
     * Output/Return: **
     */
    void editSciOrCom();
    void printSciList(vector <CScientist> scientists);
    void printComList(vector <Computer> computers);

    /*
     * Name: addConnection
     * Parameter/s: None
     * Description: Adds connection between a computer and a computer scientist
     * Output/Return: Makes a connection.
     */
    void addConnection();
    string getNum(string word1, string word2);

    /*
     * Name: restoreSciOrCom
     * Parameter/s: None
     * Description: Gives the user an option of what he wants to restore.
     * Usage: The user selects option number 1.
     * Output/Return: Restores sientists.
     */
    void restoreSciOrCom();

    /*
     * Name: restoreSci
     * Parameter/s: None
     * Description: Restores and updates the list
     * Usage: The user chooses a scientist to restore
     * Output/Return: Scientist is restored
     */
    void restoreSci();

    /*
     * Name: restoreCom
     * Parameter/s: None
     * Description: Restores and updates the list
     * Usage: The user chooses a computer to restore
     * Output/Return: Computer is restored
     */
    void restoreCom();

    /*
     * Name:
     * Parameter/s:
     * Description:
     * Usage:
     * Output/Return:
     */
    void restoreConnection();

    /*
     * Name: getSearchAlive
     * Parameter/s: None
     * Description: Gets informaition about if the scientist is alive
     * Usage: The User enters if the scientist is alive or not
     * Output/Return: Scientist is alive
     */
    string getSearchAlive();

    /*
     * Name: deleteSci
     * Parameter/s: None
     * Description: Deletes the scientist from list
     * Usage: Takes in the Id of the scientist and deletes it
     * Output/Return: Prints out the scientist list
     */
    void deleteSci();

    /*
     * Name: deleteCom
     * Parameter/s: None
     * Description: Deletes the computer from list
     * Usage: Takes in the Id of the computer and deletes it
     * Output/Return: Prints out the computer list
     */
    void deleteCom();

    /*
     * Name: getDeleteId
     * Parameter/s: string word
     * Description: Gets the Id that is going to be deleted
     * Usage: The user enters the Id of the computer or scientist that is going to be deleted
     * Output/Return: The Id
     */
    string getDeleteId(string word);
    string getListId(string word1, string word2);
    void analyze();
    void editSci();
    void editCom();
    void textFail();
    void searchText();
    void restoreFail();

};

#endif // PRESENTATION_H
