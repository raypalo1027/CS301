 #include "person.cpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <iomanip>

using namespace std;

void readData(vector<Person> &);
void getCompanies(vector<Person> &, vector<string> &);
void printHighestPaid(vector<Person>);
void separateAndSave(vector<Person>, vector<string>);

int main()
{
  vector<Person> employees;
  vector<string> companyNames;

  readData(employees);
  printHighestPaid(employees);
  getCompanies(employees, companyNames);
  separateAndSave(employees, companyNames);

  return 0;
}

void readData(vector<Person> &employeeVector)
{
  //declare variables to read into
  string fName, lName, cName;
  int ID;
  float pay,  numOfHours;
  //initialize a temporary person object to push into the vector
  Person temp;

  //initialize file stream object to read from the file "input.txt"
  ifstream inData("input.txt");

  inData >> fName;
  while(!inData.eof())
  {
    inData >> lName >> ID >> cName >> numOfHours >> pay;

    temp.setFirstName(fName);
    temp.setLastName(lName);
    temp.setEmployeeID(ID);
    temp.setCompanyName(cName);
    temp.setHoursWorked(numOfHours);
    temp.setPayRate(pay);

    employeeVector.push_back(temp);

    inData >> fName;
  }
}
void getCompanies(vector<Person> &employeeVector, vector<string> &companyVector)
{
    string current = employeeVector.at(0).getCompanyName();
    companyVector.push_back(current);
    bool inCompanies = false;
    vector<string>::iterator ptr = companyVector.begin();


    for (int i = 1; i < employeeVector.size(); i++)
    {
      current = employeeVector.at(i).getCompanyName();

      while(!inCompanies && ptr != companyVector.end())
      {
        if (current == *ptr)
        {
          inCompanies = true;
        }

        ptr++;
      }

      if(!inCompanies)
      {
        companyVector.push_back(current);
      }

      ptr = companyVector.begin();
      inCompanies = false;

    }

}
void printHighestPaid(vector<Person> employeeVector)
{
  //create a temporary person object to store the person
  //with the highest pay
  Person richest = employeeVector.at(0);

  for (int i = 1; i < employeeVector.size(); i++)
  {
    if (employeeVector.at(i).totalPay() > richest.totalPay())
    {
      richest = employeeVector.at(i);
    }
  }

  cout << "Highest paid: " << richest.fullName() << "\nEmployee ID: "
    << richest.getEmployeeID() << "\nEmployer: " << richest.getCompanyName()
      << "\nTotal pay: $" << richest.totalPay() << endl;
}
void separateAndSave(vector<Person> employeeVector,
  vector<string> companyVector)
{
  ofstream outData;
  float total = 0; //used to keep track of total pay for each company

  for (int j = 0;j < companyVector.size(); j++)
  {
    outData.open(companyVector.at(j) + ".txt");

    for (int i = 0; i < employeeVector.size(); i++)
    {
      if(employeeVector.at(i).getCompanyName() == companyVector.at(j))
      {
        outData << left << setw(18) << employeeVector.at(i).fullName() << " "
          << left << setw(5) << employeeVector.at(i).getEmployeeID() << " "
            << employeeVector.at(i).getCompanyName() << " "
              << fixed << setprecision(2) << "$"
                <<employeeVector.at(i).totalPay() << endl;

        total += employeeVector.at(i).totalPay();
      }
    }

    outData << "Total Pay: $" << fixed << setprecision(2) << total << endl;
    total = 0;//reset total to 0
    outData.close();
  }
}
