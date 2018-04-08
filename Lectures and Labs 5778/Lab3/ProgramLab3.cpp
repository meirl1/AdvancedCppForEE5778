
//AUTHORS:		Eliezer Gensburger & Plony Almony
//ID:			09090980980	&	123456789
//TITTLE:		exercise x part y
//SUBJECT:		someting doing with the course
//DESCRIPTION:
/********************************************************
*														*
*	Sometimes it is need to describe the program with	*
*	more details. This is generally not necessary for	*
*	the first course in Computer Science Intro			*
*	בעברית												*
*														*
********************************************************/
#include "Point.h"
#include "Polygon.h"
#include <iostream>
using namespace std;

int main()
{
	int n;
	double x, y;
	cout << "jiihiuhjkb mknhhbn" << endl;
	cin >> n;
	Polygon poly(n);
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		cin >> y;
		poly.addPoint(i, Point(x, y));
	}
	cout << "perimeter is: " << poly.perimeter() << endl;
	system("pause");
	return 0;
}