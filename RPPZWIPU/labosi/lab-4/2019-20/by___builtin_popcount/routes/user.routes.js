const express = require('express');
const router = express.Router();
const Address = require('../models/AddressModel');
const Order = require('../models/OrderModel');


//prikaz podataka o korisniku (podaci o korisniku, adrese, narudžbe)
router.get('/', function (req, res, next) {

    (async () => {

        //ako korisnik nije logiran, redirekcija na osnovnu stranicu
        if (req.session.user === undefined) {
            res.redirect('/');
            return;
        }

        //dobavi adresu korisnika
        let address = await Address.fetchByUser(req.session.user);

        //dobavi narudžbe korisnika
        let orders = await Order.fetchByUser(req.session.user);

        res.render('user', {
            title: 'User profile',
            user: req.session.user,
            address: address[0],
            orders: orders,
            linkActive: 'user'
        });
    })();
});

module.exports = router;