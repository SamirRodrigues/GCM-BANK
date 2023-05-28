// #include <iostream>
#include "Account.cpp"

class SavingsAccount : Account
{
protected:
  int points;

public:
  SavingsAccount() : Account()
  {
  }
  SavingsAccount(int accountNumber) : Account(accountNumber) {
    points = 10;
  }
  ~SavingsAccount() { }
  void AddPoints(int pointsAmount) {
    points += pointsAmount;
  }
  int GetPoints() const {
    return points;
  }
};