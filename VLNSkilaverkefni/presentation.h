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

    /*
     * Name: mainPage
     * Parameter/s: None
     * Description: Displays menu of options for the user to pick from and calls another function which gets choice from user
     * Usage: mainpage();
     * Output/Return:Displays a menu of options for the user to pick from
     */
    void mainPage();

private:

    /*
     * Name: addScientist
     * Parameter/s: None
     * Description: Adds scientists to a vector and sends them to the domain layer
     * Usage: addScientist();
     * Output/Return: Gets scientists and sends them down to domiain
     */
     void addScientist();

    /*
     * Name: options
     * Parameter/s: None
     * Description: Gets choice from the user and calls an appropriate function based on user choice
     * Usage: options();
     * Output/Return: Calls an appropriate function
     */
     void options();

    /*
     * Name: another
     * Parameter/s: None
     * Description: Calls a function that displays a menu to the user, gets user choice and returns true or false
     * Usage: while(another());
     * (bool)Output/Return: true or false depending on user choice
     */
     bool another(string word);

    /*
     * Name: listOptions
     * Parameter/s: None
     * Description: Calls a function that displays a menu to the user and sends his choice into a function that's used to display the list
     * Usage: listoptions();
     * Output/Return: Sends user choice into the function whichOrder()
     */
     void listOptions();

     /*
      * Name: printListText
      * Parameter/s: None
      * Description: Displays a list of options to the user, delete or search for an entry
      * Usage: printListText();
      * Output/Return: Displays the menu
      */
     void printListText();

     /*
      * Name: deleteFromList
      * Parameter/s: None
      * Description: Gets info from user about wich scientist to delete. Calls appropriate in domain layer wich deletes the scientist from the list
      * Usage: listoptions();
      * Output/Return: Sends user choice into the function whichOrder()
      */
     void deleteFromList();

     /*
      * Name: whichOrder
      * Parameter/s: char pChoice
      * Description: Calls an appropriate function depending on user choice to display a menu, then gets user input and calls functions
      * to sort and print the list
      * Usage: whichOrder(1);
      * Output/Return: Calls functions that sort and print the list
      */
      void whichOrder(char pChoice);

     /*
      * Name: scientistData
      * Parameter/s: none
      * Description: Calls functions that get user input and calls functions that put that input into member variables of the Scientist variable
      * Usage: scientistData(c1);
      * Output/Return: Returns the scientist variable with changed member variables
      */
      CScientist getScientistData();

     /*
      * Name: getInputGender
      * Parameter/s: none
      * Description: Prompts the user and gets his choice of gender
      * Usage: string s1=getInputGender();
      * (string)Output/Return: Returns a string containing "Male" or "Female
      */
      string getInputGender();

     /*
      * Name: getInputName
      * Parameter/s: none
      * Description: Prompts the user and gets his Name input then calls a function to normalize the name
      * Usage: string s1=getInputName();
      * (string)Output/Return: Returns a normalized string containing the scientist's name
      */
      string getInputName();

     /*
      * Name: getInputDob
      * Parameter/s: none
      * Description: Prompts the user and gets his birthyear input
      * Usage: string s1=getInputDob();
      * (string)Output/Return: Returns a string containing the scientist's birthyear
      */
      string getInputDob();

     /*
      * Name: getInputDod
      * Parameter/s: none
      * Description: Prompts the user and gets his deathyear input
      * Usage: string s1=getInputDod();
      * (string)Output/Return: Returns a string containing the scientist's year of death
      */
      string getInputDod();

     /*
      * Name: printList
      * Parameter/s: vector <CScientist> scientists
      * Description: Prints the list of scientist , prints a menu for the user and calls the function printListOptions() to get his choice
      * Usage: printList(vector <CScientist> scientists);
      * Output/Return: Prints the list of scientists and displays a menu
      */
      void printList(vector <CScientist> scientists);

     /*
      * Name: printListOptions
      * Parameter/s: none
      * Description: Gets the user's choice and calls and appropriate function
      * Usage: printListOptions();
      * Output/Return: Calls an appropriate function
      */
      void printListOptions();
     /*
      * Name: searchoptions
      * Parameter/s: none
      * Description: Displays a menu and calls an appropriate function based on user choice
      * Usage: searchOptions();
      * Output/Return: Calls an appropriate function
      */
      void searchOptions();

     /*
      * Name: getNameSearch
      * Parameter/s: none
      * Description: Prompts the user about which name to search for and gets the input
      * Usage: string s1=getNameSearch();
      * (string)Output/Return: The string containing the name
      */
      string getNameSearch();

     /*
      * Name: getGenderSearch
      * Parameter/s: none
      * Description: Displays a menu and gets choice from user about which gender to search for
      * Usage: string s1=getGenderSearch();
      * (string)Output/Return: A string containing "Male" or "Female"
      */
      string getGenderSearch();

     /*
      * Name: getYearSearch
      * Parameter/s: none
      * Description: Prompts the user about which year to search for and gets the input
      * Usage: string s1=getYearSearch();
      * (string)Output/Return: A string containing the year
      */
      string getYearSearch();

     /*
      * Name: anotherText
      * Parameter/s: none
      * Description: Tells the user a person has been added and asks if the user wants to add another one
      * Usage: anotherText();
      * Output/Return: none
      */
      void anotherText(string word);

     /*
      * Name: listOptionsText
      * Parameter/s: none
      * Description: Displays a list of options to the user, asking in what order he wants his persons displayed
      * Usage: listOptionsText();
      * Output/Return: none
      */
      void listOptionsText();

     /*
      * Name: genderOrderText
      * Parameter/s: none
      * Description: Displays a list of options to the user, asking which gender he wants displayed first
      * Usage: genderOrderText();
      * Output/Return: none
      */
      void genderOrderText();

     /*
      * Name: yearBornText
      * Parameter/s: none
      * Description: Displays a list of options to the user, asking if he wants younger or older persons displayed first
      * Usage: yearBornText();
      * Output/Return: none
      */
      void yearBornText();

     /*
      * Name: ascendingDecendingText
      * Parameter/s: none
      * Description: Displays a list of options to the user, asking if he wants the list displayed in ascending or descending order
      * Usage: ascendingDecendingText();
      * Output/Return: none
      */
      void ascendingDecendingText();
      void sciOrCom();
      void addComputer();
      Computer getComputerData();
      string getComName();
      string getComYear();
      string getComType();
      bool getComBuilt();
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
      bool getSearchBuilt();
};

#endif // PRESENTATION_H
