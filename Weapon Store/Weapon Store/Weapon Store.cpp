#include <iostream>
#include <string>

using namespace std;



//-------------------End of global variable initialization---------------------

//---------------------Innitializing the data structures-----------------------
//-------Data for each weapon attachment(e.g. scope, suppressor, bipod)--------
struct ATTACHMENT_DATA
{
    string att_type;//e.g. is it a scope, a flashlight or a suppressor
    string att_position;//e.g. underrail, top rail, side rail, barrel
};


//------------Data structure for each weapon(e.g. M4A1, Scar-L)----------------
//------------------------------Main Structure---------------------------------
struct WEAPON_DATA
{
    int id; 
    string w_name;
    string w_manufacturer;
    int w_manufactureYear;
    float cleanPrice;
    bool w_hasAttachment = false;
    ATTACHMENT_DATA w_attachment;
    float priceWithAttachment;
};

//-----------------------End of structure initialization--------------------------

//---------------------Initialization of global variables-------------------------
WEAPON_DATA Weapons[100];
int weaponCount = 0;
int weaponCountBeforeAddition = 0;
int input = 1;
int globalId = 0;
//----------------------Start of function initializations-------------------------

//---------------Function for inserting the data for the weapons------------------
void insertWeaponData()
{
    WEAPON_DATA weapon[100];//Initialising local array
    int n;
    cout << "How many weapons do you want to insert?" << endl;
    cout << ":"; cin >> n;
    //for, inserting data in local array
    for (int i = 0; i < n; i++)
    {
        cout << "=================================================" << endl;
        weapon[i].id = globalId;
        do
        {
            cout << "Name(text, no spaces): "; cin >> weapon[i].w_name;
        } while (weapon[i].w_name != (string)weapon[i].w_name);
        
        do
        {
            cout << endl << "Manufacturer(text, no spaces): "; cin >> weapon[i].w_manufacturer;
        } while (weapon[i].w_manufacturer !=(string)weapon[i].w_manufacturer);
        
        do
        {
            cout << endl << "Year of Manufacturing(number): "; cin >> weapon[i].w_manufactureYear;
        } while (weapon[i].w_manufactureYear != (int)weapon[i].w_manufactureYear);
        
        do
        {
            cout << endl << "Price(number): "; cin >> weapon[i].cleanPrice;
        } while (weapon[i].cleanPrice!=(float)weapon[i].cleanPrice);
        cout << endl << "Does the weapon have an attachment?(1=true/0=false): "; cin >> weapon[i].w_hasAttachment;
       
        if (weapon[i].w_hasAttachment == true)
        {
            cout << endl << "Type of attachment(text, no spaces): "; cin >> weapon[i].w_attachment.att_type;
            cout << endl << "Attachment position(text, no spaces): "; cin >> weapon[i].w_attachment.att_position;
            cout << endl << "Price of weapon with the attachments: "; cin >> weapon[i].priceWithAttachment;
        }
        weaponCount++;
        globalId++;
    }
    //for, transferring data from the local array to the global one
    for (int i = weaponCountBeforeAddition; i < (n + weaponCount); i++)
    {
        Weapons[i].id = weapon[i].id;
        Weapons[i].w_name = weapon[i].w_name;
        Weapons[i].w_manufacturer = weapon[i].w_manufacturer;
        Weapons[i].w_manufactureYear = weapon[i].w_manufactureYear;
        Weapons[i].cleanPrice= weapon[i].cleanPrice;
        Weapons[i].w_hasAttachment = weapon[i].w_hasAttachment;
        if (weapon[i].w_hasAttachment == true)
        {
            Weapons[i].w_attachment.att_type = weapon[i].w_attachment.att_type;
            Weapons[i].w_attachment.att_position = weapon[i].w_attachment.att_position;
            Weapons[i].priceWithAttachment = weapon[i].priceWithAttachment;
        }
    }
    weaponCountBeforeAddition = weaponCount;
}

