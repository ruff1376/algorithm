#include<iostream>
#include<stack>
#include<queue>
using namespace std;

const int inf = 10000000; //Bellman-Ford 알고리즘에서 연결되지 않는 부분을 초기화하는 상수

int n, w[100][100], Dist[100], temp[100]; //n:노드 수
										  //w[i][j]:i,j 노드 간 연결 상태 or 가중치
										  //Dist[i]:기준 노드에서 i노드 까지의 최단거리
										  //temp[]:DFS 순서로 탐색한 노드들을 임시로 저장할 배열
bool visited[100], negcycle = false; //visited[]:BFS, DFS 탐색 시 노드 방문 여부
									 //negcycle:그래프에 음의 사이클이 존재하는지 판별하는 변수
queue<int> bfs, dfs; //BFS, DFS 순서로 탐색한 노드를 저장하는 queue

void BFS(int s) { //BFS 순서로 노드를 탐색하는 BFS 함수 (s:탐색 시작 노드)
	int i, j, k;
	cout << "탐색 간선 : ";
	for (i = 0; i < n; i++)
		visited[i] = false; //모든 노드들을 방문하지 않은 상태로 초기화
	visited[s] = true; //s노드 방문
	queue<int> q; //탐색할 노드들의 목록을 저장할 queue 생성
	q.push(s); //s노드 push
	while (!q.empty()) { //queue가 빌 때 까지 실행
		j = q.front(); q.pop(); //queue에 저장된 노드 중 가장 앞의 노드를 j에 저장하고 pop
		visited[j] = true; //j노드 방문
		bfs.push(j); //노드를 방문한 순서대로 bfs queue에 노드 push
		for (k = 0; k < n; k++)
			if (w[j][k] != 0 && visited[k] == false) { //j와 연결되어 있는 노드 중 아직 방문하지 않은 노드
				q.push(k); //노드가 작은 것부터 차례대로 queue에 push
				visited[k] = true; //j와 연결되어 있는 노드들을 방문한 상태로 갱신
				cout << j << "-" << k << " "; //j와 연결되어 있는 노드들을 간선 형태로 출력
			}
	}
	cout << endl << "탐색 노드 : ";
	for (i = 1; i < n; i++) {
		cout << bfs.front() << "->";
		bfs.pop();
	}
	cout << bfs.front(); //노드를 탐색한 순서 출력
}

void DFS(int s) { //DFS 순서로 노드를 탐색하는 DFS 함수 (s:탐색 시작 노드)
	int i, j, k, l = 0;
	for (i = 0; i < n; i++)
		visited[i] = false; //모든 노드들을 방문하지 않은 상태로 초기화
	stack<int> st; //탐색할 노드들의 목록을 저장할 stack 생성
	st.push(s); //s노드 push
	while (!st.empty()) { //stack이 빌 때 까지 실행
		j = st.top(); st.pop(); //가장 최근에 push한 노드를 j에 저장하고 pop
		if (visited[j] == false) { //j노드가 방문한 상태가 아닐 경우 실행
			visited[j] = true; //j노드를 방문한 상태로 갱신
			dfs.push(j); //노드를 방문한 순서대로 dfs queue에 노드 push
			temp[l] = j; l++; //노드를 방문한 순서대로 temp[]에 노드 저장
			for (k = 0; k < n; k++)
				if (w[j][k] != 0 && visited[k] == false) //j와 연결되어 있는 노드 중 아직 방문하지 않은 노드
					st.push(k); //노드가 작은 것부터 차례대로 stack에 push
		}
	}
	cout << "탐색 간선 : "; //탐색한 간선들을 순서대로 출력
	for (l = 0; l < n - 1; l++) { //탐색되는 간선의 수는 노드 수보다 1 작다
		if (w[temp[l]][temp[l+1]] != 0) //방문 순서가 인접한 두 노드가 서로 연결되어 있는 경우
			cout << temp[l] << "-" << temp[l+1] << " "; //두 노드를 간선 형태로 출력
		else { //방문 순서가 인접한 두 노드가 서로 연결되어 있지 않은 경우 (Graph 강의노트 18페이지의 보라색 화살표 case)
			i = l;
			while (w[temp[i]][temp[l + 1]] == 0) i--; //temp[l+1] 노드와 연결된 노드가 나올 때 까지 i를 줄여가며 temp[i] 탐색
			cout << temp[i] << "-" << temp[l + 1] << " "; //두 노드를 간선 형태로 출력
		}
	}
	cout << endl << "탐색 노드 : ";
	for (i = 1; i < n; i++) {
		cout << dfs.front() << "->";
		dfs.pop();
	}
	cout << dfs.front(); //노드를 탐색한 순서 출력
}

