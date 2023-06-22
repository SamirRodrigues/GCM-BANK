#ifndef BANK_HPP
#define BANK_HPP

#include <list>
#include "Account.hpp"
#include "BonusAccount.hpp"
#include "SavingsAccount.hpp"

class Bank {
private:
  std::list<Account> accounts;
  std::list<Account>::iterator account;

  enum accountTypes {
    SIMPLE = 1,
    BONUS = 2,
    SAVINGS = 3
  };

public:
  Bank();
  ~Bank();

  int GetAccountType(int accountNumber);
  int GetNumAccounts() const;
  float GetAccountPoints(int accountNumber);
  float GetBalance(int accountNumber);
  void ApplyYield(int accountNumber, float value);
  void DebitAccount(int accountNumber, int value);
  void CreditAccount(int accountNumber, int value);
  std::list<Account>::iterator GetEndAccountsList();
  std::list<Account>::iterator FindAccount(int accountNumber);
  void AddAccount(int accountNumber, int accountType, float initialBalance);
  bool Transfer(int accountNumberDebit, int accountNumberCredit, int amount);
};

#endif // BANK_HPP
