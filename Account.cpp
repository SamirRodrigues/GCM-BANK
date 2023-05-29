#include <iostream>

class Account {
private:
  int number;
  float balance;
  int points;
  int accountType;

public:

  Account() {
    number = 0;
    balance = 0.0f;
  }

  Account (int accountNumber) {
    number = accountNumber;
    balance= 0.0f;
  }

  Account(int accountNumber, int typeOfAccount) {
    number = accountNumber;
    balance = 0.0f;
    accountType = typeOfAccount;
    points = 0;
  }
 
  Account(int accountNumber, int typeOfAccount, float initialBalance) {
    number = accountNumber;
    balance = initialBalance;
    accountType = typeOfAccount;
    points = 0;
  }

  ~Account() {}

  Account(int accountNumber, float initialBalance) {
    number = accountNumber;
    balance = initialBalance;
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

  void AddPoints(int pointsAmount) {
    points += pointsAmount;
    std::cout << "Novo saldo de pontos na conta é: " << points << std::endl;
  }

  int GetType() {
    return accountType;
  }

  void Yield(float amount) {
    balance += ((balance * amount) / 100);
  }
};