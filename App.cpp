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
int weaponCount;

//---------------------Start of function initializations------------------------

//--------------Function for inserting the data for the weapons-----------------
/*
void insertWeaponData()
{
  WEAPON_DATA weapon[100];
  int n;
  for (int i = 0; i < n; i++)
  {
    cout << "=================================================" << endl;
    cout << "Name: "; cin >> weapon[i].w_name;
    cout << endl << "Manufacturer: "; cin >> weapon[i].w_manufacturer;
    cout << endl << "Year of Manufacturing: "; cin >> weapon[i].w_manufactureYear;
    cout << endl << "hasAttachment(default: false): "; cin >> weapon[i].w_hasAttachment;
    if (weapon[i].w_hasAttachment == true)
    {
      cout << endl << "Type of attachment: "; cin >> weapon[i].w_attachment.att_type;
      cout << endl << "Attachment position: "; cin >> weapon[i].w_attachment.att_position;
      cout << endl << "Price of weapon with the attachments: "; cin >> weapon[i].priceWithAttachment;
    }
  }
}
*/
//-----------------------Structure printing the main menu-------------------------
void mainMenu()
{

  //-----------------------The main menu of the program---------------------------
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
  int selection;
  cin >> selection;
  //Switch-case selecting the different menus
  switch (selection)
  {
  case 1:
    cout << "See available firearms" << endl;
    mainMenu();
    break;
  case 2:
    cout << "Search available firearms" << endl;
    mainMenu();
    break;
  case 3:
    cout << "Sort available firearms" << endl;
    mainMenu();
    break;
  case 4:
    cout << "Order firearm" << endl;
    mainMenu();
    break;
  case 5:
    cout << "Add available firearm" << endl;
    /*
      int n;
      cout<<"How many firearms do you want to add?"<<endl;
      cout<<":"; cin>>n;
      insertWeaponData(Weapons, n);
    */
    mainMenu();
    break;
  case 0:
    break;
  default:
    cout << "Please, insert an applicable number"<<endl; mainMenu();
  }
}


//--------------------------The core of the program-----------------------------
int main()
{
  mainMenu();
}