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
        default:
           exit(1);
    }
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

        }break;
        default:
            mainPage();
    }
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
        cout << "Enter year of death: ";
        getline(cin, Dod);
    }
    else
    {
        name = "";
        gender = "";
        Dob = "";
        Dod = "";
    }
    CScientist cSci(id, name, gender, Dob, Dod, 1);
}

void Presentation::editSciOrCom()
{

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

}

void Presentation::addScientist()
{
    CScientist cSci;
    vector<CScientist> scientists;

    do
    {
        system("CLS");
        cSci = getScientistData();
        scientists.push_back(cSci);

    }while(another("--Person"));
    system("CLS");
    mainPage();
}

void Presentation::addComputer()
{
    Computer com;
    vector<Computer> coms;

    do
    {
        system("CLS");
        com = getComputerData();
        coms.push_back(com);

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
    string Dob;
    cout << "Enter year of birth: ";
    cin >> Dob;

    return Dob;


    /*if(dom.verifyBirthyear(Dob))
    {
        return Dob;
    }
    else
    {
        cout << "Please enter a valid birth year!" << endl;
        Dob = getInputDob();
    }
    */


}

string Presentation::getInputDod(string Dob)
{
    string Dod;
    cout << "Enter year of death: ";
    cin >> Dod;
    bool valid = dom.normalizeYear(Dob, Dod);
    if(!valid)
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
    cout << setfill('-') << setw(longest + longestType + 33) << '-' << endl;
    cout << setfill(' ') << left << setw(longest + 6) << "ID | Name" << setw(longestType + 3) << "|Type " << "|Built |Year Built" << endl;
    cout << setfill('-') << setw(longest + longestType + 33) << '-' << endl;
    for(unsigned int i = 0; i < computers.size(); i++)
    {
        cout << setfill(' ') << right << setw(3) << computers[i].getId() << "| " << left << setw(longest + 2)
        << computers[i].getName() << setw(longestType + 3) << computers[i].getType ()
        << setw(7) << computers[i].getBuilt() << computers[i].getYear() << endl;
        cout << setfill('-') << setw(longest + longestType + 33) << '-' << endl;
    }
}

void Presentation::deleteFromList()
{
    string name;
    vector <CScientist> searchValue;
    cout << "Enter the name of the scientist you wish to delete: ";
    getline(cin, name);
    //printList(searchValue);
    int number = 1;
    if(searchValue.empty())
    {
        system("CLS");
        cout << "That entry does not exist!" << endl;
        printListText();
        printListOptions();
    }
    if(searchValue.size() > 1)
    {
        cout << "Insert the number of the person you wish to delete:" << endl;
        cin >> number;
    }

    cout << "Are you sure you wish to delete this person?(y/n) ";
    char ans = getch();
    switch (ans)
    {
        case ('Y'):
        case ('y'):
            break;
        default:
            printListText();
            printListOptions();
            break;
    }
    system("CLS");
    mainPage();
}

void Presentation::printListOptions()
{
    printListText();

    char ans = getch();
    system("CLS");

    switch(ans)
    {
        case ('1'):
        {

        }break;
        case ('2'):
        {
            deleteFromList();
        }break;
        default:
            mainPage();
    }
}

void Presentation::printListText()
{
    cout << " ____________________________________________ " << endl;
    cout << "|----------What do you want to do ?----------|" << endl;
    cout << "|-1) Search the list for a specific entry----|" << endl;
    cout << "|-2) delete an entry ------------------------|" << endl;
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
    cout << "|-1) Male first-----------------------|" << endl;
    cout << "|-2) Female first---------------------|" << endl;
    cout << "|-Press any other key to go back------|" << endl;
    cout << "|_____________________________________|" << endl;
}

void Presentation::yearBornText()
{
    cout << " _____________________________________" << endl;
    cout << "|-In what order do you want the list?-|" << endl;
    cout << "|-1) Youngest first-------------------|" << endl;
    cout << "|-2) Oldest first---------------------|" << endl;
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
    cout << "|-1) Those built first----------------|" << endl;
    cout << "|-2) Those not built first------------|" << endl;
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
            cout << "|-Which list fo you wish to edit?--------|" << endl;
        }break;

    }
    cout << "|-1) Computer Scientists-----------------|" << endl;
    cout << "|-2) Computers---------------------------|" << endl;
    if (which == '3')
    {
        cout << "|-3) Add a connection--------------------|" << endl;
        cout << "|-Press any other key to go back---------|" << endl;
        cout << "|________________________________________|" << endl;
    }else
    {
        cout << "|-Press any other key to go back---------|" << endl;
        cout << "|________________________________________|" << endl;
    }

}
