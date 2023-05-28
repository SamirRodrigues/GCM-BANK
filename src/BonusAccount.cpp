// #include <iostream>
#include "Account.cpp"

class BonusAccount : Account
{
protected:
  int points;

public:
  BonusAccount() : Account()
  {
  }
  BonusAccount(int accountNumber) : Account(accountNumber) {
    points = 10;
  }
  ~BonusAccount() { }
  void AddPoints(int pointsAmount) {
    points += pointsAmount;
  }
  int GetPoints() const {
    return points;
  }
};