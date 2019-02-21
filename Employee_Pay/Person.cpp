#include "Person.h"

Person::Person(){}

void Person::setLastName(string lName)
{
  lastName = lName;
}

string Person::getLastName()
{
  return lastName;
}

void Person::setFirstName(string fName)
{
  firstName = fName;
}

string Person::getFirstName()
{
  return firstName;
}

void Person::setPayRate(float payAmount)
{
  payRate = payAmount;
}

float Person::getPayRate()
{
  return payRate;
}

void Person::setHoursWorked(float numOfHours)
{
  hoursWorked = numOfHours;
}

float Person::getHoursWorked()
{
  return hoursWorked;
}

float Person::totalPay()
{
  return payRate * hoursWorked;
}

string Person::fullName()
{
  return firstName + " " + lastName;
}
