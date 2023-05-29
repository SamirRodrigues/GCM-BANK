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

void BonusAccount::Credit(int amount) {
    int newPoints;
    newPoints = amount/150; // Recebe 1 ponto a cada 150 dinheiros recebidos.
    AddPoints(newPoints);
    balance += amount;
  }
