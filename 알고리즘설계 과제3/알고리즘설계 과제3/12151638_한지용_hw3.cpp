#include<iostream>
#include<stack>
#include<queue>
using namespace std;

const int inf = 10000000; //Bellman-Ford �˰��򿡼� ������� �ʴ� �κ��� �ʱ�ȭ�ϴ� ���

int n, w[100][100], Dist[100], temp[100]; //n:��� ��
										  //w[i][j]:i,j ��� �� ���� ���� or ����ġ
										  //Dist[i]:���� ��忡�� i��� ������ �ִܰŸ�
										  //temp[]:DFS ������ Ž���� ������ �ӽ÷� ������ �迭
bool visited[100], negcycle = false; //visited[]:BFS, DFS Ž�� �� ��� �湮 ����
									 //negcycle:�׷����� ���� ����Ŭ�� �����ϴ��� �Ǻ��ϴ� ����
queue<int> bfs, dfs; //BFS, DFS ������ Ž���� ��带 �����ϴ� queue

void BFS(int s) { //BFS ������ ��带 Ž���ϴ� BFS �Լ� (s:Ž�� ���� ���)
	int i, j, k;
	cout << "Ž�� ���� : ";
	for (i = 0; i < n; i++)
		visited[i] = false; //��� ������ �湮���� ���� ���·� �ʱ�ȭ
	visited[s] = true; //s��� �湮
	queue<int> q; //Ž���� ������ ����� ������ queue ����
	q.push(s); //s��� push
	while (!q.empty()) { //queue�� �� �� ���� ����
		j = q.front(); q.pop(); //queue�� ����� ��� �� ���� ���� ��带 j�� �����ϰ� pop
		visited[j] = true; //j��� �湮
		bfs.push(j); //��带 �湮�� ������� bfs queue�� ��� push
		for (k = 0; k < n; k++)
			if (w[j][k] != 0 && visited[k] == false) { //j�� ����Ǿ� �ִ� ��� �� ���� �湮���� ���� ���
				q.push(k); //��尡 ���� �ͺ��� ���ʴ�� queue�� push
				visited[k] = true; //j�� ����Ǿ� �ִ� ������ �湮�� ���·� ����
				cout << j << "-" << k << " "; //j�� ����Ǿ� �ִ� ������ ���� ���·� ���
			}
	}
	cout << endl << "Ž�� ��� : ";
	for (i = 1; i < n; i++) {
		cout << bfs.front() << "->";
		bfs.pop();
	}
	cout << bfs.front(); //��带 Ž���� ���� ���
}

void DFS(int s) { //DFS ������ ��带 Ž���ϴ� DFS �Լ� (s:Ž�� ���� ���)
	int i, j, k, l = 0;
	for (i = 0; i < n; i++)
		visited[i] = false; //��� ������ �湮���� ���� ���·� �ʱ�ȭ
	stack<int> st; //Ž���� ������ ����� ������ stack ����
	st.push(s); //s��� push
	while (!st.empty()) { //stack�� �� �� ���� ����
		j = st.top(); st.pop(); //���� �ֱٿ� push�� ��带 j�� �����ϰ� pop
		if (visited[j] == false) { //j��尡 �湮�� ���°� �ƴ� ��� ����
			visited[j] = true; //j��带 �湮�� ���·� ����
			dfs.push(j); //��带 �湮�� ������� dfs queue�� ��� push
			temp[l] = j; l++; //��带 �湮�� ������� temp[]�� ��� ����
			for (k = 0; k < n; k++)
				if (w[j][k] != 0 && visited[k] == false) //j�� ����Ǿ� �ִ� ��� �� ���� �湮���� ���� ���
					st.push(k); //��尡 ���� �ͺ��� ���ʴ�� stack�� push
		}
	}
	cout << "Ž�� ���� : "; //Ž���� �������� ������� ���
	for (l = 0; l < n - 1; l++) { //Ž���Ǵ� ������ ���� ��� ������ 1 �۴�
		if (w[temp[l]][temp[l+1]] != 0) //�湮 ������ ������ �� ��尡 ���� ����Ǿ� �ִ� ���
			cout << temp[l] << "-" << temp[l+1] << " "; //�� ��带 ���� ���·� ���
		else { //�湮 ������ ������ �� ��尡 ���� ����Ǿ� ���� ���� ��� (Graph ���ǳ�Ʈ 18�������� ����� ȭ��ǥ case)
			i = l;
			while (w[temp[i]][temp[l + 1]] == 0) i--; //temp[l+1] ���� ����� ��尡 ���� �� ���� i�� �ٿ����� temp[i] Ž��
			cout << temp[i] << "-" << temp[l + 1] << " "; //�� ��带 ���� ���·� ���
		}
	}
	cout << endl << "Ž�� ��� : ";
	for (i = 1; i < n; i++) {
		cout << dfs.front() << "->";
		dfs.pop();
	}
	cout << dfs.front(); //��带 Ž���� ���� ���
}

