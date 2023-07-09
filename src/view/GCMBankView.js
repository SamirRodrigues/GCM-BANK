const Bank = require('../controller/Bank.js');
const Account = require('../model/Account.js');
const prompt = require("prompt-sync")();

const bank = new Bank();


do {
    console.log("=====GCM-Bank=====");
    console.log("Escolha a operação a ser realizada!");
    console.log("1 - Cadastrar nova conta");
    console.log("2 - Consultar Saldo");
    console.log("3 - Crédito de Conta");
    console.log("4 - Débito de conta");
    console.log("5 - Transferiência entre contas");
    console.log("0 - Sair");
    var option = prompt("=>");

    if(option == 1) {
        let accountNumber= prompt("Insira um número para a conta: ");
        bank.createAccount(accountNumber);
        console.log("Conta adicionada!");
    } else if (option == 2) {
        let accountToConsult = prompt("Informe o número da conta a ser consultada: ");
        let accountReturned = bank.getAccount(accountToConsult);
        console.log("Saldo da Conta " + accountReturned.getNumber() + ": " + accountReturned.getBalance());
    } else if (option == 3) {
        let accountNumber = prompt("Informe o número de conta a ser creditada: ");
        let amountToCredit= prompt("Insira o valor de crédito: ");
        let accountReturned = bank.getAccount(accountNumber);
        if(amountToCredit < 0) {
            while(amountToCredit < 0) {
                console.log("Valor não pode ser negativo, tente novamente!");
                amountToCredit = prompt("Insira o valor de crédito: ");
            }
        }
        accountReturned.credit(amountToCredit);
    } else if (option == 4) {
        let accountToConsult = prompt("Informe o número da conta a ser debitada: ");
        let amountToDebit= prompt("Informe valor a ser debitado: ");
        let accountReturned = bank.getAccount(accountToConsult);
        if(amountToDebit < 0) {
            while(moneyAccount < 0) {
                console.log("Valor não pode ser negativo, tente novamente!");
                amountToDebit = prompt("Informe valor a ser debitado: ");
            }
        }
        accountReturned.debit(amountToDebit);
    } else if (option == 5) {
        let accountNumberDebit = prompt("Informe conta a ser debitada: ");
        let accountNumberCredit= prompt("Informe conta a ser creditada: ");
        let amountToTransfer = prompt("Insira o valor a ser transferido: ");
        if(amountToTransfer < 0) {
            while(amountToTransfer < 0) {
                console.log("Valor não pode ser negativo, tente novamente!");
                amountToTransfer = prompt("Insira o valor a ser transferido: ");
            }
        }
        bank.transfer(accountNumberDebit, accountNumberCredit, amountToTransfer);
    } else if (option == 0) {
        console.log("Saindo...");
    } else {
        console.log("Opção inválida!");
    }
} while(option != 0)
