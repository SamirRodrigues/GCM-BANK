#include "../libs/BonusAccount.hpp"

BonusAccount::BonusAccount() : Account() {}

BonusAccount::BonusAccount(int accountNumber) : Account(accountNumber) {
  points = 10;
}

BonusAccount::~BonusAccount() {}

void BonusAccount::AddPoints(int pointsAmount) {
  points += pointsAmount;
}

int BonusAccount::GetPoints() const {
  return points;
}
