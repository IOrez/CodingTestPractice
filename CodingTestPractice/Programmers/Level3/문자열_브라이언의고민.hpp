#include <string>
#include <stack>
#include <iostream>
using namespace std;

#define ERROR -1


const int Size = 'z' - 'a' + 1;
bool used[Size];
char pres = '.';

int check( string& ans, string& sent) {
    int len = sent.size();
    bool upperused = false, fc = false;
    stack<char> st;
    for (int i = 0; i < len; ++i) {
        if (!isalpha(sent[i]))return ERROR;
        if (isupper(sent[i])) {
            if (i >= 1 && isupper(sent[i - 1])) {
                if (st.size()!=1&&!fc)return ERROR;
                else if (fc) {
                    st.pop();
                    ans += ' ';
                }
            }
            if (st.empty())fc = true;
            upperused = true;
            ans += sent[i];
        }
        else {
            if (st.size() == 0) {
                if (used[sent[i] - 'a'])return ERROR;
                st.push(sent[i]);
                used[sent[i] - 'a'] = true;
            }
            else if (st.size() == 1) {
                char ch = st.top();
                if (!upperused)return ERROR;
                else if (ch != sent[i]){
                    if (used[sent[i] - 'a'])return ERROR;
                    else if (fc) {
                        ans += ' ';
                        fc = false;
                        st.pop();
                    }
                    st.push(sent[i]);
                    used[sent[i] - 'a'] = true;
                }
                else if(!fc){
                    if(i+1!=len)
                        ans += ' ';
                    fc = false;
                    st.pop();
                }
            }
            else {
                char ch1, ch2;
                ch1 = st.top(); st.pop();
                ch2 = st.top();
                if (!upperused)return ERROR;
                else if ((ch1 != sent[i]) && (ch2 != sent[i]))return ERROR;
                else if (ch1 == sent[i])st.push(ch1);
                else if (ch2 == sent[i]) {
                    ans += ' ';
                    st.pop();
                }
            }
            upperused = false;
        }
    }
    return 0;
}

string solution(string sentence) {
    string answer = "";
    if (check(answer, sentence) == ERROR)
        answer = "invalid";

    return answer;
}

int main() {
   /* cout << solution("HaEaLaLaObWORLDb")<<'\n';
    cout << solution("SpIpGpOpNpGJqOqA")<<'\n';
    cout << solution("AxAxAxAoBoBoB")<<'\n';*/
    cout << solution("XcXbXcX") << '\n';
}