//--------------------Function for displaying all the weapons---------------------
void displayWeapons()
{    
    //"for" printing out all the available weapons
	for (int i = 0; i < weaponCount; i++)
	{
        cout << "Id: "; cout << Weapons[i].id; 
        cout << endl << "Name: "; cout << Weapons[i].w_name; 
        cout << endl << "Manufacturer: "; cout << Weapons[i].w_manufacturer; 
        cout << endl << "Year of Manufacturing: "; cout << Weapons[i].w_manufactureYear; 
        cout << endl << "Price: "; cout << Weapons[i].cleanPrice; 
		cout << endl << "Attachments: "; 
        if (Weapons[i].w_hasAttachment == true)
        {
            cout << "Yes"; 
        }
        else
        {
            cout << "No";  
        }
        cout << endl;
        if (Weapons[i].w_hasAttachment == true)
		{
        cout << "Type of attachment: "; cout << Weapons[i].w_attachment.att_type; 
        cout << endl << "Attachment position: "; cout << Weapons[i].w_attachment.att_position; 
        cout << endl << "Price of weapon with the attachments: "; cout << Weapons[i].priceWithAttachment; 
        cout << endl;
		}
        cout << "-------------------------------------------------------"<<endl;
	}
}

//--------Function searching for weapons falling in a selected criteria-----------
void searchSorting(float a,float b,int sel) 
{
    if (sel==1)
    {
        for (int i = 0; i < weaponCount; i++)
        {
            if (Weapons[i].w_manufactureYear > a && Weapons[i].w_manufactureYear < b)
            {
                cout << "Id: "; cout << Weapons[i].id;
                cout << endl << "Name: "; cout << Weapons[i].w_name;
                cout << endl << "Manufacturer: "; cout << Weapons[i].w_manufacturer;
                cout << endl << "Year of Manufacturing: "; cout << Weapons[i].w_manufactureYear;
                cout << endl << "Price: "; cout << Weapons[i].cleanPrice;
                cout << endl << "Attachments: ";
                if (Weapons[i].w_hasAttachment == true)
                {
                    cout << "Yes";
                }
                else
                {
                    cout << "No";
                }
                cout << endl;
                if (Weapons[i].w_hasAttachment == true)
                {
                    cout << "Type of attachment: "; cout << Weapons[i].w_attachment.att_type;
                    cout << endl << "Attachment position: "; cout << Weapons[i].w_attachment.att_position;
                    cout << endl << "Price of weapon with the attachments: "; cout << Weapons[i].priceWithAttachment;
                    cout << endl;
                }
                cout << "-------------------------------------------------------" << endl;
            }
        }
    }
    else if(sel==2)
    {
        for (int i = 0; i < weaponCount; i++)
        {
            if (Weapons[i].cleanPrice > a&& Weapons[i].cleanPrice < b)
            {
                cout << "Id: "; cout << Weapons[i].id;
                cout << endl << "Name: "; cout << Weapons[i].w_name;
                cout << endl << "Manufacturer: "; cout << Weapons[i].w_manufacturer;
                cout << endl << "Year of Manufacturing: "; cout << Weapons[i].w_manufactureYear;
                cout << endl << "Price: "; cout << Weapons[i].cleanPrice;
                cout << endl << "Attachments: ";
                if (Weapons[i].w_hasAttachment == true)
                {
                    cout << "Yes";
                }
                else
                {
                    cout << "No";
                }
                cout << endl;
                if (Weapons[i].w_hasAttachment == true)
                {
                    cout << "Type of attachment: "; cout << Weapons[i].w_attachment.att_type;
                    cout << endl << "Attachment position: "; cout << Weapons[i].w_attachment.att_position;
                    cout << endl << "Price of weapon with the attachments: "; cout << Weapons[i].priceWithAttachment;
                    cout << endl;
                }
                cout << "-------------------------------------------------------" << endl;
            }
        }
    }
    else if (sel==3)
    {
        for (int i = 0; i < weaponCount; i++)
        {
            if (Weapons[i].priceWithAttachment > a&& Weapons[i].priceWithAttachment < b)
            {
                cout << "Id: "; cout << Weapons[i].id;
                cout << endl << "Name: "; cout << Weapons[i].w_name;
                cout << endl << "Manufacturer: "; cout << Weapons[i].w_manufacturer;
                cout << endl << "Year of Manufacturing: "; cout << Weapons[i].w_manufactureYear;
                cout << endl << "Price: "; cout << Weapons[i].cleanPrice;
                cout << endl << "Attachments: ";
                if (Weapons[i].w_hasAttachment == true)
                {
                    cout << "Yes";
                }
                else
                {
                    cout << "No";
                }
                cout << endl;
                if (Weapons[i].w_hasAttachment == true)
                {
                    cout << "Type of attachment: "; cout << Weapons[i].w_attachment.att_type;
                    cout << endl << "Attachment position: "; cout << Weapons[i].w_attachment.att_position;
                    cout << endl << "Price of weapon with the attachments: "; cout << Weapons[i].priceWithAttachment;
                    cout << endl;
                }
                cout << "-------------------------------------------------------" << endl;
            }
        }
    }
}


