#include <string>
#include <iostream>
#include "Person.h"
#include "Date.h"
using namespace std;

Person::Person()
{
	//The Person has a default constructor which initializes the name to “”, 
	name = "";
	//the age to 0 
	age = 0;
}

Person::Person(string perDesc, Date perDate)
{
	bday = perDate;
	name = perDesc;
	//Base Calculation of age
	CalcAge();
	bday.SetDesc("Your Name:" + name + "Your Age:" + to_string(age) + "Is your info");
}

Person::Person(string perDescription, int perMonth, int perDay, int perYear)
{
	bday.SetDate(perMonth, perDay, perYear, perDescription);
	CalcAge();
	name = perDescription;
}

void Person::SetBirthday(Date d)
{
	bday = d;
	CalcAge();
}

void Person::SetBirthday(int perMonth, int perDay, int perYear)
{
	string perDescription;
	bday.SetDate(perDay, perDay, perYear, perDescription);
	CalcAge();
}

string Person::GetNameAge()
{
	//The GetNameAge returns a string with the person’s name and age (in years). 
	return  to_string(age);

}

string Person::GetFullDesc() 
{
	//)The GetFullDescr returns a string that is formatted with a newline, and then name, age and the birthday. 
	return "Name:" + name + "Age:"+ to_string(age) + "Birthday:"+ bday.GetFormattedDate();
}

Date Person::GetBirthDay()
{
	Date d;
	return d;
}
//custom methods
void Person::CalcAge()
{
	Date dateCalc; 

	if (dateCalc.GetMonth() == bday.GetMonth()) 
	{
		if (dateCalc.GetDay() >= bday.GetDay()) 
		{
			//calc the age of the user
			age = (dateCalc.GetYear()) - (bday.GetYear());
		}
		else 
		{
			//calc the age of the user
			age = (dateCalc.GetYear()) - (bday.GetYear()) -1;
		}
	}
	else if (dateCalc.GetMonth() > bday.GetMonth()) 
	{
		//calc the age of the user
		age = (dateCalc.GetYear()) - (bday.GetYear());
	}
	else 
	{
		//calc the age of the user
		age = (dateCalc.GetYear()) - (bday.GetYear()) -1;
	}
}
//overloaded operators
bool Person::operator < (Person p)
{
	//using the string class to compare the "name"
	if (name < p.name) 
	{
		return true;
	}

	return false;
}

bool Person::operator > (Person p)
{
	if (name > p.name) 
	{
		return true;
	}
	return false;
}