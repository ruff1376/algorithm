#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int Next[50]; //pattern�� ������ ���λ�, ���̻��� �ִ� ���̸� ������ Next �迭

void InitNext(string p) { //�Է¹��� pattern�� Next �迭�� �������� InitNext() �Լ�
	int i, j, M = p.size(); //M:pattern�� ũ��
	for (i = 0, j = -1; i <= M; i++, j++) { //pattern�� ũ�� +1��ŭ Next �迭 �ʱ�ȭ
		Next[i] = j; //p[0]���� p[i-1]���� ������ ���λ�, ���̻��� �ִ� ���̰� Next[i]�� �ǵ��� �ʱ�ȭ
		while (j >= 0 && p[i] != p[j])
			j = Next[j]; //p[i]�� p[j]�� ��ġ���� �ʴٸ� j�� Next[j]�� ������ (j�� -1�� �ǰų� p[i]�� p[j]�� ����������)
	}
}

void KMP(string p, string t) { //KMP �˰����� �̿��Ͽ� text�� ���� �� pattern�� ��ġ�ϴ� �κ��� index�� ��� ����ϰ� �ϴ� KMP() �Լ�
	int i, j, M = p.size(), N = t.size(); //M:pattern�� ũ��, N:text�� ũ��
	InitNext(p); //pattern�� Next �迭�� ����
	for (i = 0, j = 0; j <= M && i <= N; i++, j++) {
		while (j >= 0 && t[i] != p[j] && j < M)
			j = Next[j]; //t[i]�� p[j]�� ����ġ�� �߻��� ������ ���ϴ� pattern�� index j�� Next[j]�� �ʱ�ȭ
		if (j == M) { //text���� pattern�� ��ġ�� �κ��� ã�� ���
			cout << i - M << " "; //��ġ�ϴ� �κ��� ���� index�� i-M�� �ǹǷ� i-M ���
			j = Next[j] - 1;
			i--; //pattern�� ������ ���λ�, ���̻��� �ִ� ���̸�ŭ �񱳸� ������ i, j ����
		}
	}
}

int main() {
	string txt; //RFC2616 ������ ������ string txt
	int line = 1; //Ž���ϴ� text�� line ��ȣ�� �����ϴ� int line
	ifstream file("RFC2616_modified.txt"); //file ��ü�� 'RFC2616_modified.txt' ������ �о��

	//(1)-1
	/*string t1 = "ababab", t2 = "aaaaa", p1 = "abab", p2 = "aa"; //(1)�� �־��� ������ text�� pattern ����
	KMP(p1, t1); cout << endl; //t1���� ã�� p1�� index
	KMP(p2, t2); cout << endl;*/ //t2���� ã�� p2�� index

	//(1)-2
	/*string p1 = "1", p2 = "*"; //���ڿ� Ư����ȣ pattern ����
	while (getline(file,txt)) { //text�� file�� ������ �� line�� ����
		cout << "<line " << line << ">" << endl; //Ž������ line ��ȣ ���
		cout << p1 << " : "; KMP(p1, txt); cout << endl; //p1 Ž��
		cout << p2 << " : "; KMP(p2, txt); cout << endl; //p2 Ž��
		cout << endl;
		line++; //line ��ȣ ����
	}*/
	//���� text���� pattern ã�� ���� ����

	//(3)
	/*string p1 = "aba", p2 = "aa";
	while (getline(file, txt)) {
		cout << "<line " << line << ">" << endl;
		cout << p1 << " : "; KMP(p1, txt); cout << endl;
		cout << p2 << " : "; KMP(p2, txt); cout << endl;
		cout << endl;
		line++;
	}*/

	//(4)
	/*string p1 = "similar", p2 = "satisfy", p3 = "refer", p4 = "representation", p5 = "connections";
	while (getline(file, txt)) {
		cout << "<line " << line << ">" << endl;
		cout << p1 << " : "; KMP(p1, txt); cout << endl;
		cout << p2 << " : "; KMP(p2, txt); cout << endl;
		cout << p3 << " : "; KMP(p3, txt); cout << endl;
		cout << p4 << " : "; KMP(p4, txt); cout << endl;
		cout << p5 << " : "; KMP(p5, txt); cout << endl;
		cout << endl;
		line++;
	}*/

	file.close(); //���� �ݱ�

	cout << "==============================================" << endl;
	cout << "12151638 ������" << endl;

	return 0;
}