//---------------------Gives data to the previous function------------------------
void searchFirearms()
{
    int selection;
    cout << "+--------------------------------------------+" << endl;
    cout << "|     Select a criteria for your search      |" << endl;
    cout << "|                                            |" << endl;
    cout << "|  1. Span of year of manufacturing(from-to) |" << endl;
    cout << "|  2. Span of price(from-to)                 |" << endl;
    cout << "|  3. Span of price with attacments(from-to) |" << endl;
    cout << "|                                            |" << endl;
    cout << "+--------------------------------------------+" << endl;
    cout << ":"; cin >> selection;
    switch (selection)
    {
    case 1:
        int fromYear, toYear;
        cout << "Please insert start of span and end of span(from to):"; cin >> fromYear >> toYear;
        searchSorting(fromYear,toYear, selection);
        break;
    case 2:
        float fromPrice, toPrice;
        cout << "Please insert start of span and end of span(from to):"; cin >> fromPrice >> toPrice;
        searchSorting(fromPrice, toPrice, selection);
        break;
    case 3:
        float fromAttPrice, toAttPrice;
        cout << "Please insert start of span and end of span(from to):"; cin >> fromAttPrice >> toAttPrice;
        searchSorting(fromAttPrice, toAttPrice, selection);
        break;  
    default:
        cout << "Please select a viable number."; searchFirearms();
        break;
    }
}

