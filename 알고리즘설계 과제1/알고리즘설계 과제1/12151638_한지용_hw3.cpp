#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<time.h>
using namespace std;

void selectionSort(int *S, int size) { //Selection sort를 수행하는 함수 정의 (인자:배열, 배열의 크기)
	int i, j, smallest; //smallest:최소값의 index
	for (i = 0; i < size - 1; i++) {
		smallest = i;
		for (j = i + 1; j < size; j++)
			if (S[j] < S[smallest]) //지정한 최소값보다 작은 값이 존재할 경우
				smallest = j; //최소값의 index 변경
		swap(S[i], S[smallest]); //S[i]~S[size-1]의 원소중 최소값과 S[i]를 교환
	}
}

void medianOfThreeQuickSort(int *S, int l, int r) { //Median-of-three quick sort를 수행하는 함수 정의 (인자:배열, 정렬구간 시작 index, 정렬구간 끝 index)
	int i, j, m, p; //m:중간값 index, p:pivot
	if (r - l > 1) { //정렬할 원소가 2개 이상인 경우
		m = (l + r) / 2; //중간값 index 지정
		if (S[l] > S[m]) swap(S[l], S[m]);
		if (S[l] > S[r]) swap(S[l], S[r]);
		if (S[m] > S[r]) swap(S[m], S[r]); //왼쪽, 가운데, 오른쪽 원소를 오름차순으로 정렬
		swap(S[m], S[r - 1]); //중간값을 S[r-1]로 옮김
		p = S[r - 1]; i = l; j = r - 2; //S[r-1]을 pivot으로 정함. pivot에 대하여 [l, r-2]구간 정렬
		while (i <= j) { //i와 j가 교차할 때까지 수행
			while (i <= j && S[i] <= p) i++;
			while (i <= j && S[j] >= p) j--;
			if (i < j) swap(S[i], S[j]); //S[i]가 pivot보다 크고 S[j]가 pivot보다 작으면 서로 교환
		}
		swap(S[i], S[r - 1]); //pivot을 올바른 자리에 배치
		medianOfThreeQuickSort(S, l, i - 1);
		medianOfThreeQuickSort(S, i + 1, r); //pivot을 기준으로 왼쪽 구간과 오른쪽 구간에 대해 같은 작업 반복
	}
	else if (S[l] > S[r]) swap(S[l], S[r]); //정렬할 원소가 2개이고 왼쪽 원소가 더 클 경우 swap
}

void shellSort(int *S, int size) { //Shell sort를 수행하는 함수 정의 (인자:배열, 정렬할 원소 수)
	int h = 1, v, i, j; //h:sublist의 gap
	while (h < size)
		h = 3 * h + 1; //초기 gap 설정
	for (; h > 0; h /= 3) { //gap 감소식:h=h/3
		for (i = h + 1; i <= size; i++) { //sublist 삽입정렬
			v = S[i];
			j = i;
			while (j > h && S[j - h] > v) { //sublist의 오른쪽 원소보다 왼쪽 원소(S[j-h])가 더 클 경우
				S[j] = S[j - h]; //해당 원소를 gap만큼 오른쪽으로 이동
				j = j - h; //그 다음 왼쪽 원소에 대하여 같은 작업 수행
			}
			S[j] = v; //마지막으로 이동된 원소가 있던 자리에 삭제된 원소 추가(sublist 정렬 완료)
		}
	}
}

void bitonicCompare(int *S, int i, int j, bool isAscending) { //bitonicMerge()의 bitonicCompare() 정의 (인자:배열, 비교할 두 원소의 index, 오름 또는 내림차순 여부)
	if (isAscending == (S[i] > S[j]))
		swap(S[i], S[j]); //isAscending==true이면 두 원소를 오름차순, false이면 두 원소를 내림차순으로 정렬
}

void bitonicMerge(int *S, int l, int size, bool isAscending) { //bitonicSort()의 bitonicMerge() 정의 (인자:배열, 정렬할 배열의 시작 index, 정렬할 원소 수, 오름 또는 내림차순 여부)
	if (size > 1) { //배열을 원소가 1개 남을때까지 자름
		int half = size / 2; //배열의 절반 크기를 int half에 저장
		for (int i = l; i < l + half; i++)
			bitonicCompare(S, i, i + half, isAscending); //나눈 배열의 크기만큼의 간격의 두 원소 비교
		bitonicMerge(S, l, half, isAscending); //좌측 절반 원소 비교
		bitonicMerge(S, l+half, half, isAscending); //우측 절반 원소 비교
	}
}

void bitonicSort(int *S, int l, int size, bool isAscending) { //Bitonic sort를 수행하는 함수 정의 (인자:배열, 정렬할 배열의 시작 index, 정렬할 원소 수, 오름 또는 내림차순 여부)
	if (size > 1) { //배열을 원소가 1개 남을때까지 나눔
		int half = size / 2; //배열의 절반 크기를 int half에 저장
		bitonicSort(S, l, half, 1); //좌측 절반 오름차순 정렬
		bitonicSort(S, l + half, half, 0); //우측 절반 내림차순 정렬
		bitonicMerge(S, l, size, isAscending); //나눈 배열들을 정렬한 뒤 다시 합쳐준다
	}
}

void oddEvenMergeCompare(int *S, int i, int j) {
	if (S[i] > S[j])
		swap(S[i], S[j]); //두 원소 오름차순 정렬
}

