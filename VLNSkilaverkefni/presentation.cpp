#include "presentation.h"

void Presentation::mainPage()
{
    cout << " ___________MAIN_MENU_________" << endl;
    cout << "|---What do you want to do?---|" << endl;
    cout << "|-1) Display lists------------|" << endl;
    cout << "|-2) Search lists-------------|" << endl;
    cout << "|-3) Add to lists-------------|" << endl;
    cout << "|-4) Delete from lists--------|" << endl;
    cout << "|-5) Edit the lists-----------|" << endl;
    cout << "|-6) Restore deleted entries--|" << endl;
    cout << "|-Press any other key to quit-|" << endl;
    cout << "|_____________________________|" << endl;
    options();
}

void Presentation::options()
{
    char ans = getch();
    system("CLS");

    switch (ans)
    {
        case ('1'):
        {
            sciOrComText(ans);
            printSciOrCom();
        }break;
        case ('2'):
        {
            sciOrComText(ans);
            searchSciOrCom();
        }break;
        case ('3'):
        {
            sciOrComText(ans);
            addSciOrCom();
        }break;
        case ('4'):
        {
            sciOrComText(ans);
            deleteSciOrCom();
        }break;
        case ('5'):
        {
            sciOrComText(ans);
            editSciOrCom();
        }break;
        case ('6'):
        {
            sciOrComText(ans);
            restoreSciOrCom();
        }break;
        default:
           exit(1);
    }
}

void Presentation::restoreSciOrCom()
{
    char ans = getch();
    system ("CLS");

    switch (ans)
    {
        case ('1'):
        {
            restoreSci();
        }break;
        case ('2'):
        {
            restoreCom();
        }break;
        case ('3'):
        {
            restoreConnection();
        }break;
        default:
            mainPage();
    }
}

void Presentation::restoreSci()
{
    vector<CScientist> scientists;
    dom.restoreEntry(scientists);
    if (scientists.empty())
    {
        restoreFail();
    }
    else
    {
        printSciList(scientists);
        string id = getListId("scientist", "restore");
        if (dom.checkIfLegitId(id))
        {
            dom.updateEntrySci(id);
        }
        else
        mainPage();
    }
}

void Presentation::restoreCom()
{
    vector<Computer> computers;
    dom.restoreEntry(computers);
    if (computers.empty())
    {
          restoreFail();
    }
    else
    {
        printComList(computers);
        string id = getListId("computer", "restore");
        if (dom.checkIfLegitId(id))
        {
            dom.updateEntrySci(id);
        }
        else
        mainPage();
    }
}

void Presentation::restoreFail()
{
    cout << "No entries to restore!" << endl;
    cout << "Press any key to go to the main menu" << endl;
    char ans = getch();
    system ("CLS");
    mainPage();
}

void Presentation::restoreConnection()
{

}

void Presentation::printSciOrCom()
{
    char ans = getch();
    system("CLS");

    switch (ans)
    {
        case ('1'):
        {
            listOptions(ans);
        }break;
        case ('2'):
        {
            listOptions(ans);
        }break;
        case ('3'):
        {

        }break;
        default:
            mainPage();
    }
}

void Presentation::addSciOrCom()
{
    char ans = getch();
    system("CLS");

    switch (ans)
    {
        case('1'):
        {
            addScientist();
        }break;
        case('2'):
        {
            addComputer();
        }break;
        case('3'):
        {
            addConnection();
        }break;
        default:
            mainPage();
    }
}

void Presentation::addConnection()
{
    vector<CScientist> scientists;
    vector<Computer> computers;
    dom.sortBy(scientists,'5','1');
    dom.sortBy(computers, '5','1');

    printSciList(scientists);
    string sci = getNum("scientist/s","computer/s");
    printComList(computers);
    string com = getNum("computer/s", "scientist/s");

    //dom.addRelation(sci, com);
}

