
const { Bank, CheckingAccount, SavingsAccount, BonusAccount } = require('../controller/Bank');

describe('Bank', () => {
  test('operação de crédito', () => {
    const bank = new Bank();
    const account = bank.createCheckingAccount(1000);
    bank.credit(account, 200);
    expect(account.getBalance()).toBeCloseTo(1200, 2);
  });

  test('valor de crédito negativo', () => {
    const bank = new Bank();
    const account = bank.createCheckingAccount(1000);
    expect(() => {
      bank.credit(account, -200);
    }).toThrowError();
  });

  test('bonificação depois da operação de crédito ', () => {
    const bank = new Bank();
    const account = bank.createBonusAccount(1000, 0.1);
    bank.credit(account, 200);
    expect(account.getBalance()).toBeCloseTo(1220, 2);
  });

  test('operação de débito', () => {
    const bank = new Bank();
    const account = bank.createCheckingAccount(1000);
    bank.debit(account, 200);
    expect(account.getBalance()).toBeCloseTo(800, 2);
  });

  test('valor negativo de débito', () => {
    const bank = new Bank();
    const account = bank.createCheckingAccount(1000);
    expect(() => {
      bank.debit(account, -200);
    }).toThrowError();
  });

  test('débito no caso de o saldo ficar negativo', () => {
    const bank = new Bank();
    const account = bank.createCheckingAccount(1000);
    expect(() => {
      bank.debit(account, 1200);
    }).toThrowError();
  });

  test('tranferência', () => {
    const bank = new Bank();
    const account1 = bank.createCheckingAccount(1000);
    const account2 = bank.createCheckingAccount(500);
    bank.transfer(account1, account2, 200);
    expect(account1.getBalance()).toBeCloseTo(800, 2);
    expect(account2.getBalance()).toBeCloseTo(700, 2);
  });

  test('transferência de valor negativo', () => {
    const bank = new Bank();
    const account1 = bank.createCheckingAccount(1000);
    const account2 = bank.createCheckingAccount(500);
    expect(() => {
      bank.transfer(account1, account2, -200);
    }).toThrowError();
  });

  test('transferência caso um saldo fique negativo', () => {
    const bank = new Bank();
    const account1 = bank.createCheckingAccount(1000);
    const account2 = bank.createCheckingAccount(500);
    expect(() => {
      bank.transfer(account1, account2, 1200);
    }).toThrowError();
  });

  test('bonificação na operação de transferência', () => {
    const bank = new Bank();
    // fator de bônus de 0.1
    const account1 = bank.createBonusAccount(1000, 0.1);
    const account2 = bank.createCheckingAccount(500);
    bank.transfer(account1, account2, 200);
    expect(account1.getBalance()).toBeCloseTo(820, 2);
    expect(account2.getBalance()).toBeCloseTo(700, 2);
  });

  test('rendimento da conta', () => {
    const bank = new Bank();
    //taxa de rendimento de 0.01
    const account = bank.createSavingsAccount(1000, 0.01);
    bank.applyInterest(account);
    expect(account.getBalance()).toBeCloseTo(1010, 2);
  });
});