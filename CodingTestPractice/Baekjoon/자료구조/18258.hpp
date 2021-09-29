#include <iostream>
#include <string>
using namespace std;

class Data {
private:
	int _data;
	Data* _pLink = nullptr;
public:
	Data(int a_data) :_data(a_data) {}
	int GetData() { return _data; }
	Data*& Next() { return _pLink; }
};

class Queue {
private:
	Data* pFront = nullptr, *pBack = nullptr;
	int _size = 0;
public:
	int GetSize() { return _size; }
	bool IsEmpty() { return _size == 0; }
	
	void Push(int data);
	int Pop();

	int Front();
	int Back();
};

void Queue::Push(int data) {
	Data* pData = new Data(data);
	if (IsEmpty())
		pFront = pBack = pData;
	else {
		pBack->Next() = pData;
		pBack = pData;
	}
	_size++;
}

int Queue::Pop() {
	if (IsEmpty())return -1;
	Data* tmp = pFront;
	int value = pFront->GetData();
	pFront = tmp->Next();
	delete tmp;
	_size--;
	return value;
}

int Queue::Front() {
	if (IsEmpty())return -1;
	return pFront->GetData();
}

int Queue::Back() {
	if (IsEmpty())return -1;
	return pBack->GetData();
}

Queue que;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N;
	string str;
	cin >> N;
	cin.ignore();
	while (N--) {
		getline(cin, str);
		auto pos = str.find_last_of(' ');
		if (pos != string::npos) {
			str = str.substr(pos + 1);
			int value = strtol(str.c_str(), NULL, 10);
			que.Push(value);
		}
		else {
			if (str == "pop")
				cout << que.Pop() << '\n';
			else if (str == "front")
				cout << que.Front() << '\n';
			else if (str == "back")
				cout << que.Back() << '\n';
			else if (str == "size")
				cout << que.GetSize() << '\n';
			else if (str == "empty")
				cout << (int)que.IsEmpty() << '\n';
		}
	}
	return 0;
}