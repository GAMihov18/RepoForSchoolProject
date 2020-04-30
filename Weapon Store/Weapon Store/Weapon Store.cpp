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
    int cleanPrice;
    bool w_hasAttachment = false;
    ATTACHMENT_DATA w_attachment;
    int priceWithAttachment;
};

//----------------------End of structure initialization-------------------------

//--------------------Initialization of global variables-----------------------
WEAPON_DATA Weapons[100];
int weaponCount = 0;
int weaponCountBeforeAddition = 0;
int input = 1;
int globalId = 0;
//---------------------Start of function initializations------------------------

//--------------Function for inserting the data for the weapons-----------------

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
        cout << "Name(text, no spaces): "; cin >> weapon[i].w_name;
        cout << endl << "Manufacturer(text, no spaces): "; cin >> weapon[i].w_manufacturer;
        cout << endl << "Year of Manufacturing(number): "; cin >> weapon[i].w_manufactureYear;
        cout << endl << "Price(number): "; cin >> weapon[i].cleanPrice;
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

void displayWeapons ()
{    

	for (int i = 0; i < weaponCount; i++)
	{
        cout << "Id: "; cout << Weapons[i].id;
		cout << endl << "Name: "; cout << Weapons[i].w_name;
		cout << endl << "Manufacturer: "; cout << Weapons[i].w_manufacturer;
		cout << endl << "Year of Manufacturing: "; cout << Weapons[i].w_manufactureYear;
		cout << endl << "Price: "; cout << Weapons[i].cleanPrice;
		cout << endl << "Attachments: "; 
        if (Weapons[i].w_hasAttachment == true)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
		if (Weapons[i].w_hasAttachment == true)
		{
			cout << "Type of attachment: "; cout<< Weapons[i].w_attachment.att_type;
			cout << endl << "Attachment position: "; cout<< Weapons[i].w_attachment.att_position;
			cout << endl << "Price of weapon with the attachments: "; cout<< Weapons[i].priceWithAttachment;
            cout << endl;
		}
	}
}



void selection(int selection)
{
    //Switch-case selecting the different menus
    switch (selection)
    {
    case 1:
		displayWeapons();
        break;
    case 2:
        cout << "Search available firearms" << endl;
        break;
    case 3:
        cout << "Sort available firearms" << endl;
        break;
    case 4:
        cout << "Order firearm" << endl;
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
}