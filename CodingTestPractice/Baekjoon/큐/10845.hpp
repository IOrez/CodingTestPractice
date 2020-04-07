#include <iostream>
#include <string>
using namespace std;

template <typename T,const int Size>
class Queue
{
public:
	void Push(T elem);
	T Pop();
	T Front();
	T Back();
	int  size();
	bool IsEmpty() { return front == rear; };
	bool IsFull() { return ((rear + 1) % Size) == front; };

private:
	T elems[Size];
	int front{ 0 };
	int rear{ 0 };
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	Queue<int, 20000> que;
	int N;
	cin >> N;
	cin.ignore();
	while (N--)
	{
		getline(cin, s);
		int idx = s.find(" ");
		if (idx < 0)
		{
			if (s == "front")cout << que.Front() << '\n';
			else if(s == "back")cout << que.Back() << '\n';
			else if(s =="size")cout << que.size() << '\n';
			else if(s =="empty")cout << (int)que.IsEmpty() << '\n';
			else if(s == "pop")cout << que.Pop() << '\n';
		}
		else
		{
			int val = stoi(s.substr(idx, s.size()));
			que.Push(val);
		}
	}

	return 0;
}

template <typename T, const int Size>
void Queue<T, Size>::Push(T elem)
{
	if (IsFull())return;
	rear = (rear + 1) % Size;
	elems[rear] = elem;
}

template <typename T,const int Size>
T Queue<T, Size>::Pop()
{
	if (IsEmpty())return -1;
	front = (front + 1) % Size;
	return elems[front];
}

template <typename T,const int Size>
T Queue<T, Size>::Front()
{
	if (IsEmpty())return -1;
	return elems[(front + 1) % Size];
}

template <typename T,const int Size>
T Queue<T, Size>::Back()
{
	if (IsEmpty())return -1;
	return elems[rear];
}

template <typename T, const int Size>
int Queue<T, Size>::size()
{
	auto i = front;
	int count = 0;
	while (i != rear)
	{
		++count;
		i = (i + 1) % Size;
	}
	return count;
}