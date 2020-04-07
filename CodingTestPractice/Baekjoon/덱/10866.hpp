#include <iostream>
#include <string>
using namespace std;

template <typename T, const int Size>
class Deque
{
public:
	void Push_Front(T elem);
	void Push_Back(T elem);
	T Pop_Front();
	T Pop_Back();
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
	Deque<int, 20000> que;
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
			else if (s == "back")cout << que.Back() << '\n';
			else if (s == "size")cout << que.size() << '\n';
			else if (s == "empty")cout << (int)que.IsEmpty() << '\n';
			else if (s == "pop_front")cout << que.Pop_Front() << '\n';
			else if (s == "pop_back")cout << que.Pop_Back() << '\n';
		}
		else
		{
			string sub(s.begin(), s.begin() + idx);
			int val = stoi(s.substr(idx, s.size()));
			if (sub == "push_front")que.Push_Front(val);
			else if (sub == "push_back")que.Push_Back(val);
		}
	}

	return 0;
}

template <typename T, const int Size>
void Deque<T, Size>::Push_Back(T elem)
{
	if (IsFull())return;
	rear = (rear + 1) % Size;
	elems[rear] = elem;
}

template <typename T,const int Size>
void Deque<T, Size>::Push_Front(T elem)
{
	if (IsFull())return;
	elems[front] = elem;
	front = (front - 1) % Size;
	if (front < 0)front = Size + front;
}


template <typename T, const int Size>
T Deque<T, Size>::Pop_Front()
{
	if (IsEmpty())return -1;
	front = (front + 1) % Size;
	return elems[front];
}

template <typename T, const int Size>
T Deque<T, Size>::Pop_Back()
{
	if (IsEmpty())return -1;
	int item = elems[rear];
	rear = (rear - 1) % Size;
	if (rear < 0)rear = Size + rear;
	return item;
}

template <typename T, const int Size>
T Deque<T, Size>::Front()
{
	if (IsEmpty())return -1;
	return elems[(front + 1) % Size];
}

template <typename T, const int Size>
T Deque<T, Size>::Back()
{
	if (IsEmpty())return -1;
	return elems[rear];
}

template <typename T, const int Size>
int Deque<T, Size>::size()
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