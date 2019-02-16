/*
Ray Palo
CPSC301
C++ Input Assignment

My program reads from the file data.txt and creates a structure from each line
containing a name and a balance. The program will then make an array out of
the structures.

The user can log in and the program will check if they are in the array, and if
the user exists they will be provided with some options and the file will be
updated accordingly. If the user does not exist the program will close.

User Login
Enter your full name: Maria Brown
------------------------------------
Hello Maria Brown,
What would you like to do?
1. View your balance
2. Make a deposit
3. Make a withdrawal
4. Log out
------------------------------------

Please select an option: 2
Your current ballance is: $2100.9
How much would you like to deposit? $100
You deposited $100. Your new balance is: $2200.9
------------------------------------

Please select an option: 4

I used my name(Ray Palo) to be an admin log in. When the user logs in with my
name, they will be given the options to view the customer array or to view the
richest customer.

User Login
Enter your full name: Ray Palo
------------------------------------
Hello Ray Palo,
What would you like to do?
1. Display Customer Database
2. View richest client
3. Log out
------------------------------------

Please select an option: 1
~~~~~~~Customer Database~~~~~~~
Maria Brown 2200.9
Jeffrey Jackson 200.2
Bernard Smith 223.1
Matthew Davenport 1630.2
Kimberly Macias 19100.9
Amber Daniels 2400.4
------------------------------------

Please select an option: 3
*/
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

int countRecords(int &);

struct PERSON
{
  char personName[20];
  //string personName;
  float balance;
};

void Build_Customer_Array(PERSON [], int);
void Display_Customer_Array(PERSON [], int);
void Find_Richest(PERSON [], int);
void Deposit(char [], PERSON [], int);
void Withdraw(char [], PERSON [], int);
void Update_Database(PERSON[], int);
void Display_Admin_Menu(char [], PERSON [], int);
void Display_Customer_Menu(char [], PERSON [], int, int);


int main()
{
  int numOfRecords = 0;
  int customerIDX = 0;
  bool customerFound = false;
  string userInput;
  char adminName[20] = "Ray Palo";
  char userName[20];

  countRecords(numOfRecords);
  PERSON customerArray[numOfRecords];
  Build_Customer_Array(customerArray, numOfRecords);


  cout << "User Login" << "\nEnter your full name: ";
  getline(cin, userInput);
  strcpy(userName, userInput.c_str());

  if(strcmp(userName, adminName) == 0)
  {
    customerFound = true;
    Display_Admin_Menu(userName, customerArray, numOfRecords);
  }
  else
  {
      while(!customerFound && customerIDX < numOfRecords)
      {
        if(strcmp(customerArray[customerIDX].personName, userName) == 0)
        {
          Display_Customer_Menu(userName, customerArray, numOfRecords,
            customerIDX);
          customerFound = true;
        }
        else
        {
          customerIDX++;
        }
      }
  }
  if(!customerFound)
  {
    cout << "This account does not exist" << endl;
  }

  return 0;
}

//Returns the number of records in the file
int countRecords(int &count)
{
  ifstream inData;
  inData.open("data.txt");
  string line;

  while(getline(inData, line))
  {
    count++;
  }

  inData.close();
  return count;
}

//Reads in the information from the file data.txt
//and initializes the elements of the array
void Build_Customer_Array(PERSON array[], int count)
{
  float savings;
  string firstName;
  string lastName;
  string fullName;
  ifstream inData("data.txt");

  for(int i = 0; i < count; i++)
  {
    inData >> firstName;
    inData >> lastName;
    inData >> savings;

    fullName = firstName + " " + lastName;

    strcpy(array[i].personName, fullName.c_str());
    array[i].balance = savings;
  }
  inData.close();
}

void Display_Customer_Array(PERSON array[], int count)
{
  cout << "~~~~~~~Customer Database~~~~~~~" << endl;
  for(int i = 0; i < count; i++)
  {
    cout << array[i].personName << " " << array[i].balance << endl;
  }
}

//Searches through the customerArray
//and finds the richest customer
void Find_Richest(PERSON array[], int count)
{
  float richest = 0;

  for(int i = 0; i < count; i++)
  {
    if(array[i].balance > richest)
    {
      richest = array[i].balance;
    }
  }

  for(int i = 0; i < count; i++)
  {
    if(array[i].balance == richest)
    {
      cout << "The customer with the greatest balance is " <<
        array[i].personName << endl;
    }
  }

}

void Deposit(char customerName[], PERSON array[], int count)
{
  int idx;
  float depositAmount;
  for(int i = 0; i < count; i++)
  {
    if(strcmp(array[i].personName, customerName) == 0)
    {
        idx = i;
    }
  }

  cout << "Your current ballance is: $"
    << array[idx].balance << "\nHow much would you like to deposit? $";
  cin >> depositAmount;
  array[idx].balance += depositAmount;
  cout << "You deposited $" << depositAmount << ". Your new balance is: $"
    << array[idx].balance << endl;\
    Update_Database(array, count);

}

void Withdraw(char customerName[], PERSON array [], int count)
{
  int idx;
  float withdrawalAmount;
  for(int i = 0; i < count; i++)
  {
    if(strcmp(array[i].personName, customerName) == 0)
    {
        idx = i;
    }
  }

  cout << "Your current ballance is: $" << array[idx].balance
    << "\nHow much would you like to withdraw? $";
  cin >> withdrawalAmount;

  if(withdrawalAmount > array[idx].balance)
  {
    cout << "WARNING! You don't have enough money!" << endl;
  }
  else
  {
    array[idx].balance -= withdrawalAmount;
    cout << "You withdrew $" << withdrawalAmount << ". Your new balance is: $"
      << array[idx].balance << endl;\
    Update_Database(array, count);
  }
}

void Update_Database(PERSON array[], int count)
{
  ofstream outData("data.txt");

  for(int i = 0; i < count; i++)
  {
    outData << array[i].personName << " " << array[i].balance << "\n";
  }
  outData.close();
}

void Display_Admin_Menu(char adminName[], PERSON array[], int count)
{
  int input;
  cout << "------------------------------------" << endl;
  cout << "Hello " << adminName << ",\nWhat would you like to do?"
    << "\n1. Display Customer Database" << "\n2. View richest client"
      << "\n3. Log out" << endl;

  while(input != 3)
  {
    cout << "------------------------------------" << endl;
    cout << "\nPlease select an option: ";
    cin >> input;

    if(input == 1)
    {
      Display_Customer_Array(array, count);
    }
    else if(input == 2)
    {
      Find_Richest(array, count);
    }
  }

}
void Display_Customer_Menu(char customerName[], PERSON array[], int count,
  int idx)
{
  int input;
  cout << "------------------------------------" << endl;
  cout << "Hello " << customerName << ",\nWhat would you like to do?"
    << "\n1. View your balance" << "\n2. Make a deposit"
      << "\n3. Make a withdrawal" << "\n4. Log out" << endl;

  while(input != 4)
  {
    cout << "------------------------------------" << endl;
    cout << "\nPlease select an option: ";
    cin >> input;

    if(input == 1)
    {
      cout << "Your current balance is: $" << array[idx].balance << endl;
    }
    else if(input == 2)
    {
      Deposit(customerName, array, count);
    }
    else if(input == 3)
    {
      Withdraw(customerName, array, count);
    }
  }
}
