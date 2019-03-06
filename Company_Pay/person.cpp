#include "person.h"
Person::Person()
{

  firstName = "";
  lastName = "";
  employeeID = 0;
  companyName = "";
  hoursWorked = 0;
  payRate = 0;
}
void Person::setFirstName(string fName)
{
  firstName = fName;
}
string Person::getFirstName()
{
  return firstName;
}
void Person::setLastName(string lName)
{
  lastName = lName;
}
string Person::getLastName()
{
  return lastName;
}
void Person::setEmployeeID(int ID)
{
  employeeID = ID;
}
int Person::getEmployeeID()
{
  return employeeID;
}
void Person::setCompanyName(string cName)
{
  companyName = cName;
}
string Person::getCompanyName()
{
  return companyName;
}
void Person::setHoursWorked(float numOfHours)
{
  hoursWorked = numOfHours;
}
float Person::getHoursWorked()
{
  return hoursWorked;
}
void Person::setPayRate(float pay)
{
  payRate = pay;
}
float Person::getPayRate()
{
  return payRate;
}
float Person::totalPay()
{
  return hoursWorked * payRate;
}
string Person::fullName()
{
  return firstName + " " + lastName;
}
