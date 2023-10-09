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
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

int alphabetCount['z' - 'a' + 1];
string isValid(string s) {
    string ans = "NO";
    map<int, int> m;

    int size = 'z' - 'a' + 1;
    for (int i = 0; i < s.size(); i++)
    {
        int key = s[i] - 'a';
        m[key] += 1;
    }

    for (auto targetIter = m.begin(); targetIter != m.end(); targetIter++)
    {
        int targetValue = 0;
        bool check = false;
        for (auto aIter = m.begin(); aIter != m.end(); aIter++)
        {
            if (targetValue == 0)
                targetValue = aIter->second;
            if (targetValue != aIter->second)
            {
                check = true;
                break;
            }
        }

        if (check == false)
        {
            ans = "YES";
            break;
        }
        else
        {
            check = false;
            int targetValue = max(targetIter->second - 1, 0);
            for (auto aIter = m.begin(); aIter != m.end(); aIter++)
            {
                int compareValue = 0;
                if (aIter == targetIter)
                {
                    if (aIter->second - 1 <= 0)
                        continue;

                    compareValue = aIter->second - 1;
                }
                else
                    compareValue = aIter->second;

                if (targetValue == 0)
                {
                    targetValue = compareValue;
                }

                if (targetValue != compareValue)
                {
                    check = true;
                    break;
                }
            }

            if (check == false)
            {
                ans = "YES";
                break;
            }
        }
    }

    return ans;
}

int main()
{

    string s;
    getline(cin, s);

    string result = isValid(s);

    printf("%s", result.c_str());

    return 0;
}