string Presentation::getNum(string word1, string word2)
{
    string ids;
    cout << "Enter the ID's of the " << word1 << " you wish to connect to the " <<  word2 << endl;
    cout << "Seperate entries with a comma" << endl;
    cout << "ID's: ";
    getline (cin, ids);
    return ids;
}

void Presentation::searchSciOrCom()
{
    char ans = getch();
    system("CLS");

    switch(ans)
    {
        case('1'):
        {
            searchSci();
        }break;
        case('2'):
        {
            searchCom();
        }break;
        default:
            mainPage();
    }
}

void Presentation::searchSci()
{
    system("CLS");
    string name, gender, Dob, Dod;
    int id = getSearchId();

    if (id == -1)
    {
        name = getSearchName();
        gender = getSearchGender();
        cout << "Enter year of birth: ";
        getline(cin, Dob);
        string alive = getSearchAlive();

        if (alive == "No")
        {
            cout << "Enter year of death: ";
            getline(cin, Dod);
        }
        else if (alive == "Yes")
        {
            Dod = "Alive";
        }
        else
        {
            Dod = "";

        }
    }
    else
    {
        name = "";
        gender = "";
        Dob = "";
        Dod = "";
    }
    CScientist cSci(id, name, gender, Dob, Dod, 1);
    vector <CScientist> scientists;
    dom.search(scientists, cSci);
    if (!scientists.empty())
    {
        printSciList(scientists);
        printListOptions();
    }
    else
    {
        system("CLS");
        cout << "Sorry nothing was found" << endl;
        printListOptions();
    }
}

void Presentation::editSciOrCom()
{
    char ans = getch();
    system ("CLS");

    switch (ans)
    {
        case ('1'):
        {
            editSci();
        }break;
        case ('2'):
        {
            editCom();
        }break;
        default:
            mainPage();
    }
}

void Presentation::editSci()
{
    vector<CScientist> scientists;
    dom.sortBy(scientists, '5','1');
    printSciList(scientists);
    string id = getListId("scientist", "edit");
}

void Presentation::editCom()
{
    vector<Computer> computers;
    dom.sortBy(computers, '5','1');
    printComList(computers);
    string id = getListId("computer", "edit");
}

string Presentation::getSearchName()
{
    string name;
    cout << "Enter name: ";
    getline(cin, name);
    return name;
}

string Presentation::getSearchGender()
{
    string gender;
    cout << "Is the scientist [m]ale or [f]emale or [u]nknown " << endl;
    char ans = getch();
        switch (ans)
        {
        case ('M'):
        case ('m'):
        {
            gender = "Male";
            cout << gender << " selected" << endl;
        }break;
        case ('F'):
        case ('f'):
        {
        gender = "Female";
        cout << gender << " selected" << endl;
        }break;
        case ('U'):
        case ('u'):
        {
            gender = "";
            cout << "Unknown selected" << endl;
        }break;
        default:
            cout << "Please select a valid option!" << endl;
            gender = getSearchGender();
        }
        return gender;
}

int Presentation::getSearchId()
{
    string id;
    cout << "Enter ID: ";
    getline(cin,id);
    int ans = dom.checkStrInput(id);

    return ans;
}

string Presentation::getSearchAlive()
{
    string alive;
    cout << "Is the person alive? [y]es, [n]o, [u]nknown" << endl;
    char ans = getch();

    switch (ans)
    {
        case ('Y'):
        case ('y'):
        {
            alive = "Yes";
        }break;
        case ('N'):
        case ('n'):
        {
            alive = "No";
        }break;
        case ('U'):
        case ('u'):
        {
            alive = "";
        }break;
        default:
            cout << "Please select a valid option!" << endl;
            alive = getSearchAlive();
    }

    return alive;
}

