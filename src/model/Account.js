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
		else
		{
			throw new Error("Não é possível creditar valores negativos");
		}
	}

	debit(amount) {
		if(amount <= this.balance && amount >= 0) {
			this.balance -= parseFloat(amount);
		}
		else
		{
			throw new Error("Não é possível debitar o valor solicitado, pois o saldo ficará negativo");
		}
	}


}

module.exports = Account;
