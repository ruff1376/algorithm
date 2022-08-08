#include<iostream>
#include<cmath>
#include<cstdlib>
#include<time.h>
using namespace std;

int i, n, placedqueen = 1, board[15]; //i:ü���� 0��°�� ���� ��ġ, n:ü���� �� �� ĭ��, placedqueen:��ġ�� ���� ��, board[x]:x���� ���� ��ġ

bool place(int x, int y) { //(x,y)�� ���� ��ġ �������� �˷��ִ� �Լ�
	for (int l = 0; l < x; l++) //x�� ���� ���鿡 ���� ��ġ �������� �Ǻ�
		if (board[l] == y || abs(x - l) == abs(y - board[l])) //���� ���� ���� �ְų� �밢�� ��ġ�� �ִ� ���
			return false; //place(x,y)=false
	return true; //�� ���� ��� place(x,y)=true
}

void n_queens(int x, int y) { //(x,y)���� ��ġ ������ ���� ��ġ�� board[]�� �ʱ�ȭ
	int j, k = y; //���� ���� y������ �Ǻ�
	if (y >= n) { //���� x���� ��ġ �Ұ����� ���
		placedqueen--; //��ġ�� ���� �� -1
		n_queens(x - 1, board[x - 1] + 1); //���� ������ ���ư� �� ��Ž��
	}
	else {
		for (j = x; j < n; j++) { //��
			for (; k < n; k++) { //��
				if (place(j, k)) { //���� ��ġ �����ϸ�
					board[j] = k; //(j,k)�� �� ��ġ
					placedqueen++; //��ġ�� ���� �� +1
					k = 0; //(j+1,0)���� �̾ Ž��
					break; //for�� Ż��
				}
			}
			if (placedqueen == n) break; //���� ��� ��ġ �Ǿ����� for�� Ż��
			if (k == n) { //�� ���� ������ ������ ���� ��ġ�� �� ���� ���
				placedqueen--; //��ġ�� ���� �� -1
				n_queens(j - 1, board[j - 1] + 1); //���� ������ ���ư� �� ��Ž��
			}
		}
	}
}

int main() {
	time_t start, end; //���� ����, �� ���� ���� ����
	double result; //����ð� 
	cin >> n; //n �Է�

	start = clock(); //���� ����
	for (i = 0; i < n; i++){
		board[0] = i; //0��° �࿡ �� ��ġ
		n_queens(1, 0); //1��° �� 0��°
		if (placedqueen == n) break; //���� ��� ��ġ �Ǿ����� for�� Ż��
		else placedqueen = 1; //�� ���� ��� 0��° �� ���� ��ġ ������
	}
	end = clock(); //���� ����
	result = (double)(end - start); //result�� ������ ����ð� ����
	printf("Backtracking : %f ms\n", result); //backtracking ����ð� ���

	cout << "========================================================" << endl;
	cout << "12151638 ������" << endl;
	return 0;
}