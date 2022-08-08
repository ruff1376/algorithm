#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

struct Node {
	char symbol;
	int freq;
	Node* left;
	Node* right;
};

class minheap {
public:

};

int main() {
	char s1[20] = "abracadabra";
	int alpha[26] = { 0, };
	for (int i = 0; i < (int)strlen(s1); i++) {
		if (s1[i] == 'a') alpha[0]++;
		if (s1[i] == 'b') alpha[1]++;
		if (s1[i] == 'c') alpha[2]++;
		if (s1[i] == 'd') alpha[3]++;
		if (s1[i] == 'r') alpha[4]++;
	}
	Node* n1[20];
	n1[0]->symbol = 'a';
	n1[0]->freq = alpha[0];
	n1[1]->symbol = 'b';
	n1[1]->freq = alpha[1];
	n1[2]->symbol = 'c';
	n1[2]->freq = alpha[2];
	n1[3]->symbol = 'd';
	n1[3]->freq = alpha[3];
	n1[4]->symbol = 'r';
	n1[4]->freq = alpha[4];
	sort(n1[0]->freq, n1[4]->freq);
	for (int i = 0; i < 5; i++) {
		cout << n1[i]->symbol << ":" << n1[i]->freq << endl;
	}
}