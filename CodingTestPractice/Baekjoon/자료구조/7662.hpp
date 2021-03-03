#include <iostream>
#include <string>
#include <queue>
using namespace std;

class DeletableHeap {
public:
	enum class Type{
		MAXHEAP,MINHEAP
	};

public:
	explicit DeletableHeap(Type type) :type_(type) {};

	void Add(long long x);
	void Remove(long long x);
	void Update();
	bool IsEmpty();
	long long  Top();
	void Pop();

private:
	Type type_;
	priority_queue<long long> heap_;
	priority_queue<long long> del_;
};


void DeletableHeap::Add(long long x)
{
	if (type_ == Type::MINHEAP)heap_.push(-x);
	else heap_.push(x);
}

void DeletableHeap::Remove(long long x)
{
	if (type_ == Type::MINHEAP)del_.push(-x);
	else del_.push(x);
}

inline void DeletableHeap::Update()
{
	while (!del_.empty() && heap_.top() == del_.top()) {
		heap_.pop();
		del_.pop();
	}
}

inline bool DeletableHeap::IsEmpty()
{
	Update();
	if (heap_.empty())return true;
	return false;
}

long long DeletableHeap::Top()
{
	Update();
	long long res = heap_.top();
	if (type_ == Type::MINHEAP)res *= -1;
	return res;
}

void DeletableHeap::Pop()
{
	Update();
	heap_.pop();
}

long long t, N, C;
string input;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> t;
	while (t--) {
		DeletableHeap minheap(DeletableHeap::Type::MINHEAP);
		DeletableHeap maxheap(DeletableHeap::Type::MAXHEAP);

		cin >> N; cin.ignore();
		for (int i = 0; i < N; ++i) {
			getline(cin, input);
			C = atoi(input.substr(1).c_str());
			
			switch (input[0]) {
			case 'I':
				minheap.Add(C);
				maxheap.Add(C);
				break;
			case 'D':
				if (minheap.IsEmpty() || maxheap.IsEmpty())continue;
				if (C == 1) {
					minheap.Remove(maxheap.Top());
					if(!maxheap.IsEmpty())
						maxheap.Pop();
				}
				else {
					maxheap.Remove(minheap.Top());
					if (!minheap.IsEmpty())
						minheap.Pop();
				}
				break;
			}
		}
		if (minheap.IsEmpty() || maxheap.IsEmpty())cout << "EMPTY" << '\n';
		else cout << maxheap.Top() << " " << minheap.Top() << '\n';

	}
	return 0;
}