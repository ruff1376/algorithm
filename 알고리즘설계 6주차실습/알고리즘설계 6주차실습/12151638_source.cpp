#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

class BinarySearchTree {
public:
	int *node;
	BinarySearchTree() {
		node = new int[512];
		for (int i = 0; i <= 511; i++)
			node[i] = 0;
	}
	~BinarySearchTree() {
		delete[] node;
	}
	int search(int v) {
		if (v < 0) {
			for (int i = 1; i <= 255; i++) {
				if (abs(v) == node[i]) {
					deletev(node[i]);
					return abs(v);
				}
			}
			return 0;
		}
	}
	void insert(int i, int v) {
		if (v > 0) {
			if (node[i] == 0) {
				node[i] = v;
			}
			else if (v < node[i]) {
				i *= 2;
				insert(i, v);
			}
			else {
				i = 2 * i + 1;
				insert(i, v);
			}
		}
		if (v < 0) {
			cout << search(v) << endl;
		}
		if (v == 0) {
			for (int i = 1; i <= 255; i++) {
				if (node[i] != 0) {
					cout << node[i] << " ";
				}
			}
		}
	}
	void deletev(int v) {
		int j, k;
		for (int i = 1; i <= 255; i++) {
			if (v == node[i]) {
				if (node[2 * i] == 0 && node[2 * i + 1] == 0) {
					node[i] = 0;
					break;
				}
				else if (node[2 * i] != 0 && node[2 * i + 1] == 0) {
					if (node[4 * i + 1] == 0) {
						swap(node[i], node[2 * i]);
						deletev(node[2 * i]);
					}
					else {
						for (j = 4 * i + 1; j <= 255; j = 2 * j + 1) {
							if (node[2 * j] == 0 && node[2 * j + 1] == 0) {
								swap(node[i], node[j]);
								node[j] = 0;
								break;
							}
						}
					}
				}
				else {
					if (node[4 * i + 2] == 0) {
						swap(node[i], node[2 * i + 1]);
						deletev(node[2 * i + 1]);
					}
					else {
						for (k = 4 * i + 2; k <= 255; k *= 2) {
							if (node[2 * k] == 0 && node[2 * k + 1] == 0) {
								swap(node[i], node[k]);
								node[k] = 0;
								break;
							}
						}
					}
				}
			}
		}
	}
};

int main() {
	BinarySearchTree bst;
	int v;
	for (;;) {
		cin >> v;
		bst.insert(1, v);
		if (v == 0) break;
	}
	return 0;
}