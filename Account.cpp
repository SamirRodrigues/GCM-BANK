#include <iostream>

class Account
{
private:
  int number;
  float balance;

public:
  Account()
  {
    number = 0;
    balance = 0.0f;
  }

  Account(int acountNumber)
  {
    number = acountNumber;
    balance = 0.0f;
  }
 
  Account(int accountNumber, int typeOfAccount, float initialBalance) {
    number = accountNumber;
    balance = initialBalance;
    accountType = typeOfAccount;
    points = 0;
  }



  Account(int accountNumber, float initialBalance) {
    number = accountNumber;
    balance = initialBalance;
  }

    ~Account() {}
  
  int GetNumber()
  {
    return number;
  }

  float GetBalance()
  {
    return balance;
  }

  void Credit(int amount) {    
    balance += amount;
  }

  void Debit(int amount) {
    if(amount <= balance) {
      balance -= amount;
    } else {
      std::cout << "Saldo em conta insuficiente!" << std::endl;
    }
  }
};