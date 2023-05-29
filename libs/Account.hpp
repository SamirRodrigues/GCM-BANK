#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>

class Account {
protected:
  int number;
  float balance;
  int points;
  float negativeLimit = -1000.00;
  int accountType;

public:
  Account();
  Account(int accountNumber);
  Account(int accountNumber, int typeOfAccount);
  Account(int accountNumber, int typeOfAccount, float initialBalance);
  ~Account();

  int GetNumber();
  float GetBalance();
  void Credit(int amount);
  void Debit(int amount);
  void AddPoints(int pointsAmount);
  int GetType();
  void Yield(float amount);
};

#endif // ACCOUNT_HPP