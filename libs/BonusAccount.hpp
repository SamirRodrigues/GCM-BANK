#ifndef BONUS_ACCOUNT_HPP
#define BONUS_ACCOUNT_HPP

#include "Account.hpp"

class BonusAccount : public Account {
protected:
  int points;

public:
  BonusAccount();
  BonusAccount(int accountNumber);
  ~BonusAccount();
  void AddPoints(int pointsAmount);
  int GetPoints() const;
};

#endif // BONUS_ACCOUNT_HPP
