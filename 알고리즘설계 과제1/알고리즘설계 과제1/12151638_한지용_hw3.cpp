#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<time.h>
using namespace std;

void selectionSort(int *S, int size) { //Selection sort�� �����ϴ� �Լ� ���� (����:�迭, �迭�� ũ��)
	int i, j, smallest; //smallest:�ּҰ��� index
	for (i = 0; i < size - 1; i++) {
		smallest = i;
		for (j = i + 1; j < size; j++)
			if (S[j] < S[smallest]) //������ �ּҰ����� ���� ���� ������ ���
				smallest = j; //�ּҰ��� index ����
		swap(S[i], S[smallest]); //S[i]~S[size-1]�� ������ �ּҰ��� S[i]�� ��ȯ
	}
}

void medianOfThreeQuickSort(int *S, int l, int r) { //Median-of-three quick sort�� �����ϴ� �Լ� ���� (����:�迭, ���ı��� ���� index, ���ı��� �� index)
	int i, j, m, p; //m:�߰��� index, p:pivot
	if (r - l > 1) { //������ ���Ұ� 2�� �̻��� ���
		m = (l + r) / 2; //�߰��� index ����
		if (S[l] > S[m]) swap(S[l], S[m]);
		if (S[l] > S[r]) swap(S[l], S[r]);
		if (S[m] > S[r]) swap(S[m], S[r]); //����, ���, ������ ���Ҹ� ������������ ����
		swap(S[m], S[r - 1]); //�߰����� S[r-1]�� �ű�
		p = S[r - 1]; i = l; j = r - 2; //S[r-1]�� pivot���� ����. pivot�� ���Ͽ� [l, r-2]���� ����
		while (i <= j) { //i�� j�� ������ ������ ����
			while (i <= j && S[i] <= p) i++;
			while (i <= j && S[j] >= p) j--;
			if (i < j) swap(S[i], S[j]); //S[i]�� pivot���� ũ�� S[j]�� pivot���� ������ ���� ��ȯ
		}
		swap(S[i], S[r - 1]); //pivot�� �ùٸ� �ڸ��� ��ġ
		medianOfThreeQuickSort(S, l, i - 1);
		medianOfThreeQuickSort(S, i + 1, r); //pivot�� �������� ���� ������ ������ ������ ���� ���� �۾� �ݺ�
	}
	else if (S[l] > S[r]) swap(S[l], S[r]); //������ ���Ұ� 2���̰� ���� ���Ұ� �� Ŭ ��� swap
}

void shellSort(int *S, int size) { //Shell sort�� �����ϴ� �Լ� ���� (����:�迭, ������ ���� ��)
	int h = 1, v, i, j; //h:sublist�� gap
	while (h < size)
		h = 3 * h + 1; //�ʱ� gap ����
	for (; h > 0; h /= 3) { //gap ���ҽ�:h=h/3
		for (i = h + 1; i <= size; i++) { //sublist ��������
			v = S[i];
			j = i;
			while (j > h && S[j - h] > v) { //sublist�� ������ ���Һ��� ���� ����(S[j-h])�� �� Ŭ ���
				S[j] = S[j - h]; //�ش� ���Ҹ� gap��ŭ ���������� �̵�
				j = j - h; //�� ���� ���� ���ҿ� ���Ͽ� ���� �۾� ����
			}
			S[j] = v; //���������� �̵��� ���Ұ� �ִ� �ڸ��� ������ ���� �߰�(sublist ���� �Ϸ�)
		}
	}
}

void bitonicCompare(int *S, int i, int j, bool isAscending) { //bitonicMerge()�� bitonicCompare() ���� (����:�迭, ���� �� ������ index, ���� �Ǵ� �������� ����)
	if (isAscending == (S[i] > S[j]))
		swap(S[i], S[j]); //isAscending==true�̸� �� ���Ҹ� ��������, false�̸� �� ���Ҹ� ������������ ����
}

void bitonicMerge(int *S, int l, int size, bool isAscending) { //bitonicSort()�� bitonicMerge() ���� (����:�迭, ������ �迭�� ���� index, ������ ���� ��, ���� �Ǵ� �������� ����)
	if (size > 1) { //�迭�� ���Ұ� 1�� ���������� �ڸ�
		int half = size / 2; //�迭�� ���� ũ�⸦ int half�� ����
		for (int i = l; i < l + half; i++)
			bitonicCompare(S, i, i + half, isAscending); //���� �迭�� ũ�⸸ŭ�� ������ �� ���� ��
		bitonicMerge(S, l, half, isAscending); //���� ���� ���� ��
		bitonicMerge(S, l+half, half, isAscending); //���� ���� ���� ��
	}
}

void bitonicSort(int *S, int l, int size, bool isAscending) { //Bitonic sort�� �����ϴ� �Լ� ���� (����:�迭, ������ �迭�� ���� index, ������ ���� ��, ���� �Ǵ� �������� ����)
	if (size > 1) { //�迭�� ���Ұ� 1�� ���������� ����
		int half = size / 2; //�迭�� ���� ũ�⸦ int half�� ����
		bitonicSort(S, l, half, 1); //���� ���� �������� ����
		bitonicSort(S, l + half, half, 0); //���� ���� �������� ����
		bitonicMerge(S, l, size, isAscending); //���� �迭���� ������ �� �ٽ� �����ش�
	}
}

void oddEvenMergeCompare(int *S, int i, int j) {
	if (S[i] > S[j])
		swap(S[i], S[j]); //�� ���� �������� ����
}