//------------------------Function sorting the firearms---------------------------
void sortFirearms()
{
    int selection;
    cout << "+--------------------------------------------+" << endl;
    cout << "|     Select a criteria for your sort        |" << endl;
    cout << "|                                            |" << endl;
    cout << "|  1. Sort by year of manufacturing(>)       |" << endl;
    cout << "|  2. Sort by price(>)                       |" << endl;
    cout << "|  3. Sort by price with attachment(>)       |" << endl;
    cout << "|                                            |" << endl;
    cout << "+--------------------------------------------+" << endl;
    cout << ":"; cin >> selection;

    switch (selection)
    {
    case 1:
        for (int i = 0; i < weaponCount-1; i++)
        {
            if (Weapons[i].w_manufactureYear> Weapons[i+1].w_manufactureYear)
            {
                swap(Weapons[i].id, Weapons[i + 1].id);
                swap(Weapons[i].w_name, Weapons[i + 1].w_name);
                swap(Weapons[i].w_manufacturer, Weapons[i + 1].w_manufacturer);
                swap(Weapons[i].w_manufactureYear, Weapons[i + 1].w_manufactureYear);
                swap(Weapons[i].cleanPrice, Weapons[i + 1].cleanPrice);
                swap(Weapons[i].w_hasAttachment, Weapons[i + 1].w_hasAttachment);
                swap(Weapons[i].w_attachment.att_type, Weapons[i+1].w_attachment.att_type);
                swap(Weapons[i].w_attachment.att_position, Weapons[i + 1].w_attachment.att_position);
                swap(Weapons[i].priceWithAttachment, Weapons[i + 1].priceWithAttachment);
            }
        }
        break;
    case 2:
        for (int i = 0; i < weaponCount - 1; i++)
        {
            if (Weapons[i].cleanPrice > Weapons[i + 1].cleanPrice)
            {
                swap(Weapons[i].id, Weapons[i + 1].id);
                swap(Weapons[i].w_name, Weapons[i + 1].w_name);
                swap(Weapons[i].w_manufacturer, Weapons[i + 1].w_manufacturer);
                swap(Weapons[i].w_manufactureYear, Weapons[i + 1].w_manufactureYear);
                swap(Weapons[i].cleanPrice, Weapons[i + 1].cleanPrice);
                swap(Weapons[i].w_hasAttachment, Weapons[i + 1].w_hasAttachment);
                swap(Weapons[i].w_attachment.att_type, Weapons[i + 1].w_attachment.att_type);
                swap(Weapons[i].w_attachment.att_position, Weapons[i + 1].w_attachment.att_position);
                swap(Weapons[i].priceWithAttachment, Weapons[i + 1].priceWithAttachment);
            }
        }
        break;
    case 3:
        for (int i = 0; i < weaponCount - 1; i++)
        {
            if (Weapons[i].priceWithAttachment > Weapons[i + 1].priceWithAttachment)
            {
                swap(Weapons[i].id, Weapons[i + 1].id);
                swap(Weapons[i].w_name, Weapons[i + 1].w_name);
                swap(Weapons[i].w_manufacturer, Weapons[i + 1].w_manufacturer);
                swap(Weapons[i].w_manufactureYear, Weapons[i + 1].w_manufactureYear);
                swap(Weapons[i].cleanPrice, Weapons[i + 1].cleanPrice);
                swap(Weapons[i].w_hasAttachment, Weapons[i + 1].w_hasAttachment);
                swap(Weapons[i].w_attachment.att_type, Weapons[i + 1].w_attachment.att_type);
                swap(Weapons[i].w_attachment.att_position, Weapons[i + 1].w_attachment.att_position);
                swap(Weapons[i].priceWithAttachment, Weapons[i + 1].priceWithAttachment);
            }
        }
        break;
    default:
        cout << "Please, insert an applicable number" << endl; sortFirearms();
        break;
    }
}

