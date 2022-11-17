const express = require('express');
const router = express.Router();
const Order = require('../models/OrderModel')
const Address = require('../models/AddressModel')
const authHandler = require('./helpers/auth-handler');
const cartExistence = require('./helpers/cart-existence');

//prikaz košarice
// Ulančavanje funkcija međuopreme
router.post('/', cartExistence, authHandler, function (req, res, next) {

    //brisanje košarice nakon kupovine
    if (req.session.cart !== undefined) {
        req.session.cart.invalid = true;
    }

    (async () => {

        //dohvaćanje primarne adrese korisnika
        let addresses = await Address.fetchByUser(req.session.user);
        let address = addresses[0];


        //stvaranje zapisa narudžbe u tablici order
        let order = new Order(req.session.user, address, req.session.cart);
        await order.persist();

        req.session.promo = undefined

        res.render('checkout', {
            title: 'Cart Checkout',
            linkActive: 'cart',
            user: req.session.user,
            cart: req.session.cart,
            err: undefined
        });
    })()
});

module.exports = router;