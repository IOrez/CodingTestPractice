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
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */


int nonDivisibleSubset(int k, vector<int> s) {
    
    int ans = 0;
    map<int, int> m;
    for (int i = 0; i < s.size(); i++)
        m[s[i] % k]++;

    if (m[0] > 0)
        ans++;
    for (int i = 1; i < k; i++)
    {
        if (m[i] == 0) continue;
        if ((i + i) % k == 0)
            ans++;
        else
        {
            ans += max(m[i], m[k - i]);
            m[i] = 0;
            m[k - i] = 0;
        }
    }

    return ans;
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    int result = nonDivisibleSubset(k, s);

    printf("%d", result);

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
