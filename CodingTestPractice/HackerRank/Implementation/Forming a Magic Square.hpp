#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
#include <functional>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */

int formingMagicSquare(vector<vector<int>> s) {
    int  table[3][3], ans = numeric_limits<int>().max();
    memset(table, 0, sizeof(table));
    table[1][1] = 5;
    for (int i = 0; i < 4; i += 2)
    {
        for (int j = 0; j < 4; j += 2)
        {
            table[i][j] = 2;
            table[2 - i][2 - j] = 8;
            for (int k = 0; k < 4; k += 2)
            {
                for (int l = 0; l < 4; l += 2)
                {
                    if (table[k][l] != 0)
                        continue;
                    table[k][l] = 4;
                    table[2 - k][2 - l] = 6;

                    table[0][1] = 15 - (table[0][0] + table[0][2]);
                    table[2][1] = 15 - (table[2][0] + table[2][2]);
                    table[1][0] = 15 - (table[0][0] + table[2][0]);
                    table[1][2] = 15 - (table[0][2] + table[2][2]);

                    int result = 0;
                    for (int n = 0; n < 3; ++n)
                        for (int m = 0; m < 3; ++m)
                            result += abs(s[n][m] - table[n][m]);
                    ans = min(result, ans);

                    table[k][l] = 0;
                    table[2 - k][2 - l] = 0;
                }
            }
            table[i][j] = 0;
            table[2 - i][2 - j] = 0;
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);

    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        string s_row_temp_temp;
        getline(cin, s_row_temp_temp);

        vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int s_row_item = stoi(s_row_temp[j]);

            s[i][j] = s_row_item;
        }
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

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
