const  Bank  = require('../controller/Bank');

describe('Bank', () => {
  const bank = new Bank();

  test('criar conta comum', () => {
    bank.createBonusAccount(18);
    const account = bank.getAccount(18);
    expect(account);
  });

  test('criar conta bônus', () => {
    bank.createBonusAccount(19);
    const account = bank.getAccount(19);
    expect(account);
  });

  test('criar conta poupança', () => {
    bank.createBonusAccount(20);
    const account = bank.getAccount(20);
    expect(account);
  });

  test('consultar conta comum', () => {
    bank.createAccount(16);
    const account = bank.getAccount(16);
    account.credit(100);
    expect(account.getBalance()).toBeCloseTo(100, 2);
  });

  test('consultar conta bônus', () => {
    bank.createBonusAccount(17);
    const account = bank.getAccount(17);
    account.credit(100);
    expect(account.getBalance()).toBeCloseTo(100, 2);
  });

  test('consultar conta poupança', () => {
    bank.createBonusAccount(18);
    const account = bank.getAccount(18);
    account.credit(100);
    expect(account.getBalance()).toBeCloseTo(100, 2);
  });

  test('operação de crédito', () => {
    bank.createAccount(1);
    const account = bank.getAccount(1);
    account.credit(200);
    expect(account.getBalance()).toBeCloseTo(200, 2);
  });

  test('valor de crédito negativo', () => {
    bank.createAccount(2);
    const account = bank.getAccount(2);
    expect(() => {
      account.credit(-200);
    }).toThrowError();
  });

  test('bonificação depois da operação de crédito ', () => {
    bank.createBonusAccount(3);
    const account = bank.getAccount(3);
    account.credit(200);
    expect(account.points).toBeCloseTo(12, 2);
  });

  test('operação de débito', () => {
    bank.createAccount(4);
    const account = bank.getAccount(4);
    account.credit(1000);
    account.debit(200);
    expect(account.getBalance()).toBeCloseTo(800, 2);
  });

  test('valor negativo de débito', () => {
    bank.createAccount(5);
    const account = bank.getAccount(5);
    expect(() => {
      account.debit(-200);
    }).toThrowError();
  });

  test('débito no caso de o saldo ficar negativo', () => {
    bank.createAccount(6);
    const account = bank.getAccount(6);
    expect(() => {
      account.debit(1200);
    }).toThrowError();
  });

  test('tranferência', () => {
    bank.createAccount(7);
    const account1 = bank.getAccount(7);
    account1.credit(1000);
    bank.createAccount(500);
    const account2 = bank.getAccount(500);
    account2.credit(500);
    bank.transfer(7, 500, 200);
    expect(account1.getBalance()).toBeCloseTo(800, 2);
    expect(account2.getBalance()).toBeCloseTo(700, 2);
  });

  test('transferência de valor negativo', () => {
    bank.createAccount(8);
    const account1 = bank.getAccount(8);
    account1.credit(200);
    bank.createAccount(9);
    const account2 = bank.getAccount(9);
    account2.credit(100);
    expect(() => {
      bank.transfer(8, 9, -200);
    }).toThrowError();
  });

  test('transferência caso um saldo fique negativo', () => {
    bank.createAccount(10);
    const account = bank.getAccount(10);
    account.credit(1000);
    bank.createAccount(11);
    expect(() => {
      bank.transfer(10, 11, 1200);
    }).toThrowError();
  });

  test('bonificação na operação de transferência', () => {
    // fator de bônus de 0.1
    bank.createBonusAccount(12);
    const account1 = bank.getAccount(12);
    account1.credit(200);
    bank.createAccount(13);
    const account2 = bank.getAccount(13);
    account2.credit(2);
    bank.transfer(12, 13, 200);
    expect(account1.points).toBeCloseTo(12, 2);
    expect(account2.points).toBeCloseTo(11, 2);
  });

  test('rendimento da conta', () => {
    //taxa de rendimento de 0.01
    bank.createSavingAccount(14);
    const account = bank.getAccount(14);
    account.credit(1000);
    account.yieldInterest(1);
    expect(account.getBalance()).toBeCloseTo(1010, 2);
  });
});