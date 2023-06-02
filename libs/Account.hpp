#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>

class Account {
protected:

  enum accountTypes
  {
    SIMPLE = 1,
    BONUS = 2,
    SAVINGS = 3
  }; 
  int number;
  float balance;
  int points;
  float negativeLimit = -1000.00;
  int accountType;

public:

  Account();
  Account(int accountNumber);
  Account(int accountNumber, int typeOfAccount);
  Account(int accountNumber, float initialBalance);
  Account(int accountNumber, int typeOfAccount, float initialBalance);
  ~Account();

  int GetType();
  int GetNumber();
  float GetBalance();
  int GetAccountNumber();
  void Debit(int amount);
  void Credit(int amount);
  void Yield(float amount);
  void AddPoints(int pointsAmount);
};

#endif // ACCOUNT_HPP