//----------------Sells a firearm, removing it from the database------------------
void sellFirearm()
{
    int desiredID;//initialising an int for an ID
    cout << "Enter the ID of the firearm you want to buy"<<endl;
    cout << ":"; cin >> desiredID;//the user inserts desired id
    for (int i = 0; i < weaponCount; i++)//"for" cycling through to find the desired id by the user
    {
        if (Weapons[i].id==desiredID)//"if" checkig if the desired id equals the id of the weapon slot
        {
            cout << "Bought weapon:"<<endl;
            cout << "Id: "; cout << Weapons[i].id;
            cout << endl << "Name: "; cout << Weapons[i].w_name;
            cout << endl << "Manufacturer: "; cout << Weapons[i].w_manufacturer;
            cout << endl << "Year of Manufacturing: "; cout << Weapons[i].w_manufactureYear;
            cout << endl << "Price: "; cout << Weapons[i].cleanPrice;
            cout << endl << "Attachments: ";
            if (Weapons[i].w_hasAttachment == true)
            {
                cout << "Yes";
            }
            else
            {
                cout << "No";
            }
            cout << endl;
            if (Weapons[i].w_hasAttachment == true)
            {
                cout << "Type of attachment: "; cout << Weapons[i].w_attachment.att_type;
                cout << endl << "Attachment position: "; cout << Weapons[i].w_attachment.att_position;
                cout << endl << "Price of weapon with the attachments: "; cout << Weapons[i].priceWithAttachment;
                cout << endl;
            }
            char confirmation;//initialising char for coonfirmation
            cout << "Confirm?(Y/N): "; cin >> confirmation;//cin char for confirmation
            if (confirmation=='Y'|| confirmation == 'y')//check if confirmation is Y or y
            {
                //clears all fields of selected weapon
                Weapons[i].id = NULL;
                Weapons[i].w_name = "";
                Weapons[i].w_manufacturer = "";
                Weapons[i].w_manufactureYear = NULL;
                Weapons[i].cleanPrice = NULL;
                if (Weapons[i].w_hasAttachment == true)
                {
                    Weapons[i].w_attachment.att_type = "";
                    Weapons[i].w_attachment.att_position = "";
                    Weapons[i].priceWithAttachment = NULL;
                }
                //last weapon becomes selected weapon
                Weapons[i].id = Weapons[weaponCount-1].id;
                Weapons[i].w_name = Weapons[weaponCount - 1].w_name;
                Weapons[i].w_manufacturer = Weapons[weaponCount - 1].w_manufacturer;
                Weapons[i].w_manufactureYear = Weapons[weaponCount - 1].w_manufactureYear;
                Weapons[i].cleanPrice = Weapons[weaponCount - 1].cleanPrice;
                if (Weapons[i].w_hasAttachment == true)
                {
                    Weapons[i].w_attachment.att_type = Weapons[weaponCount - 1].w_attachment.att_type;
                    Weapons[i].w_attachment.att_position = Weapons[weaponCount - 1].w_attachment.att_position;
                    Weapons[i].priceWithAttachment = Weapons[weaponCount - 1].priceWithAttachment;
                }
                weaponCount--;
            }
            else if(confirmation == 'N' || confirmation == 'n')
            {
                cout << "Do you want to select a new weapon(Y/N): "; cin >> confirmation;//check if the customer wants to enter a new id
                if (confirmation == 'Y' || confirmation == 'y')
                {
                    sellFirearm();
                }
            }
        }
    }
}

//----------Function, utilizing the selection from the function ahead-------------
void selection(int selection)
{
    //Switch-case selecting the different menus
    switch (selection)
    {
    case 1:
		displayWeapons();
        break;
    case 2:
        searchFirearms();
        break;
    case 3:
        sortFirearms();
        break;
    case 4:
        sellFirearm();
        break;
    case 5:
        insertWeaponData();
        break;
    case 0:
        break;
    default:
        cout << "Please, insert an applicable number" << endl; break;
    }
}

//-----------------------Structure printing the main menu-------------------------
void mainMenu()
{

    //------------------------The main menu of the program----------------------------
    cout << "+--------------------------------------------+" << endl;
    cout << "|           Please choose a number           |" << endl;
    cout << "|                                            |" << endl;
    cout << "|  1. See available firearms                 |" << endl;
    cout << "|  2. Search available firearms              |" << endl;
    cout << "|    -> 3: Sort available firearms           |" << endl;
    cout << "|  4. Order firearm                          |" << endl;
    cout << "|  5. Add available firearm                  |" << endl;
    cout << "|  0. Exit                                   |" << endl;
    cout << "|                                            |" << endl;
    cout << "+--------------------------------------------+" << endl;
    cout << ":";
    cin >> input;
    selection(input);
}


//--------------------------The core of the program-----------------------------
int main()
{
    while (input != 0)
    {
        mainMenu();
    }
    cout << "Goodbye!";
}


/*
Copyright© Georgi Mihov/Emily Kehayova/Alexandra Laleva/Boris Milev

We state that there are no copied lines of code. Everything is personally
written by the hands of the members stated above.
*/