void Presentation::searchCom()
{
    system("CLS");
    string name, type, year, built;
    int id = getSearchId();
    if (id == -1)
    {
        name = getSearchName();
        cout << "Enter type: ";
        getline(cin,type);
        built = getSearchBuilt();
        if (built == "Yes")
        {
            cout << "Enter the year the computer was built: ";
            getline(cin, name);
        }
        else
        {
            year = "";
        }
    }
    else
    {
        name = "";
        type = "";
        built = "";
    }
    Computer com(id, name, year, type, built);
    vector<Computer> computers;
    dom.search(computers,com);
    printComList(computers);
    printListOptions();
}

string Presentation::getSearchBuilt()
{
    string built;
    cout << "Was the computer built? [y]es, [n]o, [u]nknown" << endl;
    char ans = getch();

    switch (ans)
    {
        case('Y'):
        case('y'):
        {
            built = "Yes";
        }break;
        case('N'):
        case('n'):
        {
            built = "No";
        }break;
        case('U'):
        case('u'):
        {
            built = "";
        }break;
        default:
            cout << "Please enter a valid option!" << endl;
            built = getSearchBuilt();
    }

    return built;
}

void Presentation::deleteSciOrCom()
{
    char ans = getch();
    system ("CLS");

    switch (ans)
    {
        case ('1'):
        {
            deleteSci();
        }break;
        case ('2'):
        {
            deleteCom();
        }break;
        default:
            mainPage();
    }
}

void Presentation::deleteSci()
{
    vector<CScientist> scientists;
    dom.sortBy(scientists, '5','1');
    printSciList(scientists);
    string id = getListId("scientist", "delete");
    if (dom.checkIfLegitId(id))
    {
        dom.updateEntrySci(id);
    }
    else
    mainPage();
}

void Presentation::deleteCom()
{
    vector<Computer> computers;
    dom.sortBy(computers, '5','1');
    printComList(computers);
    string id = getListId("computer", "delete");
    if (dom.checkIfLegitId(id))
    {
        dom.updateEntryCom(id);
    }
    else
    mainPage();
}

string Presentation::getListId(string word1, string word2)
{
    string id;
    cout << "Enter the ID of the " << word1 << " you wish to " << word2 << endl;
    cout << "Press return to cancel" << endl;
    cout << "ID: ";
    getline (cin,id);
    return id;
}

void Presentation::addScientist()
{
    CScientist cSci;
    do
    {
        system("CLS");
        cSci = getScientistData();
        dom.addEntry(cSci);

    }while(another("--Person"));
    system("CLS");
    mainPage();
}

void Presentation::addComputer()
{
    Computer com;

    do
    {
        system("CLS");
        com = getComputerData();
        dom.addEntry(com);

    }while(another("Computer"));
    system("CLS");
    mainPage();
}

CScientist Presentation::getScientistData()
{
    string name, gender, Dob, Dod;
    name = getInputName();
    gender = getInputGender();
    Dob = getInputDob();
    bool alive = getInputAlive();
    if(!alive)
    {
        Dod = getInputDod(Dob);
    }
    else
    {
        Dod = "";
    }

    CScientist cSci(0,name, gender, Dob, Dod, 1);
    return cSci;
}

string Presentation::getInputGender()
{
    string gender;
    cout << "Is the scientist [m]ale or [f]emale ? " << endl;
    char ans = getch();
    switch (ans)
    {
        case ('M'):
        case ('m'):
        {
            gender = "Male";
            cout << gender << " selected" << endl;
        }break;
        case ('F'):
        case ('f'):
        {
        gender = "Female";
        cout << gender << " selected" << endl;
        }break;
        default:
        {
            cout << "Please select either male or female"<<endl;
            gender = getInputGender();
        }
    }
    return gender;
}

string Presentation::getInputName()
{
    string name;
    bool namecheck = false;
    cout << "Enter name: ";
    while(namecheck==false)
    {
        getline(cin,name);
        namecheck = dom.normalizeName(name);
    }
    return name;
}

