#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v1(n);
	vector<string> v2(n);
	for (int i = 0; i < n; i++)
		cin >> v1[i] >> v2[i];

	for(int i=0;i<n;i++)
		for(int j=0;j<n-1-i;j++)
			if (v1[j] > v1[j+1])
			{
				int a = v1[j];
				v1[j] = v1[j+1];
				v1[j+1] = a;

				string b = v2[j];
				v2[j] = v2[j+1];
				v2[j+1] = b;
			}

	for (int i = 0; i < n; i++)
		cout << v1[i] << " " << v2[i] << endl;

	return 0;
}