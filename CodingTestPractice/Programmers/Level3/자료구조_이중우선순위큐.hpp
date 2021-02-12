#include <string>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;


deque<int> dq;


vector<int> solution(vector<string> operations) {
    for (auto& s : operations) {
        char oper = s[0];
        int num = stoi(s.substr(2));
        switch (oper) {
        case 'I':
            dq.push_back(num);
            sort(dq.begin(), dq.end());
            break;
        case 'D':
            if (dq.empty())continue;
            if (num == 1)
                dq.pop_back();
            else
                dq.pop_front();
            break;
        }
    }
    vector<int> answer;
    if (dq.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    
    return answer;
}


int main() {
    return 0;
}