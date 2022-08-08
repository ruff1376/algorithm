#include<iostream>
using namespace std;

int main()
{
	int n,a,b,c;
	cout << "3ÀÚ¸® ½ÊÁø¼ö¸¦ ÀÔ·ÂÇÏ¼¼¿ä : ";
	cin >> n;
	a = n / 100;
	b = (n - 100 * a) / 10;
	c = n - 100 * a - 10 * b;
	if (a % 2 == 0)
		cout << a << " : Â¦¼ö ";
	else
		cout << a << " : È¦¼ö ";
	if (b % 2 == 0)
		cout << b << " : Â¦¼ö ";
	else
		cout << b << " : È¦¼ö ";
	if (c % 2 == 0)
		cout << c << " : Â¦¼ö ";
	else
		cout << c << " : È¦¼ö ";
	cout << endl;
	
	return 0;
}