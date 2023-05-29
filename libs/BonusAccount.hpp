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
  int GetPoints() const;
  void AddPoints(int pointsAmount);
  void BonusAccount::Credit(int amount);
};

#endif // BONUS_ACCOUNT_HPP
