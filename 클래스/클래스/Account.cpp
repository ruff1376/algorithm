#include <iostream>
using namespace std;

class Account
{
public:
	void setBalance(int balance)
	{
		if (balance < 0)
		{
			cout << "Error: Initial balance cannot be negative.\n\n";
			this->balance = 0;
		}
		else
			this->balance = balance;
	}

	int getBalance()
	{
		return this->balance;
	}

	void debit()
	{
		int input;
		cout << "Enter withdrawal amount for account1: ";
		cin >> input;
		cout << "\nattempting to substract " << input << " from account1 balance" << endl;
		if (input > this->balance)
			cout << "\nDebit amount exceeded account balance." << endl << endl;
		else
		{
			setBalance(this->balance - input);
			cout << endl;
		}
	}

	void credit()
	{
		int input;
		cout << "Enter deposit amount for account2: ";
		cin >> input;
		cout << "\nattempting to add " << input << " to account2 balance" << endl;
		setBalance(this->balance + input);
		cout << endl;
	}
private:
	int balance;
};

int main()
{
	Account account1;
	Account account2;

	account1.setBalance(50);
	account2.setBalance(-25);

	account1.debit();
	account2.credit();

	cout << "account1 balance: " << account1.getBalance() << endl;
	cout << "account2 balance: " << account2.getBalance() << endl;

	return 0;
}