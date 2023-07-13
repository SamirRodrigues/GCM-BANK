const Account = require("./Account");

class SavingAccount extends Account {
	constructor(number){
		super();
		this.number = number;
		this.type = "savingAccount";
	}
	yieldInterest(interestRate) {
		if(interestRate >= 0) {
			this.balance += ((this.balance/100) * interestRate);
		}
	}
}

module.exports = SavingAccount;
