//PersonGen.h
//Programmer: Eliot Ostling
//Program: 2 peroson

#ifndef  _PERSONGEN_H
#define  _PERSONGEN_H

#include <string>
#include "Person.h"
#include <fstream>
#include <iostream>
#include <time.h>
#include <sstream>



class PersonGen
{
private:

	int youngAge = 4;
	int olderAge = 85;
	string name; 
	int bMonth;
	int bDay;
	int bYear;
	bool bGender=false;
	bool bFileRead = false;
	bool bUseFile=false;
	Date date;
	ifstream checker;
	int totalNumOfPeople=0;
	int countNumOfLinesRead=0;
	string lName[300]; 
	string fName[300];
	string mName[300];
	void BirthdayGen(int youngAge, int oldAge);
	void NameGen();
	bool ReadFile(string fileName, string vn[]);
	void ReadUseFile();

public:
	PersonGen();

	PersonGen(int youngAge, int oldAge);

	Person GetPerson();

	Person* GetNewPerson();

	bool IsTextFileRead();

	bool CreateFile(string filename, int numOfPersons);

	bool  UseFile(string filename);
};
#endif
