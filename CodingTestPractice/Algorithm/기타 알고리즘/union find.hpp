#include <iostream>

int group[1000];

void Init() {
	for (int i = 0; i < 1000; ++i)
		group[i] = i;
}

int FindGroup(int a) {
	if (group[a] == a)return group[a];
	return group[a] = FindGroup(group[a]);
}

bool CheckSameGroup(int a, int b) {
	int group_a = FindGroup(a);
	int group_b = FindGroup(b);

	return group_a == group_b;
}

void UnionFind(int a, int b) {
	int group_a = FindGroup(a);
	int group_b = FindGroup(b);

	if (group_a < group_b)group[group_b] = group_a;
	else group[group_a] = group_b;
}