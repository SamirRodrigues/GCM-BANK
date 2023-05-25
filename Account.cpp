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