void oddEvenMerge(int *S, int l, int size, int d) { //oddEvenMergeSort()의 oddEvenMerge() 정의 (인자:배열, 정렬할 배열의 시작 index, 정렬할 원소 수, 비교할 원소 간 거리)
	int merge = d * 2; //d를 2배로 늘려가며 비교
	if (merge < size) { //merge가 size가 될때까지 수행
		oddEvenMerge(S, l, size, merge); //좌측 절반 비교
		oddEvenMerge(S, l + d, size, merge); //우측 절반 비교
		for (int i = l + d; i + d < l + size; i += merge)
			oddEvenMergeCompare(S, i, i + d); //i를 merge만큼 늘려가며 간격 d의 두 원소를 비교한다
	}
	else
		oddEvenMergeCompare(S, l, l + d); //나뉜 배열의 양 끝 원소 비교
}

void oddEvenMergeSort(int *S, int l, int size) { //odd even merge sort를 수행하는 함수 정의 (인자:배열, 정렬할 배열의 시작 index, 정렬할 원소 수)
	if (size > 1) { //배열을 원소가 1개 남을때까지 나눔
		int half = size / 2; //배열의 절반 크기를 int half에 저장
		oddEvenMergeSort(S, l, half); //좌측 절반 정렬
		oddEvenMergeSort(S, l + half, half); //우측 절반 정렬
		oddEvenMerge(S, l, size, 1); //가장 작은 단위의 배열 정렬
	}
}

bool isPowerOfTwo(int n) { //n이 2의 거듭제곱인지 판별하는 함수
	for (int i = 0;; i++) {
		if (pow(2, i) == n)
			return true; //n이 2의 거듭제곱이라면 true 반환
		if (pow(2, i) > n)
			return false; //n이 2의 거듭제곱이 아니라면 false 반환
	}
}

int main() {
	time_t start, end; //함수의 수행시간 측정 시작과 끝을 표시할 변수 start, end
	double result; //측정된 수행시간을 표시할 변수 result
	int size, n; //원소의 개수를 받을 size와 0으로 패딩한 배열의 크기 n

	cout << "Enter the size : ";
	cin >> size; //배열의 원소의 개수를 입력받음

	int *sel = new int[size];
	int *qui = new int[size];
	int *she = new int[size + 1];
	int *bit = new int[size];
	int *oem = new int[size]; //5가지로 sorting할 5가지 배열 선언

	she[0] = 0; //shell정렬의 0번째 원소는 사용하지 않으므로 0으로 초기화

	if (!isPowerOfTwo(size)) { //원소의 개수가 2의 거듭제곱 개가 아니라면
		                       //bitonic과 odd even merge sort를 할 배열에 대해 배열의 크기를 2의 거듭제곱으로 만들어 준 뒤 늘어난 수만큼 0으로 패딩해준다.
		for (n = 1;; n *= 2)
			if (n > size) break; //size보다 큰 2의 거듭제곱수 중 최소값을 찾는다
		bit = new int[n];
		oem = new int[n]; //배열의 크기를 n으로 늘림
		for (int i = 0; i < n - size; i++) {
			bit[i] = 0;
			oem[i] = 0; //늘어난 배열 크기만큼 배열 앞쪽부터 0으로 패딩
		}
		for (int i = 0; i < size; i++) {
			int k = rand();
			sel[i] = k;
			qui[i] = k;
			she[i + 1] = k;
			bit[i + n - size] = k;
			oem[i + n - size] = k; //5개의 배열에 무작위 난수 삽입
		}
	}
	else { //원소의 개수가 2의 거듭제곱 개이면 
		n = size; //배열을 늘릴 필요가 없으므로 n은 size와 같음
		for (int i = 0; i < size; i++) {
			int k = rand();
			sel[i] = k;
			qui[i] = k;
			she[i + 1] = k;
			bit[i] = k;
			oem[i] = k; //5개의 배열에 무작위 난수 삽입
		}
	}

	start = clock();
	selectionSort(sel, size);
	end = clock();
	result = (double)(end - start);
	printf("Selection sort : %f sec\n", result / CLOCKS_PER_SEC); //selection sort 실행시간 측정

	start = clock();
	medianOfThreeQuickSort(qui, 0, size - 1);
	end = clock();
	result = (double)(end - start);
	printf("Median-of-three quick sort : %f sec\n", result / CLOCKS_PER_SEC); //median-of-three quick sort 실행시간 측정

	start = clock();
	shellSort(she, size - 1);
	end = clock();
	result = (double)(end - start);
	printf("Shell sort : %f sec\n", result / CLOCKS_PER_SEC); //shell sort 실행시간 측정

	start = clock();
	bitonicSort(bit, 0, n, 1);
	end = clock();
	result = (double)(end - start);
	printf("Bitonic sort : %f sec\n", result / CLOCKS_PER_SEC); //bitonic sort 실행시간 측정

	start = clock();
	oddEvenMergeSort(oem, 0, n);
	end = clock();
	result = (double)(end - start);
	printf("Odd even merge sort : %f sec\n", result / CLOCKS_PER_SEC); //odd even merge sort 실행시간 측정

	delete[]sel;
	delete[]qui;
	delete[]she;
	delete[]bit;
	delete[]oem; //배열 메모리 해제

	cout << "==============================================" << endl;
	cout << "12151638 한지용" << endl;

	return 0;
}