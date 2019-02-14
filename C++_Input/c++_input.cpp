#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

int countRecords(int &);

struct PERSON
{
  //char personName[20];
  string personName;
  float balance;
};

void Build_Customer_Array(PERSON [], int);


int main()
{
  int numOfRecords = 0;
  /*
  double savings;
  string firstName;
  string lastName;
  string fullName;*/
  PERSON customerArray[numOfRecords];

  countRecords(numOfRecords);

  /*ifstream inData("data.txt");
  float savings;
  string firstName, lastName, fullName;

  inData >> firstName >> lastName >> savings;
  fullName = firstName + " " + lastName;
  customerArray[0].personName = fullName;
  customerArray[0].balance = savings;

  inData.close();*/
  Build_Customer_Array(customerArray, numOfRecords);
  cout << customerArray[0].personName << " " << customerArray[0].balance << endl;



//  cout << customerArray[0].personName << endl;



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

    //strcpy(array[i].personName, fullName.c_str());
    array[i].personName = fullName;
    array[i].balance = savings;
  }
  inData.close();
}
