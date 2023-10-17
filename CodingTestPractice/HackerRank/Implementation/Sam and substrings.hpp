#include <cstring>
#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>


using namespace std;

/*
 * Complete the 'substrings' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING n as parameter.
 */
#define MOD 1000000007
using ull = unsigned long long;

ull substrings(string n) {
    ull tot = 0, prev = 0;
    for (int i = 0; i < n.size(); i++)
    {
        prev = (prev * 10 + (ull)(n[i] - '0') * (i + 1)) % MOD;
        tot = (tot + prev) % MOD;
    }

    return tot;
}


int main()
{

    string n;
    getline(cin, n);

    ull result = substrings(n);

    cout << result << "\n";

    return 0;
}
