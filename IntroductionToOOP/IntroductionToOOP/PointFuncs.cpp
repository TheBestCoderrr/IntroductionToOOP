#include <iostream>
#include "Classes.h"
#define STRSIZE 200
using namespace std;

double Point::EnteringAxis(char symbolaxis) {
	double axis;
	cout << "Enter " << symbolaxis << ": ";
	cin >> axis;
	return axis;
}

void Point::PrintCoordinate() {
	cout << "Point coordinate:\n";
	cout << "x = " << x << ";y = " << y << ";z = " << z << ';' << endl;
}

char EnteringPointName() {
	char PointName;
	cout << "Enter point name: ";
	cin >> PointName;
	return PointName;
}

void SavePointInFile(FILE* PointFile, Point point) {
	char PointName = EnteringPointName();
	fprintf(PointFile, "Point %c: %f; %f; %f\n", PointName, point.GetX(), point.GetY(), point.GetZ());
}

double GetDoubleAxis(char* tempAxis){
	bool doubleAxis = false;
	int pointI;
	for (int i = 0; i < strlen(tempAxis); i++) {
		if (tempAxis[i] == '.') {
			doubleAxis = true;
			pointI = i;
		}
	}
	double axis = 0;
	if (doubleAxis == false) {
		for (int i = 0; i < strlen(tempAxis); i++) {
			axis += tempAxis[i] - '0';
			axis *= 10;
		}
		axis /= 10;
	}
	else {
		for (int i = 0; i < pointI; i++) {
			axis += tempAxis[i] - '0';
			axis *= 10;
		}
		axis /= 10;
		double NumAfterPoint = 0;
		for (int i = pointI + 1; i < strlen(tempAxis); i++) {
			NumAfterPoint += tempAxis[i] - '0';;
			NumAfterPoint *= 10;
		}
		NumAfterPoint /= 10;
		NumAfterPoint *= pow(0.1, strlen(tempAxis) - pointI - 1);
		axis += NumAfterPoint;
	}
	return axis;
}

void GetPointFromFile(FILE* PointFile, Point& point) {
	char PointName = EnteringPointName();
	char FilePoint;
	char* PointSTR = new char[STRSIZE];
	do {
		fseek(PointFile, 6, SEEK_CUR);
		FilePoint = fgetc(PointFile);
		if (FilePoint == PointName) {
			fgets(PointSTR, STRSIZE, PointFile);
			char* tempAxis = NULL;
			char* NextAxis = NULL;
			tempAxis = strtok_s(PointSTR, " :;\n", &NextAxis);
			point.SetX(GetDoubleAxis(tempAxis));
			tempAxis = strtok_s(NULL, " :;\n", &NextAxis);
			point.SetY(GetDoubleAxis(tempAxis));
			tempAxis = strtok_s(NULL, " :;\n", &NextAxis);
			point.SetZ(GetDoubleAxis(tempAxis));
			break;
		}
		else {
			fgets(PointSTR, STRSIZE, PointFile);
		}
	} while (PointSTR[strlen(PointSTR)] != EOF);
}