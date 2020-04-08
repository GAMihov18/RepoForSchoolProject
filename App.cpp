#include <iostream>
#include <string>

using namespace std;

//----------------Innitializing the data structures----------------------------
//-------Data for each weapon attachment(e.g. scope, suppressor, bipod)---------
struct ATTACHMENT_DATA
{
  string att_type;
};


//------------Data structure for each weapon(e.g. M4A1, Scar-L)----------------
//------------------------------Main Structure---------------------------------
struct WEAPON_DATA
{
  string w_name;
  string w_manufacturer;
  int w_manufactureYear;
  bool hasAttachment;
  ATTACHMENT_DATA w_attachment;
};

//----------------------End of structure initialization-------------------------


//--------------------------The core of the program-----------------------------
int main()
{
  WEAPON_DATA Weapons[100];
  int selection;
menu:
  cout << "+--------------------------------------------+" << endl;
  cout << "|           Please choose a number           |" << endl;
  cout << "|                                            |" << endl;
  cout << "|  1. See available firearms                 |" << endl;
  cout << "|  2. Search available firearms              |" << endl;
  cout << "|  3. Sort available firearms                |" << endl;
  cout << "|  4. Add available firearm                  |" << endl;
  cout << "|  0. Exit                                   |" << endl;
  cout << "|                                            |" << endl;
  cout << "+--------------------------------------------+" << endl;
  cout << ":";
defaultCaseError:
  cin >> selection;
  switch (selection)
  {
  case 1:
    goto menu;
  case 2:
    goto menu;
  case 3:
    goto menu;
  case 4:
    goto menu;
  case 0:
    break;
  default:
    cout << "Please, insert an applicable number:"; goto defaultCaseError;
  }
}