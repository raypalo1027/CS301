#ifndef PERSON_H
#define PERSON_H

using namespace std;
#include <string>

class Person
{
private:
  string firstName;
  string lastName;
  int employeeID;
  string companyName;
  float hoursWorked;
  float payRate;
public:
  Person();
  void setFirstName(string fName);
  string getFirstName();
  void setLastName(string lName);
  string getLastName();
  void setEmployeeID(int ID);
  int getEmployeeID();
  void setCompanyName(string cName);
  string getCompanyName();
  void setHoursWorked(float numOfHours);
  float getHoursWorked();
  void setPayRate(float pay);
  float getPayRate();
  float totalPay();
  string fullName();

};
#endif