void BAF(int v) { //Bellman-Ford 알고리즘 실행 함수 (v:시작 노드)
	int i, j, k;
	for (i = 0; i < n; i++)
		Dist[i] = w[v][i]; //초기 Dist[]를 v노드에서 i노드까지의 가중치로 초기화
	for (i = 1; i < n; i++) //Dist[]를 n-1회 갱신하면 음의 사이클이 존재하지 않는 한 Dist[]가 최종적으로 갱신됨
		for (j = 0; j < n; j++)
			for (k = 0; k < n; k++) //k노드까지 거리와 j노드를 거쳐 k노드까지 가는 거리를 비교하여 Dist[] 갱신
				if (Dist[k] > Dist[j] + w[j][k])
					Dist[k] = Dist[j] + w[j][k]; //j노드를 거쳐 k노드까지 가는 거리가 더 짧은 경우 Dist[k]를 갱신
	for (j = 0; j < n; j++)
		for (k = 0; k < n; k++) //Dist[] 최종 갱신 후 한번 더 Dist[]를 갱신하여 Dist[] 값이 바뀐다면 (Dist[k]가 Dist[j]+w[j][k]보다 큰 경우가 존재한다면) 음의 사이클이 존재한다고 볼 수 있음
			if (Dist[k] > Dist[j] + w[j][k])
				negcycle = true; //음의 사이클이 존재한다면 negcycle을 true로 초기화
}

int main() {
	int i, j, m, a, b, wei, v; //m:간선 수
							   //wei:가중치
							   //v:Bellman-Ford 탐색 시작 노드
	cout << "노드 수 : ";
	cin >> n;
	cout << "간선 수 : ";
	cin >> m;

	//(1)
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			w[i][j] = 0;
	cout << "연결할 두 노드 :" << endl;
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		w[a][b] = 1;
		w[b][a] = 1;
	} //w[][]가 0이면 연결되지 않은 상태, 1이면 연결된 상태
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			if (w[i][j] != 0 && visited[i] == false) { //간선이 존재하고 아직 방문하지 않은 가장 작은 i노드를 탐색 시작 노드로 설정
				cout << "<BFS>" << endl; BFS(i);
				cout << endl << "<DFS>" << endl; DFS(i);
				cout << endl;
			} //BFS, DFS 탐색 결과 출력
		}

	//(2)
	/*for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			i == j ? w[i][j] = 0 : w[i][j] = inf; //자기 자신으로 가는 가중치는 0, 나머지는 inf로 초기화
	cout << "(시작점) (도착점) (가중치)" << endl;
	for (i = 0; i < m; i++) {
		cin >> a >> b >> wei;
		w[a][b] = wei;
	} //그래프 생성
	cout << "시작점 : ";
	cin >> v; //시작점 설정
	BAF(v); //BAF 함수를 실행하여 Dist[] 초기화
	if (negcycle) //음의 사이클이 존재하는 경우
		cout << "Negative cycle 존재" << endl; //메시지 출력
	else { //음의 사이클이 존재하지 않는 경우
		cout << "<노드 " << v << "에서 각 노드까지의 최단거리>" << endl;
		for (i = 0; i < n; i++)
			cout << "노드 " << i << " : " << Dist[i] << endl;
	} //시작점부터 각 노드까지의 최단거리 출력*/

	cout << "========================================================" << endl;
	cout << "12151638 한지용" << endl;

	return 0;
}