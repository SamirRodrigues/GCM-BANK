class Account {
    constructor(number) {
        this.number = number;
        this.balance = parseFloat(0);
    }

    getNumber() {
        return this.number;
    }

    getBalance() {
        return this.balance;
    }

    credit(amount) {
        if(amount >= 0) {
            this.balance += parseFloat(amount);
        }
    }

    debit(amount) {
        if(amount < this.balance) {
            this.balance -= parseFloat(amount);
        }
    }


}

module.exports = Account;
