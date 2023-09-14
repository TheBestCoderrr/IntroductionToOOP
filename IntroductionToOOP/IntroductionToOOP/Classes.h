#pragma once
class PIB {
public:
	char* FirstName;
	char* LastName;
	char* SurName;
};

class Date {
public:
	int day;
	int month;
	int year;
};

class Location {
public:
	char* city;
	char* country;
};

class Student {
private:
	PIB pib;
	Date date;
	int PhoneNumber;
	char* NameUniversity;
	Location StudentLocation;
	Location UniversityLocation;
	int GroupNumber;
public:
	void SetPIB(PIB pib);
	PIB GetPIB() { return pib; }
	
	void SetDate(Date date);
	Date GetDate() { return date; }
	
	void SetPhoneNumber(int PhoneNumber);
	int GetPhoneNumber() { return PhoneNumber; }
	
	void SetNameUniversity(char* NameUniversity);
	char* GetNameUniversity() { return NameUniversity; }
	
	void SetStudentLocation(Location StudentLocation);
	Location GetStudentLocation() { return StudentLocation; }
	
	void SetUniversityLocation(Location UniversityLocation);
	Location GetUniversityLocation() { return UniversityLocation; }

	void SetGroupNumber(int GroupNumber);
	int GetGroupNumber() { return GroupNumber; }

	void EnteringStudent(Student& SomeStudent);
	void PrintInfo(Student SomeStudent) const;
};

inline void Student::SetPIB(PIB pib) {
	this->pib = pib;
}

inline void Student::SetDate(Date date) {
	this->date = date;
}

inline void Student::SetPhoneNumber(int PhoneNumber) {
	this->PhoneNumber = PhoneNumber;
}

inline void Student::SetNameUniversity(char* NameUniversity) {
	this->NameUniversity = NameUniversity;
}

inline void Student::SetStudentLocation(Location StudentLocation) {
	this->StudentLocation = StudentLocation;
}

inline void Student::SetUniversityLocation(Location UniversityLocation) {
	this->UniversityLocation = UniversityLocation;
}

inline void Student::SetGroupNumber(int GroupNumber) {
	this->GroupNumber = GroupNumber;
}



class Point {
private:
	double x, y, z;
public:
	void SetX(double x);
	double GetX() { return x; }
	
	void SetY(double y);
	double GetY() { return y; }
	
	void SetZ(double z);
	double GetZ() { return z; }

	double EnteringAxis(char symbolaxis);
	void PrintCoordinate();
};

inline void Point::SetX(double x) {
	this->x = x;
}

inline void Point::SetY(double y) {
	this->y = y;
}

inline void Point::SetZ(double z) {
	this->z = z;
}