#include<iostream>
#include<vector>
using namespace std;

void swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

/*void heapify(int root, int left, int right) {
	
	if (right == NULL) {
		if (root < left) {
			int temp = root;
			root = left;
			left = temp;
		}
	}
	if (root < left&&root < right) {
		if (left < right) {
			int temp = root;
			root = right;
			right = temp;
		}
		else {
			int temp = root;
			root = left;
			left = temp;
		}
	}
	if (root < left) {
		int temp = root;
		root = left;
		left = temp;
	}
	if (root < right) {
		int temp = root;
		root = right;
		right = temp;
	}
}*/

int main() {
	vector<int> v1,v2;
	int n,alphaelement,betaelement;
	cin >> n;
	int alpha[101], beta[101];

	//v1.push_back(NULL);
	/*v1.push_back(6);
	v1.push_back(2);
	v1.push_back(8);
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(9);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(10);
	v1.push_back(7);
	v1.push_back(NULL);*/

	for (int i = 1; i < n+1; i++) {
		cin >> alphaelement;
		alpha[i]=alphaelement;
	}
	for (int i = 1; i < n + 1; i++) {
		cin >> betaelement;
		beta[i] = betaelement;
	}

	for (int i = 1; i < n + 1; i++) {
		if (alpha[i * 2] != NULL) {
			if (alpha[i * 2 + 1] != NULL) {
				if (alpha[i] < alpha[i * 2]||alpha[i]< alpha[i * 2 + 1]) {
					swap(alpha[i], alpha[i * 2]);
				}
			}
		}
	}
	/*for (int i = 0; i < n; i++) {
		cin >> beta;
		v2.push_back(beta);
	}*/
	/*for (int i = n + 1; i < n * 2 + 2; i++) {
		v1.push_back(NULL);
		v2.push_back(NULL);
	}

	int s = (v1.size() - 2) / 2;

	for (int i = 1; i <= s; i++) {
		heapify(v1[i], v1[i * 2], v1[i * 2 + 1]);
		for (; (i / 2) != 1; i /= 2) {
			if (i % 2 == 0)
				heapify(v1[i / 2], v1[i], v1[i + 1]);
			else
				heapify(v1[i / 2], v1[i - 1], v1[i]);
		}
	}
	for (int i = 1; i <= 2 * s; i++) {
		cout << v1[1] << " ";
		v1[1] = v1[v1.size() - i - 1];
		v1[v1.size() - i - 1] = NULL;
		heapify(v1[1], v1[2], v1[3]);
	}
	cout << endl;*/

	/*for (int i = 1; i < n + 1; i++) {
		if (v1[i * 2] != NULL) {
			if (v1[i * 2 + 1] != NULL) {
				if()
			}
		}
	}*/
	
	return 0;
}