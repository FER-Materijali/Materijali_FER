const express = require('express');
const router = express.Router();
const Order = require('../models/OrderModel');
const Address = require('../models/AddressModel');

//prikaz košarice
router.get('/', function (req, res, next) {

    //brisanje košarice nakon kupovine
    if (req.session.cart !== undefined)
        req.session.cart.invalid = true;

    if (req.session.user) {
        req.app.userData.store();
    }

    (async () => {

        //moraju biti logiran korisnik i definirana košarica
        if ((req.session.user === undefined) || (req.session.cart === undefined)) {
            res.redirect('/');
            return;
        }

        //dohvaćanje primarne adrese korisnika
        let addresses = await Address.fetchByUser(req.session.user);
        let address = addresses[0];


        //stvaranje zapisa narudžbe u tablici order
        let order = new Order(req.session.user, address, req.session.cart);
        await order.persist();

        res.render('checkout', {
            title: 'Cart Checkout',
            linkActive: 'checkout',
            user: req.session.user,
            cart: req.session.cart,
            history: req.session.history,
            err: undefined
        });


    })();
});


module.exports = router;