const Account = require('./Account');

class BonusAccount extends Account {
    constructor(number) {
        super();
        this.number = number;
        this.points = 10;
        this.type = 'bonusAccount';
    }

    getPoints() {
        return this.points;
    }

    credit(amount) {
        if(amount >= 0) {
            let pointsToAdd = parseInt(amount/100);
            this.points += pointsToAdd;
            this.balance += amount;
        }
    }

    depositByTransfer(amount) {
        if(amount >= 0) {
            let pointsToAdd = parseInt(amount/200);
            this.points += pointsToAdd;
            this.balance += amount;
        }
    }
}

module.exports = BonusAccount;
