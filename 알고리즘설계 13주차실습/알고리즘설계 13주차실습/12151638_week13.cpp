#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

int R, N, m[108][108][108];
bool visited[108][108][108];

int start(int n) {
	if (n >= 0) return n;
	else return 0;
}

int end(int n) {
	if (n <= N - 1) return n;
	else return n - 1;
}

void DFS(int s, int n) {
	int i, j, k, star[100][100][100];
	
	stack<int> st;
	st.push(s);
	while (!st.empty()) {
		j = st.top();
		st.pop();
		if (visited[j] == false) {
			st.push(j);
			visited[j] = true;
			if (j - R >= 0 && j + R <= N - 1) {
				for (k = j - R; k <= j + R; k++)
					if (visited[k] == false)
						st.push(k);
			}
			if (j - R >= 0 && j + R > N - 1) {
				for (k = j - R; k < N; k++)
					if (visited[k] == false)
						st.push(k);
			}
			if (j - R < 0 && j + R <= N - 1) {
				for (k = 0; k <= j + R; k++)
					if (visited[k] == false)
						st.push(k);
			}
			if (j - R < 0 && j + R > N - 1) {
				for (k = 0; k < N; k++)
					if (visited[k] == false)
						st.push(k);
			}
		}
	}
}

int main() {
	int i, j, k, x, y, z, t;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			for (k = 0; k < N; k++)
				visited[i][j][k] = false;
	cin >> R >> N;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			for (k = 0; k < N; k++)
				cin >> m[i][j][k];
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			for (k = 0; k < N; k++) {
				if (m[i][j][k] == 1 && visited[i][j][k] == false) {
					x = i; y = j; z = k;
					if (x - R >= 0 && x + R <= N - 1) {
						if (y - R >= 0 && y + R <= N - 1) {
							if (z - R >= 0 && z + R <= N - 1) {

							}
						}
						for (t = j - R; t <= j + R; t++)
							if (visited[t] == false)
								st.push(t);
					}
					if (x - R >= 0 && x + R > N - 1) {
						for (k = j - R; k < N; k++)
							if (visited[k] == false)
								st.push(k);
					}
					if (x - R < 0 && x + R <= N - 1) {
						for (k = 0; k <= j + R; k++)
							if (visited[k] == false)
								st.push(k);
					}
					if (x - R < 0 && x + R > N - 1) {
						for (k = 0; k < N; k++)
							if (visited[k] == false)
								st.push(k);
					}
				}
			}
}