void BAF(int v) { //Bellman-Ford �˰��� ���� �Լ� (v:���� ���)
	int i, j, k;
	for (i = 0; i < n; i++)
		Dist[i] = w[v][i]; //�ʱ� Dist[]�� v��忡�� i�������� ����ġ�� �ʱ�ȭ
	for (i = 1; i < n; i++) //Dist[]�� n-1ȸ �����ϸ� ���� ����Ŭ�� �������� �ʴ� �� Dist[]�� ���������� ���ŵ�
		for (j = 0; j < n; j++)
			for (k = 0; k < n; k++) //k������ �Ÿ��� j��带 ���� k������ ���� �Ÿ��� ���Ͽ� Dist[] ����
				if (Dist[k] > Dist[j] + w[j][k])
					Dist[k] = Dist[j] + w[j][k]; //j��带 ���� k������ ���� �Ÿ��� �� ª�� ��� Dist[k]�� ����
	for (j = 0; j < n; j++)
		for (k = 0; k < n; k++) //Dist[] ���� ���� �� �ѹ� �� Dist[]�� �����Ͽ� Dist[] ���� �ٲ�ٸ� (Dist[k]�� Dist[j]+w[j][k]���� ū ��찡 �����Ѵٸ�) ���� ����Ŭ�� �����Ѵٰ� �� �� ����
			if (Dist[k] > Dist[j] + w[j][k])
				negcycle = true; //���� ����Ŭ�� �����Ѵٸ� negcycle�� true�� �ʱ�ȭ
}

int main() {
	int i, j, m, a, b, wei, v; //m:���� ��
							   //wei:����ġ
							   //v:Bellman-Ford Ž�� ���� ���
	cout << "��� �� : ";
	cin >> n;
	cout << "���� �� : ";
	cin >> m;

	//(1)
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			w[i][j] = 0;
	cout << "������ �� ��� :" << endl;
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		w[a][b] = 1;
		w[b][a] = 1;
	} //w[][]�� 0�̸� ������� ���� ����, 1�̸� ����� ����
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			if (w[i][j] != 0 && visited[i] == false) { //������ �����ϰ� ���� �湮���� ���� ���� ���� i��带 Ž�� ���� ���� ����
				cout << "<BFS>" << endl; BFS(i);
				cout << endl << "<DFS>" << endl; DFS(i);
				cout << endl;
			} //BFS, DFS Ž�� ��� ���
		}

	//(2)
	/*for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			i == j ? w[i][j] = 0 : w[i][j] = inf; //�ڱ� �ڽ����� ���� ����ġ�� 0, �������� inf�� �ʱ�ȭ
	cout << "(������) (������) (����ġ)" << endl;
	for (i = 0; i < m; i++) {
		cin >> a >> b >> wei;
		w[a][b] = wei;
	} //�׷��� ����
	cout << "������ : ";
	cin >> v; //������ ����
	BAF(v); //BAF �Լ��� �����Ͽ� Dist[] �ʱ�ȭ
	if (negcycle) //���� ����Ŭ�� �����ϴ� ���
		cout << "Negative cycle ����" << endl; //�޽��� ���
	else { //���� ����Ŭ�� �������� �ʴ� ���
		cout << "<��� " << v << "���� �� �������� �ִܰŸ�>" << endl;
		for (i = 0; i < n; i++)
			cout << "��� " << i << " : " << Dist[i] << endl;
	} //���������� �� �������� �ִܰŸ� ���*/

	cout << "========================================================" << endl;
	cout << "12151638 ������" << endl;

	return 0;
}