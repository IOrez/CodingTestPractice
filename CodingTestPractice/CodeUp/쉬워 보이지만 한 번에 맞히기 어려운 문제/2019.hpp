#include <iostream>
#include <cmath>
#include <iomanip>
#include <complex>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	int D = b * b - 4 * a * c;
	float ans1 = 0.0f;
	float ans2 = 0.0f;
	if (D > 0)
	{
		ans1 = (float)(-1 * b + sqrt(D)) / (2 * a);
		ans2 = (float)(-1 * b - sqrt(D)) / (2 * a);
		cout<< fixed << setprecision(2) << ans1 << endl
			<< ans2 << endl;
	}
	else if (D == 0)
	{
		ans1 = (float)(-1 * b) / (2 * a);
		cout << fixed << setprecision(2) << ans1 << endl;
	}
	else
	{
		complex<double> com;
		D *= -1;
		float image = abs(sqrt(D) / (2 * a));
		ans1 = (float)(-1 * b) / (2 * a);
		cout << fixed<<setprecision(2) << ans1 <<"+" <<image<< "i"<<endl
			<< ans1 << "-" << image << "i"<<endl;
	}
	return 0;
}