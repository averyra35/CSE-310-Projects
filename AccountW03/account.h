#include <string>
#include <list>
using namespace std;

class Account {
private:
	int accountID;
	string accountName;
	float accountBalance;
public:
	Account();
	Account(int ID, string Name, float Balance);
	void display_account();
	void deposit(float addition);
	void withdraw(float subtraction);
	int get_id()const;
};