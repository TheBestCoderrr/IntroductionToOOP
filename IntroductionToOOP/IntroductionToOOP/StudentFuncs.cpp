#include <iostream>
#include "Classes.h"
#define TEXTSIZE 50
using namespace std;

void Student::EnteringStudent(Student& SomeStudent) {
	SomeStudent.pib.FirstName = new char[TEXTSIZE];
	SomeStudent.pib.LastName = new char[TEXTSIZE];
	SomeStudent.pib.SurName = new char[TEXTSIZE];
	cout << "Enter First Name: ";
	cin.getline(SomeStudent.pib.FirstName, TEXTSIZE);
	cout << "Enter Last Name: ";
	cin.getline(SomeStudent.pib.LastName, TEXTSIZE);
	cout << "Enter Sur Name: ";
	cin.getline(SomeStudent.pib.SurName, TEXTSIZE);

	cout << "Enter date(d/m/y): ";
	cin >> SomeStudent.date.day >> SomeStudent.date.month >> SomeStudent.date.year;

	cout << "Enter Phone Number: ";
	cin >> SomeStudent.PhoneNumber;

	SomeStudent.NameUniversity = new char[TEXTSIZE];
	cout << "Enter University name: ";
	cin.ignore();
	cin.getline(SomeStudent.NameUniversity, TEXTSIZE);

	SomeStudent.StudentLocation.city = new char[TEXTSIZE];
	SomeStudent.StudentLocation.country = new char[TEXTSIZE];
	cout << "(Student location)\nEnter city: ";
	cin.getline(SomeStudent.StudentLocation.city, TEXTSIZE);
	cout << "Enter country: ";
	cin.getline(SomeStudent.StudentLocation.country, TEXTSIZE);
	
	SomeStudent.UniversityLocation.city = new char[TEXTSIZE];
	SomeStudent.UniversityLocation.country = new char[TEXTSIZE];
	cout << "(University location)\nEnter city: ";
	cin.getline(SomeStudent.UniversityLocation.city, TEXTSIZE);
	cout << "Enter country: ";
	cin.getline(SomeStudent.UniversityLocation.country, TEXTSIZE);

	cout << "Enter Group Number: ";
	cin >> SomeStudent.GroupNumber;
}

void Student::PrintInfo(Student SomeStudent) const{
	PIB pib = SomeStudent.GetPIB();
	Date date = SomeStudent.GetDate();
	char * NameUniversity = SomeStudent.GetNameUniversity();
	cout << "First Name: " << pib.FirstName << endl;
	cout << "Last Name: " << pib.LastName << endl;
	cout << "SurName: " << pib.SurName << endl;
	cout << "Date: " << date.day << "/" << date.month << "/" << date.year << endl;
	int Number = SomeStudent.GetPhoneNumber();
	cout << "Phone number: " << Number << endl;
	cout << "Name University: " << NameUniversity << endl;
	Location location = SomeStudent.GetStudentLocation();
	cout << "~StudentLocation~\nCity:" << location.city << endl;
	cout << "Country:" << location.country << endl;
	delete[] location.city;
	delete[] location.country;
	location = SomeStudent.GetUniversityLocation();
	cout << "~UniversityLocation~\nCity:" << location.city << endl;
	cout << "Country:" << location.country << endl;
	Number = SomeStudent.GetGroupNumber();
	cout << "Group number: " << Number << endl;

	delete[] pib.FirstName;
	delete[] pib.LastName;
	delete[] pib.SurName;
	delete[] NameUniversity;
	delete[] location.city;
	delete[] location.country;
}
