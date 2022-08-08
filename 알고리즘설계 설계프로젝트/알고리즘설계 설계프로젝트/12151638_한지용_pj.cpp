#include<iostream>
#include<cmath>
#include<cstdlib>
#include<time.h>
using namespace std;

int i, n, placedqueen = 1, board[15]; //i:체스판 0번째행 퀸의 위치, n:체스판 한 변 칸수, placedqueen:배치된 퀸의 수, board[x]:x행의 퀸의 위치

bool place(int x, int y) { //(x,y)에 퀸이 배치 가능한지 알려주는 함수
	for (int l = 0; l < x; l++) //x행 위의 퀸들에 대해 배치 가능한지 판별
		if (board[l] == y || abs(x - l) == abs(y - board[l])) //퀸이 같은 열에 있거나 대각선 위치에 있는 경우
			return false; //place(x,y)=false
	return true; //그 외의 경우 place(x,y)=true
}

void n_queens(int x, int y) { //(x,y)부터 배치 가능한 퀸의 위치를 board[]에 초기화
	int j, k = y; //퀸의 열은 y열부터 판별
	if (y >= n) { //퀸을 x열에 배치 불가능한 경우
		placedqueen--; //배치된 퀸의 수 -1
		n_queens(x - 1, board[x - 1] + 1); //이전 행으로 돌아간 후 재탐색
	}
	else {
		for (j = x; j < n; j++) { //행
			for (; k < n; k++) { //열
				if (place(j, k)) { //퀸을 배치 가능하면
					board[j] = k; //(j,k)에 퀸 배치
					placedqueen++; //배치된 퀸의 수 +1
					k = 0; //(j+1,0)부터 이어서 탐색
					break; //for문 탈출
				}
			}
			if (placedqueen == n) break; //퀸이 모두 배치 되었으면 for문 탈출
			if (k == n) { //한 행의 마지막 열까지 퀸을 배치할 수 없는 경우
				placedqueen--; //배치된 퀸의 수 -1
				n_queens(j - 1, board[j - 1] + 1); //이전 행으로 돌아간 후 재탐색
			}
		}
	}
}

int main() {
	time_t start, end; //측정 시작, 끝 지점 변수 선언
	double result; //수행시간 
	cin >> n; //n 입력

	start = clock(); //측정 시작
	for (i = 0; i < n; i++){
		board[0] = i; //0번째 행에 퀸 배치
		n_queens(1, 0); //1번째 행 0번째
		if (placedqueen == n) break; //퀸이 모두 배치 되었으면 for문 탈출
		else placedqueen = 1; //그 외의 경우 0번째 행 퀸의 위치 재조정
	}
	end = clock(); //측정 종료
	result = (double)(end - start); //result에 측정된 수행시간 저장
	printf("Backtracking : %f ms\n", result); //backtracking 수행시간 출력

	cout << "========================================================" << endl;
	cout << "12151638 한지용" << endl;
	return 0;
}