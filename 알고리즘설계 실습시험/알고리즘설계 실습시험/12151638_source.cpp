#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;

struct Node {
	char symbol;
	int freq;
	Node* parent;
	Node* left;
	Node* right;
};

/*class minheap {
public:
	minheap() {
		root = NULL;
		s = 0;
	}
	bool isroot(Node* n) {
		return n->parent == NULL;
	}
	bool isempty() {

	}
	void insert(Node* n) {
		if (isroot(n))
	}
private:
	Node* root;
	int s;
};*/

int main() {
	pair<int, char> p[26];
	char arr[100];
	int count[26] = { 0, };
	int freq[26];
	int bit[26] = { 0, };
	int j = 0;
	cin >> arr;
	for (int i = 0; i < (int)strlen(arr); i++) {
		if (arr[i] == 'a') count[0]++;
		if (arr[i] == 'b') count[1]++;
		if (arr[i] == 'c') count[2]++;
		if (arr[i] == 'd') count[3]++;
		if (arr[i] == 'e') count[4]++;
		if (arr[i] == 'f') count[5]++;
		if (arr[i] == 'g') count[6]++;
		if (arr[i] == 'h') count[7]++;
		if (arr[i] == 'i') count[8]++;
		if (arr[i] == 'j') count[9]++;
		if (arr[i] == 'k') count[10]++;
		if (arr[i] == 'l') count[11]++;
		if (arr[i] == 'm') count[12]++;
		if (arr[i] == 'n') count[13]++;
		if (arr[i] == 'o') count[14]++;
		if (arr[i] == 'p') count[15]++;
		if (arr[i] == 'q') count[16]++;
		if (arr[i] == 'r') count[17]++;
		if (arr[i] == 's') count[18]++;
		if (arr[i] == 't') count[19]++;
		if (arr[i] == 'u') count[20]++;
		if (arr[i] == 'v') count[21]++;
		if (arr[i] == 'w') count[22]++;
		if (arr[i] == 'x') count[23]++;
		if (arr[i] == 'y') count[24]++;
		if (arr[i] == 'z') count[25]++;
	}
	for (int i = 0; i < 26; i++) {
		if (count[i] != 0) {
			p[j] = make_pair(count[i], (char)(i + 97));
			j++;
		}
	}
	
	stable_sort(p, p + j);
	for (int i = 0; i < j; i++) {
		freq[i] = p[i].first;
	}
	for (int i = 0; i < j - 1; i++) {
		p[i].first=p[i].first + p[i + 1].first;
		p[i + 1].first = 0;
		bit[i]++; bit[i + 1]++;
		stable_sort(p, p + j);
	}

	int sum = 0;

	for (int i = 0; i < j; i++)
		sum += freq[i] * bit[i];
	cout << sum << endl;

	return 0;
}