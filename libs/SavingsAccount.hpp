#ifndef SAVINGS_ACCOUNT_HPP
#define SAVINGS_ACCOUNT_HPP

#include "Account.hpp"

class SavingsAccount : public Account {
protected:
  int points;

public:
  SavingsAccount();
  SavingsAccount(int accountNumber);
  ~SavingsAccount();
  void AddPoints(int pointsAmount);
  void Debit(int amount);
  int GetPoints() const;
};

#endif // SAVINGS_ACCOUNT_HPP
