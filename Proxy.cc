#include<iostream>
#include<string>
 
using namespace std;
 
class IBank
{
public:
	virtual string WithDrawCash(void) = 0;
	virtual ~IBank(){}
};
 
class ActualBank : IBank
{
public:
	string WithDrawCash(void)
	{
		return "Here, have a million Zimbabwean dollars.\n\n";
	}
};
 
class Bank : public IBank
{
	ActualBank* _bank;
	string _password;
public:
	Bank() :_bank(NULL), _password("WhoWhatWhere"){}
 
	string WithDrawCash(void)
	{
		if (_bank == NULL)
			return "\nDid you authenticate?\n";
		return _bank->WithDrawCash();
	}
 
	void Authenticate(string passwd)
	{
		if (_password == passwd)
		{
			cout << "\nYou have been authenticated.\n\n";
			_bank = new ActualBank();
		}
		else
		{
			cout << "\nSorry but wrong.\n";
		}
	}
 
	~Bank()
	{
		delete _bank;
	}
};
 
int main()
{
	Bank* daddysBank = new Bank();
	cout << daddysBank->WithDrawCash();
	daddysBank->Authenticate("Hello");
	daddysBank->Authenticate("WhoWhatWhere");
	cout << daddysBank->WithDrawCash();
 
	return 1;
}
