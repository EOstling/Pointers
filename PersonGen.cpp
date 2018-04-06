//Program 2 
//Programmer: Eliot Ostling

#include "PersonGen.h"


using namespace std;

PersonGen::PersonGen():PersonGen(youngAge, olderAge)
{}

PersonGen::PersonGen(int youngerAge, int oldAge):youngAge(youngerAge),olderAge(oldAge),name(""),bMonth(1),
bDay(1),bYear(1)
{
	srand(time(NULL));

	bool readFile1 = ReadFile("FirstFemale.txt", fName);
	bool readFile2 = ReadFile("FirstMale.txt", mName);
	bool readFile3 = ReadFile("Last.txt", lName);

	if (!readFile1 && !readFile2 && !readFile3) 
	{
		bFileRead = false;
	}
	else 
	{
		bFileRead = true;
	}

}

Person PersonGen::GetPerson() 
{
	Person person;
	if (bUseFile == true)
	{
		ReadUseFile();
	}
	else
	{
		NameGen();
		BirthdayGen(youngAge, olderAge);
	}
	person.SetName(name);
	person.SetBirthday(date);

	return person;
}

Person* PersonGen::GetNewPerson() 
{
	bool bUseFile = false;
	if (bUseFile == true)
	{
		ReadUseFile();
	}
	else
	{
		NameGen();
		BirthdayGen(youngAge, olderAge);
	}
	 Person* personPointer = new Person;
	 personPointer->SetName(name);
	 personPointer->SetBirthday(date);
	return personPointer;
}

bool PersonGen::IsTextFileRead() 
{
	return bFileRead;
}

bool PersonGen::CreateFile(string filename, int numOfPersons) 
{
	stringstream stringstream;
	ofstream importer(filename);
	if (!importer.is_open()) 
	{
		stringstream << "An error Occurred";
		return false;
	}
	else 
	{
		stringstream << numOfPersons << endl;

		for(int i=0; i < numOfPersons; ++i) 
		{
			NameGen();
			BirthdayGen(youngAge, olderAge);
			stringstream << name << " | " << bMonth << " | " << bDay << " | "<< bYear<< "\n";
			importer << stringstream.str();
		}
		importer.close();
	}
	return true;
}

bool  PersonGen::UseFile(string filename) 
{	
	checker.open(filename);
	if (!checker.is_open()) 
	{
		bUseFile = false;
		return false;
	}
	checker >> totalNumOfPeople;
	bUseFile = true;
	return true;
}

void PersonGen::ReadUseFile() 
{
	string month, year, day;
	if (totalNumOfPeople == countNumOfLinesRead)
	{
		NameGen();
		BirthdayGen(youngAge, olderAge);
		checker.close();
		bUseFile = false;
	}
	else 
	{
		getline(checker, name, '|');
		getline(checker, month, '|');
		getline(checker, day, '|');
		getline(checker, year, '|');
		int monthTemp = stoi(month);
		int dayTemp = stoi(day);
		int yearTemp = stoi(year);
		date.SetDate(monthTemp, dayTemp, yearTemp,"");
		countNumOfLinesRead++;
	}
}

bool PersonGen::ReadFile(string fileName, string vn[]) 
{
	string importer;
	ifstream file(fileName);
	int i = 0;
	if (file.is_open())
	{
		while (!file.eof())
		{
				getline(file, importer);
				vn[i] = importer;
				i++;
		}
		file.close();
		return true;
	}
	
	return false;
}

void PersonGen::NameGen()
{
	if (bGender)
	{
		name = lName[rand() % 300] + ", "  + mName[rand() % 300];
		bGender = false;
	}
	else 
	{
		name = lName[rand() % 300] + ", " + fName[rand() % 300];
		bGender = true;
	}
}

void PersonGen::BirthdayGen(int youngAge, int oldAge)
{

	stringstream ss;
	bDay = rand() % 30 + 1;
	bMonth = rand() % 11 + 1;
	bYear = rand() % 68 + 1950; 
	 //www.programiz.com/cpp-programming/examples/leap-year For an accurate calculation of leap year
	if (bYear % 4 == 0)
	{
		if (bYear % 100 == 0)
		{
			if (bYear % 400 == 0) 
			{
				ss << bYear << " is a leap year.";
			}
			
			else 
			{
				ss << bYear << " is not a leap year.";
			}
				
		}
		else
			ss << bYear << " is a leap year.";
			ss.str();
	}

	date.SetDate(bMonth, bDay, bYear, "");	
}