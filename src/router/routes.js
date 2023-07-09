const { Router } = require("express");
const Bank = require('../controller/Bank');

const router = Router();
const bank = new Bank();

/**
 * API Rest endpoints
 */
router.get('/isrunning', (req, res) => {
    return res.send('Server is Running!');
})

router.get('/bank/getAccounts', (req, res) => {
    const accounts = bank.getAllAccounts();
    return res.json ({
        statusCode: 200,
        accounts
    });
})

/**
 * create account
 */
router.post('/bank/account', (req, res) => {
    bank.createAccount(req.body.number);
    return res.json({
        statusCode: 200,
        message: "Account was created!"
    });
});

/**
 * create Bonus account
 */
router.post('/bank/bonusaccount', (req, res) => {
    bank.createBonusAccount(req.body.number);
    return res.json({
        statusCode: 200,
        message: "Account was created!"
    });
});

/**
 * create Saving account
 */
router.post('/bank/savingaccount', (req, res) => {
    bank.createSavingAccount(req.body.number);
    return res.json({
        statusCode: 200,
        message: "Account was created!"
    });
});

/**
 * account
 */
router.get('/bank/:account', (req, res) => {
    const returnedAccount = bank.getAccount(req.params.account);
    return res.json({
        accout: returnedAccount
    })
});

/**
 * account balance
 */
router.get('/bank/:account/balance', (req, res) => {
    const returnedAccount = bank.getAccount(req.params.account);
    return res.json({
        account: returnedAccount.number,
        balance: returnedAccount.balance
    })
});

/**
 * credit account
 */
router.put('/bank/:account/credit', (req, res) => {
    bank.creditAccount(req.params.account, req.body.amount);
    return res.json ({
        statusCode: 200,
        message: "account was credited!"
    });
});

/**
 * debit account
 */
router.put('/bank/:account/debit', (req, res) => {
    bank.debitAccount(req.params.account, req.body.amount);
    return res.json ({
        statusCode: 200
    });
});

/**
 * transfer money
 */
router.put('/bank/account/transfer', (req, res) => {
    bank.transfer(req.body.fromAccount, req.body.toAccount, req.body.amount);
    return res.json ({
        statusCode: 200
    });
});

/**
 * Yield Interest
 */
router.put('/bank/:account/yield', (req, res) => {
    bank.yield(req.params.account, req.body.rate);
    return res.json ({
        statusCode: 200
    });
});

module.exports = router;