string Presentation::getInputDob()
{
    string Dob = "";
    cout << "Enter year of birth: ";
    cin >> Dob;

    if(dom.verifyBirthyear(Dob))
    {
        return Dob;
    }
    else
    {
        cout << "Please enter a valid birth year!" << endl;
        Dob = getInputDob();
    }
    return "";
}

string Presentation::getInputDod(string Dob)
{
    string Dod;
    cout << "Enter year of death: ";
    cin >> Dod; 
    bool valid = dom.normalizeYear(Dob, Dod);
    if(valid == false)
    {
        cout << "Please select a valid death year!" << endl;
        Dod = getInputDod(Dob);
    }
    return Dod;
}

bool Presentation::getInputAlive()
{
    char ans;
    bool alive;
    cout << "Is the person alive? (y/n)" << endl;
    ans = getch();

    switch (ans)
    {
        case ('Y'):
        case ('y'):
        {
            alive = true;
        }break;
        case ('N'):
        case ('n'):
        {
            alive = false;
        }break;
        default:
            cout << "Please select a valid option!" << endl;
            alive = getInputAlive();
    }
    return alive;
}

Computer Presentation::getComputerData()
{
    string name = getComName();
    string type = getComType();
    string built = getComBuilt();
    string year;
    if(built == "Yes")
    {
        year = getComYear();
    }
    else
    {
        year = "";
    }
    Computer com(0, name, year, type, built);
    return com;
}

string Presentation::getComName()
{
    string name;
    cout << "Enter the name of the computer: ";
    cin >> name;
    return name;
}

string Presentation::getComType()
{
    string type;
    cout << "Enter the type of computer: ";
    cin >> type;
    return type;
}

string Presentation::getComBuilt()
{
    string built;
    cout << "Was the computer built? (y/n)" << endl;
    char ans = getch();

    switch (ans)
    {
        case('y'):
        case('Y'):
        {
            built = "Yes";
        }break;
        case('n'):
        case('N'):
        {
            built = "No";
        }break;
        default:
            cout << "Please enter a valid option!";
            built = getComBuilt();
    }
    return built;
}

string Presentation::getComYear()
{
    string year;
    cout << "Enter the year the computer was built: ";
    cin >> year;
    return year;
}

bool Presentation::another(string word)
{
    anotherText(word);
    char ans = getch();
    switch (ans)
    {
        case ('Y'):
        case ('y'):
            return true;
            break;
        case ('N'):
        case ('n'):
            return false;
            break;
        default:
            return false;
    }
}

void Presentation::listOptions(char which)
{
    listOptionsText(which);

    char ans = getch();
    system("CLS");

    switch(ans)
    {
        case ('1'):
        case ('2'):
        case ('3'):
        case ('4'):
        case ('5'):
        {
            if (which == '1')
            {
                whichOrderSci(which, ans);
            }
            else
            {
                whichOrderCom(which, ans);
            }
        }break;
        default:
            sciOrComText('1');
            printSciOrCom();
    }
}

void Presentation::whichOrderSci(char which, char pChoice)
{

    switch (pChoice)
    {
        case ('1'):
        case ('5'):
        {
            ascendingDecendingText();
        }break;
        case('2'):
        {
            genderOrderText();
        }break;
        case('3'):
        {
            yearBornText();
        }break;
        case ('4'):
        {
            yearDeathText();
        }break;
    }

    char ans = getch();
    system("CLS");

    vector<CScientist> scientists;

    switch (ans)
    {
        case ('1'):
        case ('2'):
        {
            dom.sortBy(scientists, pChoice, ans);
        }break;
        default:
            listOptions(which);
    }

    printSciList(scientists);
    printListOptions();
}

void Presentation::whichOrderCom(char which, char pChoice)
{
    switch(pChoice)
    {
        case ('1'):
        case ('2'):
        case ('5'):
        {
            ascendingDecendingText();
        }break;
        case ('3'):
        {
            ifBuiltText();
        }break;
        case('4'):
        {
            buildYearText();
        }break;
    }

    char ans = getch();
    system("CLS");

    vector <Computer> computers;
    computers.clear();
    switch (ans)
    {
        case ('1'):
        case ('2'):
        {
            dom.sortBy(computers , pChoice, ans);
        }break;
        default:
            listOptions(which);
    }

    printComList(computers);
    printListOptions();
}

