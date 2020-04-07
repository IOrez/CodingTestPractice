#include <iostream>
#include <string>

using namespace std;
template <typename T,const int size>
class Stack
{
public:
	void	Push(T elem);
	T		Pop();
	T   	Top();
	bool	IsFull() { return top == size; }
	bool	IsEmpty() { return top == -1; }
	int		Size() { return top+1; }
private:
	T elems[size];
	int top{-1};
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	string s;
	cin >> N; cin.ignore();
	Stack<int, 20000> st;
	while (N--)
	{
		getline(cin, s);
		int idx = s.find(" ");
		if (idx<0)
		{
			if (s == "top")cout << st.Top() << '\n';
			else if (s == "size")cout << st.Size() << '\n';
			else if(s=="pop")cout << st.Pop() << '\n';
			else if(s=="empty")cout << (int)st.IsEmpty() << '\n';
		}
		else
		{
			int val = stoi(s.substr(idx, s.size()));
			st.Push(val);
		}
	}
	return 0;
}

template <typename T,const int size>
void Stack<T, size>::Push(T elem) {
	if (IsFull())return;
	elems[++top] = elem;
}

template <typename T,const int size>
T Stack<T, size>::Pop(){
	if (IsEmpty())return -1;
	return elems[top--];
}

template <typename T, const int size>
T Stack<T, size>::Top() {
	if (IsEmpty())return -1;
	return elems[top];
}
