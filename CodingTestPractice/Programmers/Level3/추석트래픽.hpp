#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#pragma warning(disable:4996)

using namespace std;

#define BUF_SIZE	99999999

int buff[BUF_SIZE] = { 0 };

int solution(vector<string> lines)
{
	int answer = 0;
	for (int i = 0; i < lines.size(); ++i)
	{
		int end = 0;
		int elapsed_time;
		int y, m, d, hh, mm, ss, zzz;
		double elapsed_double;
		sscanf(lines[i].c_str(), "%d-%d-%d %d:%d:%d.%d %lfs", &y, &m, &d, &hh, &mm, &ss, &zzz, &elapsed_double);
		
		elapsed_time = (int)(elapsed_double * 1000);

		end += hh * 60;
		end == mm;
		end *= 60;
		end += ss;
		end *= 1000;
		end += zzz;

		for (int j = end - (elapsed_time - 1) - 999; j <= end; j++)
		{
			if (j < 0 || j >= BUF_SIZE)
				continue;
			buff[j] += 1;
			answer = max(answer, buff[i]);
		}

		return answer;
	}
}