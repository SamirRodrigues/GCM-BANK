#include "../libs/SavingsAccount.hpp"

SavingsAccount::SavingsAccount() : Account() {}

SavingsAccount::SavingsAccount(int accountNumber) : Account(accountNumber) {
  points = 10;
}

SavingsAccount::~SavingsAccount() {}

void SavingsAccount::AddPoints(int pointsAmount) {
  points += pointsAmount;
}

void SavingsAccount::Debit(int amount) {
  if (amount <= balance) {
    balance -= amount;
  } else {
    std::cout << "Saldo em conta insuficiente!" << std::endl;
  }
}

int SavingsAccount::GetPoints() const {
  return points;
}