void oddEvenMerge(int *S, int l, int size, int d) { //oddEvenMergeSort()�� oddEvenMerge() ���� (����:�迭, ������ �迭�� ���� index, ������ ���� ��, ���� ���� �� �Ÿ�)
	int merge = d * 2; //d�� 2��� �÷����� ��
	if (merge < size) { //merge�� size�� �ɶ����� ����
		oddEvenMerge(S, l, size, merge); //���� ���� ��
		oddEvenMerge(S, l + d, size, merge); //���� ���� ��
		for (int i = l + d; i + d < l + size; i += merge)
			oddEvenMergeCompare(S, i, i + d); //i�� merge��ŭ �÷����� ���� d�� �� ���Ҹ� ���Ѵ�
	}
	else
		oddEvenMergeCompare(S, l, l + d); //���� �迭�� �� �� ���� ��
}

void oddEvenMergeSort(int *S, int l, int size) { //odd even merge sort�� �����ϴ� �Լ� ���� (����:�迭, ������ �迭�� ���� index, ������ ���� ��)
	if (size > 1) { //�迭�� ���Ұ� 1�� ���������� ����
		int half = size / 2; //�迭�� ���� ũ�⸦ int half�� ����
		oddEvenMergeSort(S, l, half); //���� ���� ����
		oddEvenMergeSort(S, l + half, half); //���� ���� ����
		oddEvenMerge(S, l, size, 1); //���� ���� ������ �迭 ����
	}
}

bool isPowerOfTwo(int n) { //n�� 2�� �ŵ��������� �Ǻ��ϴ� �Լ�
	for (int i = 0;; i++) {
		if (pow(2, i) == n)
			return true; //n�� 2�� �ŵ������̶�� true ��ȯ
		if (pow(2, i) > n)
			return false; //n�� 2�� �ŵ������� �ƴ϶�� false ��ȯ
	}
}

int main() {
	time_t start, end; //�Լ��� ����ð� ���� ���۰� ���� ǥ���� ���� start, end
	double result; //������ ����ð��� ǥ���� ���� result
	int size, n; //������ ������ ���� size�� 0���� �е��� �迭�� ũ�� n

	cout << "Enter the size : ";
	cin >> size; //�迭�� ������ ������ �Է¹���

	int *sel = new int[size];
	int *qui = new int[size];
	int *she = new int[size + 1];
	int *bit = new int[size];
	int *oem = new int[size]; //5������ sorting�� 5���� �迭 ����

	she[0] = 0; //shell������ 0��° ���Ҵ� ������� �����Ƿ� 0���� �ʱ�ȭ

	if (!isPowerOfTwo(size)) { //������ ������ 2�� �ŵ����� ���� �ƴ϶��
		                       //bitonic�� odd even merge sort�� �� �迭�� ���� �迭�� ũ�⸦ 2�� �ŵ��������� ����� �� �� �þ ����ŭ 0���� �е����ش�.
		for (n = 1;; n *= 2)
			if (n > size) break; //size���� ū 2�� �ŵ������� �� �ּҰ��� ã�´�
		bit = new int[n];
		oem = new int[n]; //�迭�� ũ�⸦ n���� �ø�
		for (int i = 0; i < n - size; i++) {
			bit[i] = 0;
			oem[i] = 0; //�þ �迭 ũ�⸸ŭ �迭 ���ʺ��� 0���� �е�
		}
		for (int i = 0; i < size; i++) {
			int k = rand();
			sel[i] = k;
			qui[i] = k;
			she[i + 1] = k;
			bit[i + n - size] = k;
			oem[i + n - size] = k; //5���� �迭�� ������ ���� ����
		}
	}
	else { //������ ������ 2�� �ŵ����� ���̸� 
		n = size; //�迭�� �ø� �ʿ䰡 �����Ƿ� n�� size�� ����
		for (int i = 0; i < size; i++) {
			int k = rand();
			sel[i] = k;
			qui[i] = k;
			she[i + 1] = k;
			bit[i] = k;
			oem[i] = k; //5���� �迭�� ������ ���� ����
		}
	}

	start = clock();
	selectionSort(sel, size);
	end = clock();
	result = (double)(end - start);
	printf("Selection sort : %f sec\n", result / CLOCKS_PER_SEC); //selection sort ����ð� ����

	start = clock();
	medianOfThreeQuickSort(qui, 0, size - 1);
	end = clock();
	result = (double)(end - start);
	printf("Median-of-three quick sort : %f sec\n", result / CLOCKS_PER_SEC); //median-of-three quick sort ����ð� ����

	start = clock();
	shellSort(she, size - 1);
	end = clock();
	result = (double)(end - start);
	printf("Shell sort : %f sec\n", result / CLOCKS_PER_SEC); //shell sort ����ð� ����

	start = clock();
	bitonicSort(bit, 0, n, 1);
	end = clock();
	result = (double)(end - start);
	printf("Bitonic sort : %f sec\n", result / CLOCKS_PER_SEC); //bitonic sort ����ð� ����

	start = clock();
	oddEvenMergeSort(oem, 0, n);
	end = clock();
	result = (double)(end - start);
	printf("Odd even merge sort : %f sec\n", result / CLOCKS_PER_SEC); //odd even merge sort ����ð� ����

	delete[]sel;
	delete[]qui;
	delete[]she;
	delete[]bit;
	delete[]oem; //�迭 �޸� ����

	cout << "==============================================" << endl;
	cout << "12151638 ������" << endl;

	return 0;
}