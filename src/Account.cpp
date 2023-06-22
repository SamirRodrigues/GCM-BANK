#include "../libs/Account.hpp"

Account::Account() {
  number = 0;
  balance = 0.0f;
}

Account::Account(int accountNumber) {
  number = accountNumber;
  balance = 0.0f;
}

Account::Account(int accountNumber, int typeOfAccount) {
  number = accountNumber;
  balance = 0.0f;
  accountType = typeOfAccount;
  points = 0;
}

Account::Account(int accountNumber, int typeOfAccount, float initialBalance) {
  number = accountNumber;
  balance = initialBalance;
  accountType = typeOfAccount;
  points = 0;
}

Account::Account(int accountNumber,  float initialBalance) {
  number = accountNumber;
  balance = initialBalance;
}

Account::~Account() {}

int Account::GetAccountNumber() {
    return number;
}

int Account::GetNumber() {
  return number;
}

float Account::GetBalance() {
  return balance;
}

void Account::Credit(int amount) {
  balance += amount;
}

void Account::Debit(int amount) {
  if (amount <= balance) {
    balance -= amount;
  }
  if (amount >= balance) {
    if (amount - balance <= negativeLimit) {
      balance -= amount;
    } else {
      std::cout << "Não é possível debitar da sua conta. Seu limite de transferência é " << balance + (negativeLimit * (-1)) << std::endl;
    }

    std::cout << "Saldo em conta insuficiente!" << std::endl;
  }
}

void Account::AddPoints(int pointsAmount) {
  points += pointsAmount;
  std::cout << "Novo saldo de pontos na conta é: " << points << std::endl;
}

int Account::GetType() {
  return accountType;
}

float Account::GetPoints() {
  return points;
}

void Account::Yield(float amount) {
  balance += ((balance * amount) / 100);
}
