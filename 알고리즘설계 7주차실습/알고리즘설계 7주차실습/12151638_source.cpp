#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

void hashing(int h, char *w, char *d) {
	if (d[h] == NULL) {
		d[h] = w;
	}
	else {
		h++;
		if (h == 26) {
			h = 0;
			hashing(h, w, d);
		}
		hashing(h, w, d);
	}
}

void find(char w) {
	int h, k = w;
	h = k % 26;
}

int main() {
	int a, b, h, index;
	char word[30];
	char *dic[26];
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> word;
		index = word[0];
		h = index % 26;
		hashing(h, word, *dic);
	}
	cin >> word;
	dic[0] = word;
	cout << dic[0] << endl;
	return 0;
}