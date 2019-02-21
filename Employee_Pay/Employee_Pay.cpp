#include "Person.cpp"
#include <string>
#include <fstream>
#include <iostream>

void readData(Person [], int &);
void writeData(Person [], int);

using namespace std;

int main()
{
  Person personArray[20];
  int numOfRecords = 0;

  readData(personArray, numOfRecords);
  writeData(personArray, numOfRecords);
  return 0;
}

/*
reads from the file input.txt and creates
an array of type Person
*/
void readData(Person array[], int &count)
{
  string fName, lName;
  float pay, numOfHours;
  ifstream inData("input.txt");

  inData >> fName;
  while(!inData.eof())
  {
    inData >> lName >> numOfHours >> pay;
    array[count].setFirstName(fName);
    array[count].setLastName(lName);
    array[count].setHoursWorked(numOfHours);
    array[count].setPayRate(pay);
    inData >> fName;
    count++;
  }

  inData.close();
}

/*
writes to the file output.txt in the format
Full Name Total Pay(Hours Worked * Pay Rate)
*/
void writeData(Person array[], int count)
{
  ofstream outData("output.txt");

  for(int i = 0; i < count; i++)
  {
    outData << array[i].fullName() << " $" << array[i].totalPay() << "\n";
  }

  outData.close();
}
