#include "Person.cpp"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

void readData(vector<Person> &);
void writeData(vector<Person>);

using namespace std;

int main()
{
  vector<Person> peopleVector;

  readData(peopleVector);
  cout << peopleVector.at(0).getFirstName() << endl;
  cout << peopleVector.at(1).getFirstName() << endl;
  cout << peopleVector.at(2).getFirstName() << endl;
  writeData(peopleVector);
  return 0;
}

/*
reads from the file input.txt and creates
an array of type Person
*/
void readData(vector<Person> &people)
{
  string fName, lName;
  float pay, numOfHours;
  ifstream inData("input.txt");

  inData >> fName;
  while(!inData.eof())
  {
    inData >> lName >> numOfHours >> pay;
    people.emplace_back(fName, lName, pay, numOfHours);
    inData >> fName;
  }

  inData.close();
}

/*
writes to the file output.txt in the format
Full Name Total Pay(Hours Worked * Pay Rate)
*/
void writeData(vector<Person> people)
{
  ofstream outData("output.txt");

  for(int i = 0; i < people.size(); i++)
  {
    outData << people.at(i).fullName() << " " << people.at(i).totalPay() << endl;
  }

  outData.close();
}
