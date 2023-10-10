#include <cstring>
#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

#include <queue>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'highestValuePalindrome' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER n
 *  3. INTEGER k
 */

string highestValuePalindrome(string s, int n, int k) {
    const int bufSize = 100001;
    bool bChange[bufSize] = {false,};
    queue<pair<int, int>> pq;
    for (int i = 0; i < s.size() / 2; i++)
    {
        if (s[i] != s[s.size() - 1 - i])
            pq.push(make_pair(i, s.size() - 1 - i));
    }

    while (!pq.empty())
    {
        if (k == 0)
            return "-1";

        auto item = pq.front();
        pq.pop();
        int first = item.first, second = item.second;

        if (s[first] > s[second])
        {
            bChange[second] = true;
            s[second] = s[first];
        }
        else
        {
            bChange[first] = true;
            s[first] = s[second];
        }

        k--;
    }

    if (k > 0)
    {
        for (int i = 0; i < s.size() / 2 && k > 0; i++)
        {
            int first = i, second = s.size() - 1 - i;
            int subcnt = 2;
            if (bChange[first] || (!bChange[first] && s[first] == '9'))
                subcnt--;
            if (bChange[second] || (!bChange[second] && s[second] == '9'))
                subcnt--;

            if (k - subcnt < 0)
                break;
            
            k -= subcnt;
            s[first] = '9';
            s[second] = '9';
        }

        if (k == 1 && s.size() % 2 != 0)
        {
            s[s.size() / 2] = '9';
            k--;
        }
    }

    return s;
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

    cout << result << "\n";


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
