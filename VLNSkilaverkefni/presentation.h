#ifndef PRESENTATION_H
#define PRESENTATION_H
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <iomanip>
#include "domain.h"

class Presentation
{
public:
    void mainPage();
private:
    Domain dom;
    void addScientist();
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
    void printList(vector <CScientist> scientists);
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
    void addSciOrCom();
    void printSciOrCom();
    void deleteSciOrCom();
    void searchSciOrCom();
    void searchSci();
    void searchCom();
    int getSearchId();
    string getSearchGender();
    string getSearchName();
    string getSearchBuilt();
    bool getInputAlive();
    void whichOrderCom(char which, char pChoice);
    void yearDeathText();
    void ifBuiltText();
    void buildYearText();
};

#endif // PRESENTATION_H
