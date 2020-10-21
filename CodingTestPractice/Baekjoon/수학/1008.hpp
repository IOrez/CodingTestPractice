#include <iostream>
#include <numeric>

using namespace std;
numeric_limits<double> db;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int A, B; cin >> A >> B;
	cout.precision(db.max_digits10);
	cout <<fixed<< (double)A / B;

}