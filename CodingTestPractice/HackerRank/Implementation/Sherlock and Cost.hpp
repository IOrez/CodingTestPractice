#include <cstring>
#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'cost' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY B as parameter.
 */

int DP[2][100001];
int cost(vector<int> B) {
    memset(DP, 0, sizeof(int) * 2 * 100001);
    DP[0][1] = abs(B[0] - 1);
    DP[1][1] = abs(1 - B[1]);
    for (int i = 2; i < B.size(); i++)
    {
        DP[0][i] = DP[1][i - 1] + abs(B[i - 1] - 1);
        DP[1][i] = max(DP[0][i - 1] + abs(1 - B[i]), DP[0][i-2] + abs(1 - B[i]));
    }

    int ans = max(DP[0][B.size() - 1], DP[1][B.size() - 1]);
    return ans;
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string B_temp_temp;
        getline(cin, B_temp_temp);

        vector<string> B_temp = split(rtrim(B_temp_temp));

        vector<int> B(n);

        for (int i = 0; i < n; i++) {
            int B_item = stoi(B_temp[i]);

            B[i] = B_item;
        }

        int result = cost(B);

        cout << result << "\n";
    }


    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), std::not_fn(isspace))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), std::not_fn(isspace)).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
