#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;

void InitNext(string p, int *next) { //KMP InitNext 정의
	int i, j, M = p.size();
	next[0] = -1;
	for (i = 0, j = -1; i <= M; i++, j++) {
		next[i] = j;
		//next[i] = (p[i] == p[j]) ? next[j] : j;
		while ((j >= 0) && (p[i] != p[j]))
			j = next[j];
	}
}

/*int kmp(string p, string t, int *next) { //KMP 구현
	int i, j, M = p.size(), N = t.size();
	InitNext(p, next);
	for (i = 0, j = 0; j < M && i < N; i++, j++)
		while (j >= 0 && t[i] != p[j])
			j = next[j];
	if (j == M)
		return i - M;
	else
		return i;
}*/

void printKMP(string p, string t, int *next) { //KMP 구현
	int i, j, M = p.size(), N = t.size();
	InitNext(p, next);
	for (i = 0, j = 0; j <= M && i <= N; i++, j++) {
		while (j >= 0 && (t[i] != p[j]) && j < M)
			j = next[j];
		if (j == M) {
			cout << i - M << endl;
			j = next[j] - 1;
			i--;
		}
	}
}

int main() {
	int next[100];
	string t = "AABAAbabcababAABAAaabbabAABAAaab";
	string p = "AABAA";
	printKMP(p, t, next);
	/*InitNext(t, next);
	for (int i = 0; i < t.size(); i++)
		cout << next[i] << " ";
	cout << endl;*/
	/*pair<int, string> t[100];
	string p, text;
	int next[100];
	cin >> p;
	int i;
	for (i = 0;; i++) {
		cin >> text;
		if (text == "0") break;
		t[i] = make_pair(kmp(p, text, next), text);
	}
	stable_sort(t, t + i);
	
	for (int j = 0; j < i; j++)
		cout << t[j].second << endl;*/

	return 0;
}