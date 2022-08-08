#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int Next[50]; //pattern의 동일한 접두사, 접미사의 최대 길이를 저장할 Next 배열

void InitNext(string p) { //입력받은 pattern의 Next 배열을 지정해줄 InitNext() 함수
	int i, j, M = p.size(); //M:pattern의 크기
	for (i = 0, j = -1; i <= M; i++, j++) { //pattern의 크기 +1만큼 Next 배열 초기화
		Next[i] = j; //p[0]부터 p[i-1]까지 동일한 접두사, 접미사의 최대 길이가 Next[i]가 되도록 초기화
		while (j >= 0 && p[i] != p[j])
			j = Next[j]; //p[i]와 p[j]가 일치하지 않다면 j를 Next[j]로 재지정 (j가 -1이 되거나 p[i]와 p[j]가 같을때까지)
	}
}

void KMP(string p, string t) { //KMP 알고리즘을 이용하여 text의 내용 중 pattern과 일치하는 부분의 index를 모두 출력하게 하는 KMP() 함수
	int i, j, M = p.size(), N = t.size(); //M:pattern의 크기, N:text의 크기
	InitNext(p); //pattern의 Next 배열을 구함
	for (i = 0, j = 0; j <= M && i <= N; i++, j++) {
		while (j >= 0 && t[i] != p[j] && j < M)
			j = Next[j]; //t[i]와 p[j]의 불일치가 발생할 때마다 비교하는 pattern의 index j를 Next[j]로 초기화
		if (j == M) { //text에서 pattern과 일치한 부분을 찾은 경우
			cout << i - M << " "; //일치하는 부분의 시작 index는 i-M이 되므로 i-M 출력
			j = Next[j] - 1;
			i--; //pattern의 동일한 접두사, 접미사의 최대 길이만큼 비교를 시작할 i, j 지정
		}
	}
}

int main() {
	string txt; //RFC2616 파일을 저장할 string txt
	int line = 1; //탐색하는 text의 line 번호를 저장하는 int line
	ifstream file("RFC2616_modified.txt"); //file 객체로 'RFC2616_modified.txt' 파일을 읽어옴

	//(1)-1
	/*string t1 = "ababab", t2 = "aaaaa", p1 = "abab", p2 = "aa"; //(1)에 주어진 예시의 text와 pattern 지정
	KMP(p1, t1); cout << endl; //t1에서 찾은 p1의 index
	KMP(p2, t2); cout << endl;*/ //t2에서 찾은 p2의 index

	//(1)-2
	/*string p1 = "1", p2 = "*"; //숫자와 특수기호 pattern 지정
	while (getline(file,txt)) { //text에 file의 내용을 한 line씩 저장
		cout << "<line " << line << ">" << endl; //탐색중인 line 번호 출력
		cout << p1 << " : "; KMP(p1, txt); cout << endl; //p1 탐색
		cout << p2 << " : "; KMP(p2, txt); cout << endl; //p2 탐색
		cout << endl;
		line++; //line 번호 증가
	}*/
	//이하 text에서 pattern 찾는 과정 동일

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

	file.close(); //파일 닫기

	cout << "==============================================" << endl;
	cout << "12151638 한지용" << endl;

	return 0;
}