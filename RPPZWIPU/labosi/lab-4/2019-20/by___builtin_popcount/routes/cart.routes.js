const express = require('express');
const router = express.Router();
const cart = require('../models/CartModel');

//ZADATAK prikaz košarice uz pomoć cart.ejs
router.get('/', function (req, res, next) {
    res.render('cart', {
        title: 'Cart',
        linkActive: 'cart',
        user: req.session.user,
        cart: req.session.cart,
        history: req.session.history,
    });
});

//ZADATAK: dodavanje jednog artikla u košaricu
router.get('/add/:id', function (req, res, next) {
    (async () => {
        await cart.addItemToCart(req.session.cart, req.params.id, 1);

        req.session.history.unshift(await cart.getItemData(req.params.id));
        req.session.history = req.session.history.slice(0, 5);

        if (req.session.user) {
            req.app.userData.store();
        }

        res.end();
    })();
});

//ZADATAK: brisanje jednog artikla iz košarice
router.get('/remove/:id', function (req, res, next) {
    (async () => {
        await cart.removeItemFromCart(req.session.cart, req.params.id, 1);

        if (req.session.user) {
            req.app.userData.store();
        }

        res.end();
    })();
});

router.get('/clear/:id', function (req, res, next) {
    (async () => {
        await cart.clearFromCart(req.session.cart, req.params.id);

        if (req.session.user) {
            req.app.userData.store();
        }

        res.end();
    })();
});

module.exports = router;