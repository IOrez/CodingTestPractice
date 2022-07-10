#include <functional>
#include <cstring>
#include <memory>
#include <string>
#include <iostream>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

void itoa(int n, char* buffer)
{
    sprintf(buffer, "%d", n);
}

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void MulStrWithStr(string& a, string& b, string& result)
{
    int i, j, k, n, c;
    int i_r, i_a, i_b, i_t;

    reverse(result.begin(), result.end());
    for (i = b.size() - 1; i >= 0; --i)
    {
        string temp;
        n = i, c = 0;
        while (n++ < b.size() - 1)
            temp.push_back('0');
        for (j = a.size() - 1; j >= 0; --j)
        {
            i_a = (a[j] - '0'), i_b = (b[i] - '0');
            i_t = (i_a * i_b + c) % 10;
            c = (i_a * i_b + c) / 10;
            temp.push_back(i_t + '0');
        }

        if (c > 0)
            temp.push_back(c + '0');
        c = 0;

        for (j = 0, k = 0; j < result.length() && k < temp.length(); ++j, ++k)
        {
            i_r = result[j] - '0' + c;
            i_t = temp[k] - '0';

            result[j] = (i_r + i_t) % 10 + '0';
            c = (i_r + i_t) / 10;
        }

        while (j < result.length())
        {
            i_r = (result[j] - '0' + c) % 10;
            c = (result[j] - '0' + c) / 10;
            result[j] = i_r + '0';
            j++;
        }

        while (k < temp.length())
        {
            i_t = (temp[k] - '0' + c) % 10;
            c = (temp[k] - '0' + c) / 10;
            result.push_back(i_t + '0');
            k++;
        }
        if (c > 0)
            result.push_back(c + '0');
    }

    reverse(result.begin(), result.end());
    return;
}
void extraLongFactorials(int n) {
    int i = 0;
    char buffer[16];
    string a = "1";
    string result = "";
    for (i = 1; i <= n; ++i)
    {
        result = "";
        itoa(i, buffer);
        string b(buffer);

        MulStrWithStr(a, b, result);
        a = result;
    }
    printf("%s", result.c_str());
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
