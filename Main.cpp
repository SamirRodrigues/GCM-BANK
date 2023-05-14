#include "Bank.cpp"

void run() {
    Bank GCMBank;
    int option = 1;
    int accountNumber,accountNumberDebit , moneyAccount;

    while(option != 0) {
        std::cout << std::endl << "==============================" << std::endl;
        std::cout << "Escolha a operação a ser realizada!" << std::endl;
        std::cout << "1 - Cadastrar nova conta" << std::endl;
        std::cout << "2 - Consultar Saldo" << std::endl;
        std::cout << "3 - Crédito de Conta" << std::endl;
        std::cout << "4 - Débito de conta" << std::endl;
        std::cout << "5 - Transferiência entre contas" << std::endl;
        std::cout << "0 - Sair" << std::endl;
        std::cout << "=> ";
        std::cin >> option;

        if(option == 1) {
            std::cout << "Insira um número para a conta: ";
            std::cin >> accountNumber;
            GCMBank.AddAccount(accountNumber);
            std::cout << "Conta adicionada!" << std::endl;
        } else if (option == 2) {
            std::cout << "Informe o número da conta a ser consultada: ";
            std::cin >> accountNumber;
            std::cout << "Saldo da Conta " << accountNumber << ": " << GCMBank.GetBalance(accountNumber) << std::endl;
        } else if (option == 3) {
            std::cout << "Informe o número de conta a ser creditada: ";
            std::cin >> accountNumber;
            std::cout << "Insira o valor de crédito: ";
            std::cin >> moneyAccount;
            GCMBank.CreditAccount(accountNumber, moneyAccount);
            std::cout << "Novo saldo na conta " << accountNumber << ": " << GCMBank.GetBalance(accountNumber);
        } else if (option == 4) {
            std::cout << "Informe númeração da conta a ser debitada: ";
            std::cin >> accountNumber;
            std::cout << "Informe valor a ser debitado: ";
            std::cin >> moneyAccount;
            std::cout << "Novo saldo na conta " << accountNumber << ": " << GCMBank.GetBalance(accountNumber);
        } else if (option == 5) {
            std::cout << "Informe conta a ser creditada: ";
            std::cin >> accountNumber;
            std::cout << "Informe conta a ser debitada: ";
            std::cin >> accountNumberDebit;
            std::cout << "Insira o valor a ser transferido: ";
            std::cin >> moneyAccount;
            GCMBank.Transfer(accountNumber, accountNumberDebit, moneyAccount);
        } else if (option == 0) {
            std::cout << "Saindo..." << std::endl;
        } else {
            std::cout << "Opção inválida!" << std::endl;
        }
        
    }
}

int main() {
    run();
    return 0;
}