void Presentation::printSciList(vector<CScientist> scientists)
{
    int longest = dom.findLongestName(scientists);
    cout << "Computer scientists" << endl;
    cout << setfill('-') << setw(longest + 36) << '-' << endl;
    cout << setfill(' ') << left << setw(longest +6) << "ID | Name"
    << "|Gender |Birth Year" << "|Death Year" << endl;
    cout << setfill('-') << setw(longest + 36) << '-' << endl;
    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        cout << setfill(' ') << right << setw(3) << scientists[i].getId() << "| " << left << setw(longest+2)
        << scientists[i].getName() << setw(8) << scientists[i].getGender() << setw(11) << scientists[i].getDob()
        << scientists[i].getDod() << endl;
        cout << setfill('-') << setw(longest + 36) << '-' << endl;
    }
}

void Presentation::printComList(vector<Computer> computers)
{
    int longest = dom.findLongestName(computers);
    int longestType = dom.findLongestType(computers);
    cout << "Computers" << endl;
    cout << setfill('-') << setw(longest + longestType + 27) << '-' << endl;
    cout << setfill(' ') << left << setw(longest + 6) << "ID | Name"
    << setw(longestType + 3) << "|Type " << "|Built |Year Built" << endl;
    cout << setfill('-') << setw(longest + longestType + 27) << '-' << endl;
    for(unsigned int i = 0; i < computers.size(); i++)
    {
        cout << setfill(' ') << right << setw(3) << computers[i].getId() << "| " << left << setw(longest + 2)
        << computers[i].getName() << setw(longestType + 3) << computers[i].getType ()
        << setw(7) << computers[i].getBuilt() << computers[i].getYear() << endl;
        cout << setfill('-') << setw(longest + longestType + 27) << '-' << endl;
    }
}

void Presentation::printListOptions()
{
    printListText();

    char ans = getch();

    switch(ans)
    {
        case ('1'):
        {
            analyze();
        }break;
        case ('2'):
        {

        }break;
        default:
            system("CLS");
            mainPage();
    }
}

void Presentation::analyze()
{
    cout << "Enter the ID of the entry you wish to analyze" << endl;
    cout << "ID: ";
    string id;
    getline(cin, id);
}

void Presentation::printListText()
{
    cout << " ____________________________________________ " << endl;
    cout << "|----------What do you want to do ?----------|" << endl;
    cout << "|-1) Analyse a specific entry----------------|" << endl;
    cout << "|-2) Blabeebliblu----------------------------|" << endl;
    cout << "|-Press any other key to go to the main menu-|" << endl;
    cout << "|____________________________________________|" << endl;
}

void Presentation::anotherText(string word)
{
    cout << "---------" << word << " added-----------" << endl;
    cout << "Do you wish to add another ? (y/n)" << endl;
}

void Presentation::listOptionsText(char which)
{
    if (which == '1')
    {
        cout << " _____________________________________" << endl;
        cout << "|-How do you want the list displayed?-|" << endl;
        cout << "|-1) Alphabetically-------------------|" << endl;
        cout << "|-2) By gender------------------------|" << endl;
        cout << "|-3) By year of birth-----------------|" << endl;
        cout << "|-4) By year of death-----------------|" << endl;
        cout << "|-5) By ID----------------------------|" << endl;
        cout << "|-Press any other key to go back------|" << endl;
        cout << "|_____________________________________|" << endl;
    }
    else
    {
        cout << " _____________________________________" << endl;
        cout << "|-How do you want the list displayed?-|" << endl;
        cout << "|-1) Alphabetically-------------------|" << endl;
        cout << "|-2) By type--------------------------|" << endl;
        cout << "|-3) If built-------------------------|" << endl;
        cout << "|-4) By build year--------------------|" << endl;
        cout << "|-5) By ID----------------------------|" << endl;
        cout << "|-Press any other key to go back------|" << endl;
        cout << "|_____________________________________|" << endl;
    }
}

