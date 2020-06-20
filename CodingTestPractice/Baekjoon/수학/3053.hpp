#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main()
{
	int R;
	cin >> R;
	cout << fixed<<setprecision(6) << (double)R * R * M_PI << '\n' <<
		setprecision(6) << (double)R * R * 2.0;
	return 0;
}