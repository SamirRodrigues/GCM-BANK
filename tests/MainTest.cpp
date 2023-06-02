#include <iostream>
#include "../libs/Account.hpp"
#include "../libs/Bank.hpp"

enum accountTypes
  {
    SIMPLE = 1,
    BONUS = 2,
    SAVINGS = 3
  }; 

// Função para imprimir o resultado do teste
void printTestResult(bool result, const std::string& testName) {
    if (result) {
        std::cout << "\033[1;32m[PASSOU]\033[0m " << testName << std::endl;
    } else {
        std::cout << "\033[1;31m[FALHOU]\033[0m " << testName << std::endl;
    }
}

// Teste para a função FindAccount com conta existente
bool testFindAccountExisting() {
    Bank bank;
    bank.AddAccount(1, SIMPLE, 1000.0);
    bank.AddAccount(2, SAVINGS, 2000.0);
    bank.AddAccount(3, BONUS, 3000.0);

    // Verifica se a conta encontrada possui o número de conta correto
    return (bank.FindAccount(2) != bank.GetEndAccountsList() && bank.FindAccount(2)->GetAccountNumber() == 2);
}

// Teste para a função FindAccount com conta inexistente
bool testFindAccountNonExisting() {
    Bank bank;
    bank.AddAccount(1, SIMPLE, 1000.0);
    bank.AddAccount(2, SAVINGS, 2000.0);
    bank.AddAccount(3, BONUS, 3000.0);

    // Verifica se a conta não foi encontrada (ponteiro nulo)
    return (bank.FindAccount(4) == bank.GetEndAccountsList());
}

// Teste para a função ApplyYield
bool testApplyYield() {
    Bank bank;
    bank.AddAccount(1, SAVINGS, 1000.0);

    bank.ApplyYield(1, 0.05);
    double newBalance = bank.GetBalance(1);

    // O cálculo do rendimento de 5% sobre 1000 resulta em 1050
    return (newBalance == 1050.0);
}

// Teste para a função ApplyYield com taxa negativa
bool testApplyYieldNegativeRate() {
    Bank bank;
    bank.AddAccount(1, SAVINGS, 1000.0);

    bank.ApplyYield(1, -0.05);
    double newBalance = bank.GetBalance(1);

    // Como a taxa é negativa, o saldo não deve ser alterado
    return (newBalance == 1000.0);
}

// Teste para a função AddAccount
bool testAddAccount() {
    Bank bank;

    bank.AddAccount(1, SIMPLE, 100.0);
    bank.AddAccount(2, BONUS, 200.0);

    int numAccounts = bank.GetNumAccounts();

    return (numAccounts == 2);
}

// Teste para a função CreditAccount
bool testCreditAccount() {
    Bank bank;
    bank.AddAccount(1, SIMPLE, 100.0);

    bank.CreditAccount(1, 50.0);
    double newBalance = bank.GetBalance(1);

    return (newBalance == 150.0);
}

// Teste para a função DebitAccount
bool testDebitAccount() {
    Bank bank;
    bank.AddAccount(1, SIMPLE, 100.0);

    bank.DebitAccount(1, 50.0);
    double newBalance = bank.GetBalance(1);

    return (newBalance == 50.0);
}

// Teste para a função Transfer
bool testTransfer() {
    Bank bank;
    bank.AddAccount(1, SIMPLE, 100.0);
    bank.AddAccount(2, SIMPLE, 200.0);

    bank.Transfer(1, 2, 50.0);
    double balance1 = bank.GetBalance(1);
    double balance2 = bank.GetBalance(2);

    return (balance1 == 50.0 && balance2 == 250.0);
}

// Teste para a função GetBalance
bool testGetBalance() {
    Bank bank;
    bank.AddAccount(1, SIMPLE, 100.0);

    double balance = bank.GetBalance(1);

    return (balance == 100.0);
}

int main() {
    bool addAccountTestResult = testAddAccount();
    printTestResult(addAccountTestResult, "Teste da função AddAccount");

    bool creditAccountTestResult = testCreditAccount();
    printTestResult(creditAccountTestResult, "Teste da função CreditAccount");

    bool debitAccountTestResult = testDebitAccount();
    printTestResult(debitAccountTestResult, "Teste da função DebitAccount");

    bool transferTestResult = testTransfer();
    printTestResult(transferTestResult, "Teste da função Transfer");

    bool getBalanceTestResult = testGetBalance();
    printTestResult(getBalanceTestResult, "Teste da função GetBalance");

    bool applyYieldTestResult = testApplyYield();
    printTestResult(applyYieldTestResult, "Teste da função ApplyYield");

    bool applyYieldNegativeRateTestResult = testApplyYieldNegativeRate();
    printTestResult(applyYieldNegativeRateTestResult, "Teste da função ApplyYield com taxa negativa");

    bool findAccountExistingTestResult = testFindAccountExisting();
    printTestResult(findAccountExistingTestResult, "Teste da função FindAccount com conta existente");

    bool findAccountNonExistingTestResult = testFindAccountNonExisting();
    printTestResult(findAccountNonExistingTestResult, "Teste da função FindAccount com conta inexistente");

    return 0;
}
