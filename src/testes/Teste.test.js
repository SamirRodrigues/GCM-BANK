const  Bank  = require('../controller/Bank');

describe('Bank', () => {
  const bank = new Bank();

  test('criar conta comum', () => {
    bank.createBonusAccount(1);
    const account = bank.getAccount(1);
    expect(account);
  });

  test('criar conta bônus', () => {
    bank.createBonusAccount(2);
    const account = bank.getAccount(2);
    expect(account);
  });

  test('criar conta poupança', () => {
    bank.createBonusAccount(3);
    const account = bank.getAccount(3);
    expect(account);
  });

  test('consultar conta comum', () => {
    bank.createAccount(4);
    const account = bank.getAccount(4);
    account.credit(100);
    expect(account.getBalance()).toBeCloseTo(100, 2);
  });

  test('consultar conta bônus', () => {
    bank.createBonusAccount(5);
    const account = bank.getAccount(5);
    account.credit(100);
    expect(account.getBalance()).toBeCloseTo(100, 2);
  });

  test('consultar conta poupança', () => {
    bank.createBonusAccount(6);
    const account = bank.getAccount(6);
    account.credit(100);
    expect(account.getBalance()).toBeCloseTo(100, 2);
  });

  test('operação de crédito', () => {
    bank.createAccount(7);
    const account = bank.getAccount(7);
    account.credit(200);
    expect(account.getBalance()).toBeCloseTo(200, 2);
  });

  test('valor de crédito negativo', () => {
    bank.createAccount(8);
    const account = bank.getAccount(8);
    expect(() => {
      account.credit(-200);
    }).toThrowError();
  });

  test('bonificação depois da operação de crédito ', () => {
    bank.createBonusAccount(9);
    const account = bank.getAccount(9);
    account.credit(200);
    expect(account.points).toBeCloseTo(12, 2);
  });

  test('operação de débito', () => {
    bank.createAccount(10);
    const account = bank.getAccount(10);
    account.credit(1000);
    account.debit(200);
    expect(account.getBalance()).toBeCloseTo(800, 2);
  });

  test('valor negativo de débito', () => {
    bank.createAccount(11);
    const account = bank.getAccount(11);
    expect(() => {
      account.debit(-200);
    }).toThrowError();
  });

  test('débito no caso de o saldo ficar negativo', () => {
    bank.createAccount(12);
    const account = bank.getAccount(12);
    expect(() => {
      account.debit(1200);
    }).toThrowError();
  });

  test('tranferência', () => {
    bank.createAccount(13);
    const account1 = bank.getAccount(13);
    account1.credit(1000);
    bank.createAccount(14);
    const account2 = bank.getAccount(14);
    account2.credit(500);
    bank.transfer(13, 14, 200);
    expect(account1.getBalance()).toBeCloseTo(800, 2);
    expect(account2.getBalance()).toBeCloseTo(700, 2);
  });

  test('transferência de valor negativo', () => {
    bank.createAccount(15);
    const account1 = bank.getAccount(15);
    account1.credit(200);
    bank.createAccount(16);
    const account2 = bank.getAccount(16);
    account2.credit(100);
    expect(() => {
      bank.transfer(15, 16, -200);
    }).toThrowError();
  });

  test('transferência caso um saldo fique negativo', () => {
    bank.createAccount(17);
    const account = bank.getAccount(17);
    account.credit(1000);
    bank.createAccount(18);
    expect(() => {
      bank.transfer(17, 18, 1200);
    }).toThrowError();
  });

  test('bonificação na operação de transferência', () => {
    // fator de bônus de 0.1
    bank.createBonusAccount(19);
    const account1 = bank.getAccount(19);
    account1.credit(200);
    bank.createBonusAccount(20);
    const account2 = bank.getAccount(20);
    bank.transfer(19, 20, 200);
    expect(account1.points).toBeCloseTo(12, 2);
    expect(account2.points).toBeCloseTo(11, 2);
  });

  test('rendimento da conta', () => {
    //taxa de rendimento de 0.01
    bank.createSavingAccount(21);
    const account = bank.getAccount(21);
    account.credit(1000);
    account.yieldInterest(1);
    expect(account.getBalance()).toBeCloseTo(1010, 2);
  });
});