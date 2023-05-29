// #include <iostream>
#include "Account.cpp"

class BonusAccount : Account
{
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

  void Credit(int amount) {
    int newPoints;
    newPoints = amount/150; // Recebe 1 ponto a cada 150 dinheiros recebidos.
    AddPoints(newPoints);
    balance += amount;
  }
};