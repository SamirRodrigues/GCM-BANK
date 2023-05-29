#include "libs/Bank.hpp"

enum accountTypes
{
  SIMPLE = 1,
  BONUS = 2,
  SAVINGS = 3
}; 

void CadastrarConta(Bank *bank) {
  int accountType;
  float initialBalance;

  while (true)
  {
    
    std::cout << "Escolha o Tipo de Conta" << std::endl;
    std::cout << "1- Conta Comum" << std::endl;
    std::cout << "2- Conta Bonus" << std::endl;
    std::cout << "3- Conta Poupança" << std::endl;
    std::cout << "=> ";    

    std::cin >> accountType;
    std::cout << std::endl; 

   if(accountType != SIMPLE && accountType != BONUS && accountType != SAVINGS)
    {
      std::cout << ">>> Favor informar um tipo de conta válido <<<" << std::endl; 
      std::cout << std::endl;     
    }
    else
    {
        break;
    }
  }  

  int accountNumber;

  std::cout << "Digite o Número da Conta" << std::endl;
  std::cout << "=> ";
  std::cin >> accountNumber;
  
  if(accountType == SAVINGS || accountType == SIMPLE )
  {
    std::cout << "Qual o saldo inicial?" << std::endl;
    std::cin >> initialBalance;
  }
  else
  {
    initialBalance = 0;
  }
  
  bank->AddAccount(accountNumber, accountType, initialBalance);
  std::cout << "Conta Cadastrada Com Sucesso!" << std::endl;
}

void Creditar(Bank *bank) {
  int accountNumber;
  int value;
  std::cout << "Digite o Número da Conta" << std::endl;
  std::cout << "=> ";
  std::cin >> accountNumber;
  std::cout << "Digite o valor a ser Creditado na conta " << accountNumber << ": ";
  std::cin >> value;
  bank->CreditAccount(accountNumber, value);
  std::cout << value << " Creditado com sucesso" << std::endl;
}

void RenderJuros(Bank *bank){
  int accountNumber;
  float value;
  std::cout << "Digite o Número da Conta" << std::endl;
  std::cout << "=> ";
  std::cin >> accountNumber;
  std::cout << "Digite a taxa de juros para ser calculado a conta " << accountNumber << ": ";
  std::cin >> value;
  bank->ApplyYield(accountNumber, value);
}

void run() {

    Bank GCMBank;
    int option = 1;
    int accountNumber,accountNumberDebit , moneyAccount, initialBalance;

    while(option != 0) {
        std::cout << std::endl << "==============================" << std::endl;
        std::cout << "Escolha a operação a ser realizada!" << std::endl;
        std::cout << "1 - Cadastrar nova conta" << std::endl;
        std::cout << "2 - Consultar Saldo" << std::endl;
        std::cout << "3 - Crédito de Conta" << std::endl;
        std::cout << "4 - Débito de conta" << std::endl;
        std::cout << "5 - Transferiência entre contas" << std::endl;
        std::cout << "6 - Render Juros" << std::endl;
        std::cout << "0 - Sair" << std::endl;
        std::cout << "=> ";
        std::cin >> option;

        if(option == 1) {
            CadastrarConta(&GCMBank);
        } else if (option == 2) {
            std::cout << "Informe o número da conta a ser consultada: ";
            std::cin >> accountNumber;
            std::cout << "Saldo da Conta " << accountNumber << ": " << GCMBank.GetBalance(accountNumber) << std::endl;
        } else if (option == 3) {
            Creditar(&GCMBank);
        } else if (option == 4) {
            std::cout << "Informe númeração da conta a ser debitada: ";
            std::cin >> accountNumber;
            std::cout << "Informe valor a ser debitado: ";
            std::cin >> moneyAccount;
            if(moneyAccount < 0) {
                while(moneyAccount < 0) {
                    std::cout << "Valor não pode ser negativo, tente novamente!" << std::endl;
                    std::cout << "Informe valor a ser debitado: ";
                    std::cin >> moneyAccount;
                }
            }
            GCMBank.DebitAccount(accountNumber, moneyAccount);
            std::cout << "Novo saldo na conta " << accountNumber << ": " << GCMBank.GetBalance(accountNumber);
        } else if (option == 5) {
            std::cout << "Informe conta a ser debitada: ";
            std::cin >> accountNumberDebit;
            std::cout << "Informe conta a ser creditada: ";
            std::cin >> accountNumber;
            std::cout << "Insira o valor a ser transferido: ";
            std::cin >> moneyAccount;
            if(moneyAccount < 0) {
                while(moneyAccount < 0) {
                    std::cout << "Valor não pode ser negativo, tente novamente!" << std::endl;
                    std::cout << "Insira o valor a ser transferido: ";
                    std::cin >> moneyAccount;
                }
            }
            GCMBank.Transfer(accountNumberDebit, accountNumber, moneyAccount);
        } else if (option == 6) {
            RenderJuros(&GCMBank);
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