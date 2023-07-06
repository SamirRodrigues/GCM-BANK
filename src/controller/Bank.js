const Account = require('../model/Account');
const BonusAccount = require('../model/BonusAccount');
const SavingAccount = require('../model/SavingAccount');

class Bank {
    constructor() {
        this.accounts = [];
    }

    getAllAccounts() {
        return this.accounts;
    }

    getAccount(number) {
        var accountToReturn;
        this.accounts.forEach(account => {
            if (account.number == number) {
                accountToReturn = account;
            }
        });
        return accountToReturn;
    }

    createAccount(number) {
        this.accounts.push(new Account(number));
    }
    createBonusAccount(number) {
        this.accounts.push(new BonusAccount(number));
    }
    createSavingAccount(number) {
        this.accounts.push(new SavingAccount(number));
    }

    creditAccount(number, amount) {
        var accountToReturn;
        this.accounts.forEach(account => {
            if (account.number == number) {
                accountToReturn = account;
            }
        });
        if(accountToReturn) {
            accountToReturn.credit(amount);
        }
    }

    debitAccount(number, amount) {
        var accountToReturn;
        this.accounts.forEach(account => {
            if (account.number == number) {
                accountToReturn = account;
            }
        });
        if(accountToReturn) {
            accountToReturn.debit(amount);
        }
    }

    transfer(fromAccount, toAccount, amount) {
        var fromAccountReturn, toAccountReturn;

        this.accounts.forEach(account => {
            if(account.number == fromAccount) {
                fromAccountReturn = account;
            }
        });
        if(fromAccountReturn) {
            fromAccountReturn.debit(amount);
        }

        this.accounts.forEach(account => {
            if(account.number == toAccount) {
                toAccountReturn = account;
            }
        });
        if(toAccountReturn) {
            if(toAccountReturn.type == 'bonusAccount') {
                toAccountReturn.depositByTransfer(amount);
            } else {
                toAccountReturn.deposit(amount);
            }
        }
    }

    yield(account, interestRate) {
        var accountReturned;

        this.accounts.forEach(a => {
            if(a.number == account && a.type == "savingAccount") {
                accountReturned = a;
            }
        })
        if(accountReturned) {
            accountReturned.yieldInterest(interestRate);
        }
    }
}

module.exports = Bank;
