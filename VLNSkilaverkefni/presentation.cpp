#include "presentation.h"

string const COMPUTER = "Computer";
string const PERSON = "--Person";

void Presentation::mainPage()
{
    cout << " ___________MAIN_MENU_________" << endl;
    cout << "|---What do you want to do?---|" << endl;
    cout << "|-1) Display lists------------|" << endl;
    cout << "|-2) Search lists-------------|" << endl;
    cout << "|-3) Add to lists-------------|" << endl;
    cout << "|-4) Delete from lists--------|" << endl;
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
        default:
            exit (1);
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
            listOptions();
        }break;
        case ('2'):
        {
            listOptions();
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

    name = getSearchName();
    gender = getSearchGender();
    cout << "Enter year of birth: ";
    getline(cin, Dob);
    cout << "Enter year of death: ";
    getline(cin, Dod);

    CScientist cSci(id, name, gender, Dob, Dod, 1);
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
    Domain d1;
    string id;
    cout << "Enter ID: ";
    getline(cin,id);
    int ans = d1.checkStrInput(id);

    return ans;
}

void Presentation::searchCom()
{
    system("CLS");
    string name, type, year;
    bool built;
    int id = getSearchId();
    if (id != -1)
    {
        name = getSearchName();
        cout << "Enter type: ";
        getline(cin,type);
        built = getSearchBuilt();
        if (built)
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
        built = true;
    }
    Computer com(id, name, year, type, built);
}

bool Presentation::getSearchBuilt()
{
    bool built;
    cout << "Was the computer built? [y]es, [n]o, [d]on't know" << endl;
    char ans = getch();

    switch (ans)
    {
        case('Y'):
        case('y'):
        {
            built = true;
        }break;
        case('N'):
        case('n'):
        {
            built = false;
        }break;
        case('D'):
        case('d'):
        {
            built = true;
        }break;
        default:
            cout << "Please enter a valid option!";
            built = getComBuilt();
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

    }while(another(PERSON));
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

    }while(another(COMPUTER));
    system("CLS");
    mainPage();
}

CScientist Presentation::getScientistData()
{
    string name, gender, Dob, Dod;
    name = getInputName();
    gender = getInputGender();
    Dob = getInputDob();
    Dod = getInputDod();


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
    Domain d1;
    bool namecheck = false;
    cout << "Enter name: ";
    while(namecheck==false)
    {
        getline(cin,name);
        namecheck = d1.normalizeName(name);
    }
    return name;
}

string Presentation::getInputDob()
{
    string Dob;
    cout << "Enter year of birth: ";
    cin >> Dob;
    return Dob;
}

string Presentation::getInputDod()
{
    string Dod;
    cout << "Enter year of death, if the person is alive type \"none\": ";
    cin >> Dod;
    return Dod;
}

Computer Presentation::getComputerData()
{
    string name = getComName();
    string type = getComType();
    bool built = getComBuilt();
    string year;
    if(built)
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

bool Presentation::getComBuilt()
{
    bool built;
    cout << "Was the computer built? (y/n)" << endl;
    char ans = getch();

    switch (ans)
    {
        case('y'):
        case('Y'):
        {
            built = true;
        }break;
        case('n'):
        case('N'):
        {
            built = false;
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

void Presentation::listOptions()
{
    listOptionsText();

    char ans = getch();
    system("CLS");

    switch(ans)
    {
        case ('1'):
        case ('2'):
        case ('3'):
        {
            whichOrder(ans);
        }break;
        case ('4'):
        {
            printListText();
            printListOptions();
        }break;
        default:
            sciOrComText('1');
            printSciOrCom();
    }
}

void Presentation::whichOrder(char pChoice)
{

    switch (pChoice)
    {
        case ('1'):
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
        default:
            listOptions();
    }

    char ans = getch();
    system("CLS");

    switch (ans)
    {
        case ('1'):
        case ('2'):
        {

            printListText();
            printListOptions();

        }break;
        default:
            listOptions();
    }
}

void Presentation::printList(vector<CScientist> scientists)
{
    system("CLS");
    Domain d1;
    int longest = d1.findLongestName(scientists);
    cout << longest << endl;
    cout << "Computer scientists" << endl;
    cout << setfill('-') << setw(longest + 36) << '-' << endl;
    cout << setfill(' ') << left << setw(longest +6) << "ID | Name" << "|Gender |Birth Year" << "|Death Year" << endl;
    cout << setfill('-') << setw(longest + 36) << '-' << endl;

    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        cout << setfill(' ') << right << setw(3) << i+1 << "| " << left << setw(longest+2)
        << scientists[i].getName() << setw(8) << scientists[i].getGender() << setw(11) << scientists[i].getDob()
        << scientists[i].getDod() << endl;
        cout << setfill('-') << setw(longest + 36) << '-' << endl;
    }
}

void Presentation::deleteFromList()
{
    string name;
    Domain d1;
    vector <CScientist> searchValue;
    cout << "Enter the name of the scientist you wish to delete: ";
    getline(cin, name);
    printList(searchValue);
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

void Presentation::listOptionsText()
{
    cout << " _____________________________________" << endl;
    cout << "|-How do you want the list displayed?-|" << endl;
    cout << "|-1) Alphabetically-------------------|" << endl;
    cout << "|-2) By gender------------------------|" << endl;
    cout << "|-3) By year of birth-----------------|" << endl;
    cout << "|-4) Unchanged------------------------|" << endl;
    cout << "|-Press any other key to go back------|" << endl;
    cout << "|_____________________________________|" << endl;
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
