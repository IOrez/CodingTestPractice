#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int hour, minute;
	cin >> hour >> minute;

	minute -= 30;
	if (minute < 0)
	{
		hour -= 1;
		minute += 60;
		if (hour < 0)hour += 24;
	}
	cout << hour << " " << minute;

	return 0;
}