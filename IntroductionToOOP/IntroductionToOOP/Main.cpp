#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "PointFuncs.h"
using namespace std;
int main() {
	Student SomeStudent;
	SomeStudent.EnteringStudent(SomeStudent);
	cout << endl;
	SomeStudent.PrintInfo(SomeStudent);

	FILE* PointFile;
	Point point{};
	int UserVariant = -1;
	cout << "\nMenu:\n0 - Exit\n1 - Enter Coordinate\n2 - Print Coordinate\n3 - Get Coordinate from file\n4 - Save Point in file\n";
	while (UserVariant != NULL) {
		cout << "Enter variant: ";
		cin >> UserVariant;

		switch (UserVariant) {
			case 0:
				break;
			case 1:
				point.SetX(point.EnteringAxis('x'));
				point.SetY(point.EnteringAxis('y'));
				point.SetZ(point.EnteringAxis('z'));
				break;
			case 2:
				point.PrintCoordinate();
				break;
			case 3:
				PointFile = fopen("C:\\Users\\User\\Downloads\\Points.txt", "r");
				if (PointFile != NULL) {
					GetPointFromFile(PointFile, point);
					fclose(PointFile);
				}
				break;
			case 4:
				PointFile = fopen("C:\\Users\\User\\Downloads\\Points.txt", "a");
				if (PointFile != NULL) {
					SavePointInFile(PointFile, point);
					fclose(PointFile);
				}
				break;
			default:
				cout << "Invalid Variant!" << endl;
				break;
		}
	}
}