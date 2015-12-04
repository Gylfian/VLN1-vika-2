#include "presentation.h"

void Presentation::mainPage()
{
    cout << " ________________MAIN_MENU_______________" << endl;
    cout << "|---------What do you want to do?--------|" << endl;
    cout << "|-1) Add computer scientists to the list-|" << endl;
    cout << "|-2) See the list of computer scientists-|" << endl;
    cout << "|-------Press any other key to quit------|" << endl;
    cout << "|________________________________________|" << endl;
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
            addScientist();
        }break;
        case ('2'):
        {
            listOptions();
        }break;
        default:
            exit (1);
    }
}

void Presentation::addScientist()
{
    CScientist cSci;
    vector<CScientist> scientists;

    do
    {
        system("CLS");
        scientistData(cSci);
        scientists.push_back(cSci);

    }while(another());
    Domain dom1;
    dom1.addToFile(scientists);
    system("CLS");
    mainPage();
}

void Presentation::scientistData(CScientist& cSci)
{
    string name, gender, Dob, Dod;
    name = getInputName();
    gender = getInputGender();
    Dob = getInputDob();
    Dod = getInputDod();

    cSci.setName(name);
    cSci.setGender(gender);
    cSci.setDob(Dob);
    cSci.SetDod(Dod);
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
            cout << gender<<" selected"<< endl;
        }break;
        case ('F'):
        case ('f'):
        {
        gender = "Female";
        cout << gender<<" selected"<< endl;
        }break;
        default:{
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

bool Presentation::another()
{
    anotherText();
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
            Domain d1;
            vector<CScientist> scientists = d1.readFile();
            printList(scientists);
            printListText();
            printListOptions();
        }break;
        default:
            mainPage();

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

    Domain d1;
    vector<CScientist> scientists = d1.readFile();
    char ans = getch();
    system("CLS");

    switch (ans)
    {
        case ('1'):
        case ('2'):
        {
            d1.sortBy(scientists, pChoice, ans);
            printList(scientists);
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
    for (size_t i = 0; i < scientists.size(); i++)
    {
        cout << "#" << i+1 << endl;
        cout << "Name: " << scientists[i].getName()  << endl;
        cout << "Gender: " << scientists[i].getGender() << endl;
        cout << "Year of birth: " << scientists[i].getDob() << endl;
        cout << "Year of death: " << scientists[i].getDod() << endl << endl;
    }
}

void Presentation::searchOptions()
{
    cout << " ______________________________________ " << endl;
    cout << "|-How do you want to search the list ?-|" << endl;
    cout << "|-1) By name---------------------------|" << endl;
    cout << "|-2) By gender-------------------------|" << endl;
    cout << "|-3) By birth year---------------------|" << endl;
    cout << "|-4) By death year---------------------|" << endl;
    cout << "|______________________________________|" << endl;

    char ans = getch();
    Domain d1;
    vector <CScientist> searchValue, scientist = d1.readFile();
    string search;

    switch(ans)
    {
        case ('1'):
        {
            search = getNameSearch();


        }break;
        case ('2'):
        {
            search = getGenderSearch();


        }break;
        case ('3'):
        case ('4'):
        {
            search = getYearSearch();



        }break;
        default:
            mainPage();
    }
    if(searchValue.empty())
    {
        system("CLS");
        cout << "That entry does not exist!" << endl;
    }
    else
    {
        d1.sortBy(searchValue,'1','1');
        printList(searchValue);
    }
    printListText();
    printListOptions();
}


void Presentation::deleteFromList()
{
    string name;
    Domain d1;
    vector <CScientist> searchValue, scientist = d1.readFile();
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

string Presentation::getNameSearch()
{
    string name;
    cout << "Enter the name you wish to search for: ";
    getline(cin, name);
    return name;
}

string Presentation::getGenderSearch()
{
    cout << " __________________" << endl;
    cout << "|-1) Male search---|" << endl;
    cout << "|-2) Female search-|" << endl;
    cout << "|__________________|" << endl;

    char ans = getch();
    system("CLS");

    switch (ans)
    {
        case ('1'):
        {
            return "Male";
        }break;
        case ('2'):
        {
            return "Female";
        }break;
        default:
            cout << "Please select a valid option!" << endl;
            return getGenderSearch();
    }
}

string Presentation::getYearSearch()
{
    string search;
    cout << "Enter the year you wish to find: ";
    cin >> search;
    return search;
}

void Presentation::printListOptions()
{
    char ans = getch();
    system("CLS");

    switch(ans)
    {
        case ('1'):
        {
            searchOptions();
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
void Presentation::anotherText()
{
    cout << "-------------Person added--------------" << endl;
    cout << "Do you wish to add another person (y/n)" << endl;
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