void Presentation::ascendingDecendingText()
{
    cout << " _____________________________________" << endl;
    cout << "|-In what order do you want the list?-|" << endl;
    cout << "|-1) Ascending order------------------|" << endl;
    cout << "|-2) Decending order------------------|" << endl;
    cout << "|-Press any other key to go back------|" << endl;
    cout << "|_____________________________________|" << endl;
}

void Presentation::genderOrderText()
{
    cout << " _____________________________________" << endl;
    cout << "|-In what order do you want the list?-|" << endl;
    cout << "|-1) Female first---------------------|" << endl;
    cout << "|-2) Male first-----------------------|" << endl;
    cout << "|-Press any other key to go back------|" << endl;
    cout << "|_____________________________________|" << endl;
}

void Presentation::yearBornText()
{
    cout << " _____________________________________" << endl;
    cout << "|-In what order do you want the list?-|" << endl;
    cout << "|-1) Oldest first---------------------|" << endl;
    cout << "|-2) Youngest first-------------------|" << endl;
    cout << "|-Press any other key to go back------|" << endl;
    cout << "|_____________________________________|" << endl;
}

void Presentation::yearDeathText()
{
    cout << " _____________________________________" << endl;
    cout << "|-In what order do you want the list?-|" << endl;
    cout << "|-1) First death----------------------|" << endl;
    cout << "|-2) Latest death---------------------|" << endl;
    cout << "|-Press any other key to go back------|" << endl;
    cout << "|_____________________________________|" << endl;
}

void Presentation::ifBuiltText()
{
    cout << " _____________________________________" << endl;
    cout << "|-In what order do you want the list?-|" << endl;
    cout << "|-1) Those not built first------------|" << endl;
    cout << "|-2) Those built first----------------|" << endl;
    cout << "|-Press any other key to go back------|" << endl;
    cout << "|_____________________________________|" << endl;
}

void Presentation::buildYearText()
{
    cout << " _____________________________________" << endl;
    cout << "|-In what order do you want the list?-|" << endl;
    cout << "|-1) Built first----------------------|" << endl;
    cout << "|-2) Built latest---------------------|" << endl;
    cout << "|-Press any other key to go back------|" << endl;
    cout << "|_____________________________________|" << endl;
}

void Presentation::sciOrComText(char which)
{

    cout << " ________________________________________"  << endl;
    switch (which)
    {
        case ('1'):
        {
            cout << "|-Which list do you wish to display?-----|" << endl;
        }break;
        case ('2'):
        {
            cout << "|-Which list fo you wish to search from?-|" << endl;
        }break;
        case ('3'):
        {
            cout << "|-Which list do you wish to add to?------|" << endl;
        }break;
        case ('4'):
        {
            cout << "|-Which list do you wish to delete from?-|" << endl;
        }break;
        case ('5'):
        {
            cout << "|-Which list do you wish to edit?--------|" << endl;
        }break;
        case ('6'):
        {
            cout << "|-Which list do you wish to restore from?|" << endl;
        }break;
    }
    cout << "|-1) Computer Scientists-----------------|" << endl;
    cout << "|-2) Computers---------------------------|" << endl;

    switch (which)
    {
        case ('1'):
        {
            cout << "|-3) Display connections-----------------|" << endl;
        }break;
        case ('3'):
        {
            cout << "|-3) Add a connection--------------------|" << endl;
        }break;
        case ('6'):
        {
            cout << "|-3) A connection------------------------|" << endl;
        }break;
    }
    cout << "|-Press any other key to go back---------|" << endl;
    cout << "|________________________________________|" << endl;
}
