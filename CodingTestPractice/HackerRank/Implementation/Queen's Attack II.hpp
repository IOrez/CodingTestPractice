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
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

typedef enum _DIRECTION
{
    DIRECTION_UP,
    DIRECTION_UP_RIGHT,
    DIRECTION_RIGHT,
    DIRECTION_DOWN_RIGHT,
    DIRECTION_DOWN,
    DIRECTION_DOWN_LEFT,
    DIRECTION_LEFT,
    DIRECTION_UP_LEFT,

    MAX_DIRECTION
}DIRECTION;

int minDist[MAX_DIRECTION];

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    for (int i = DIRECTION_UP; i < MAX_DIRECTION; i++)
    {
        switch (i)
        {
        case DIRECTION_UP:
            minDist[i] = n - r_q;
            break;
        case DIRECTION_UP_RIGHT:
            minDist[i] = min(n - c_q , n - r_q );
            break;
        case DIRECTION_RIGHT:
            minDist[i] = n - c_q;
            break;
        case DIRECTION_DOWN_RIGHT:
            minDist[i] = min(n - c_q, r_q - 1);
            break;
        case DIRECTION_DOWN:
            minDist[i] = r_q - 1;
            break;
        case DIRECTION_DOWN_LEFT:
            minDist[i] = min(c_q - 1, r_q - 1);
            break;
        case DIRECTION_LEFT:
            minDist[i] = c_q - 1;
            break;
        case DIRECTION_UP_LEFT:
            minDist[i] = min(c_q - 1, n - r_q);
            break;
        default:
            break;
        }
    }

    for (int i = 0; i < obstacles.size(); i++)
    {
        DIRECTION dir;
        int y = obstacles[i][0], x = obstacles[i][1];
        int difX = x - c_q, difY = y - r_q;
        int abs_difX = abs(difX), abs_difY = abs(difY);
        if (difX == 0)
        {
            dir = (difY > 0) ? DIRECTION_UP : DIRECTION_DOWN;
        }
        else if (difY == 0)
        {
            dir = (difX > 0) ? DIRECTION_RIGHT : DIRECTION_LEFT;
        }
        else
        {
            if (abs_difX != abs_difY)
                continue;

            if (difX > 0 && difY > 0)
                dir = DIRECTION_UP_RIGHT;
            else if (difX > 0 && difY < 0)
                dir = DIRECTION_DOWN_RIGHT;
            else if (difX < 0 && difY > 0)
                dir = DIRECTION_UP_LEFT;
            else
                dir = DIRECTION_DOWN_LEFT;
        }

        switch (dir)
        {
        case DIRECTION_UP:
        case DIRECTION_DOWN:
            minDist[dir] = min(minDist[dir], abs_difY - 1);
            break;
        case DIRECTION_RIGHT:
        case DIRECTION_LEFT:
            minDist[dir] = min(minDist[dir], abs_difX - 1);
            break;
        case DIRECTION_UP_RIGHT:
        case DIRECTION_DOWN_RIGHT:
        case DIRECTION_DOWN_LEFT:
        case DIRECTION_UP_LEFT:
            minDist[dir] = min(minDist[dir], min(abs_difX - 1, abs_difY - 1));
            break;
        default:
            break;
        }
    }

    int ans = 0;
    for (int i = 0; i < MAX_DIRECTION; i++)
        ans += minDist[i];

    return ans;
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int r_q = stoi(second_multiple_input[0]);

    int c_q = stoi(second_multiple_input[1]);

    vector<vector<int>> obstacles(k);

    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        string obstacles_row_temp_temp;
        getline(cin, obstacles_row_temp_temp);

        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int obstacles_row_item = stoi(obstacles_row_temp[j]);

            obstacles[i][j] = obstacles_row_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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
