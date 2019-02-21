//Begin Person.h
#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
private:
  string lastName;
  string firstName;
  float payRate;
  float hoursWorked;

public:
  Person();
  void setLastName(string lName);
  string getLastName();
  void setFirstName(string fName);
  string getFirstName();
  void setPayRate(float payAmount);
  float getPayRate();
  void setHoursWorked(float numOfHours);
  float getHoursWorked();
  float totalPay();
  string fullName();
};

#endif //end Person.h
