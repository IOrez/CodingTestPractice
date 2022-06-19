#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <climits>

using namespace std;

typedef struct timedata
{
    int m_sTot;
    int m_eTot;
    int m_dTot;
};

int solution(vector<string> lines) {
    int answer = 0;
    int cnt = lines.size();
    int nHour, nMin, nSec, nmSec;
    int ndSec, nmdSec;

    vector<timedata> vec(cnt);
    string timeFormat = "(\\d{2}):(\\d{2}):(\\d{2}).(\\d{3})";
    string duringFormat = "(\\d{1}).?(\\d*)";
    for (int i = 0; i < cnt; ++i)
    {
        string strtime = lines[i];
        auto siter = find(lines[i].begin(), lines[i].end(), ' ');
        auto eiter = find(siter+1, lines[i].end(), ' ');

        nHour = 0, nMin = 0, nSec = 0, nmSec = 0;
        ndSec = 0, nmdSec = 0;
        std::regex timeRegex(timeFormat);
        std::smatch match;
        const string tstr = string(siter + 1, eiter).c_str();
        const string dstr = string(eiter + 1, lines[i].end()-1).c_str();
        if (std::regex_match(tstr, match, timeRegex))
        {
            for (size_t j = 0; j < match.size(); ++j)
            {
                if (match[j].length() == 0)
                    continue;
                switch (j)
                {
                case 1:
                    nHour = stoi(match[j].str());
                    break;
                case 2:
                    nMin = stoi(match[j].str());
                    break;
                case 3:
                    nSec = stoi(match[j].str());
                    break;
                case 4:
                    nmSec = stoi(match[j].str());
                    break;
                default:
                    break;
                }
            }
            vec[i].m_eTot = nHour * 3600000 + nMin * 60000 + nSec*1000 + nmSec;
        }

        std::regex duringRegex(duringFormat);
        if (std::regex_match(dstr, match, duringRegex))
        {
            for (size_t j = 0; j < match.size(); ++j)
            {
                if (match[j].length() == 0)
                    continue;
                switch (j)
                {
                case 1:
                    ndSec = stoi(match[j].str());
                    break;
                case 2:
                    nmdSec = stoi(match[j].str());
                    break;
                default:
                    break;
                }
            }
            vec[i].m_dTot = ndSec*1000 + nmdSec;
        }
        vec[i].m_sTot = vec[i].m_eTot - vec[i].m_dTot + 1;
    }

    int maxCount = INT_MIN;
    for (int i = 0; i < cnt; ++i)
    {
        int stime = vec[i].m_sTot;
        int etime = vec[i].m_eTot;
        int count = 0;
        for (int j = stime; j <= etime; j+=1000)
        {
            count = 0;
            for (int k = 0; k < cnt; ++k) 
            {
                if (vec[k].m_eTot < j || j + 1000 <= vec[k].m_sTot )
                    continue;
                count++;
            }
            maxCount = (count > maxCount) ? count : maxCount;
        }

        count = 0;
        for (int k = 0; k < cnt; ++k)
        {
            if (vec[k].m_eTot < etime || etime + 1000 <= vec[k].m_sTot)
                continue;
            count++;
        }
        maxCount = (count > maxCount) ? count : maxCount;
    }

    answer = maxCount;
    return answer;
}

int main()
{
    vector<string> lines = vector<string>{
       "2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"
    };

   int answer =  solution(lines);
   return 0;
}