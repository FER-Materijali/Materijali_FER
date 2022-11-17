const express = require('express');
const router = express.Router();
const authHandler = require('./helpers/auth-handler');

router.get('/', function (req, res, next) {

    if (req.session.user) {

        res.render('promotional', {
            title: 'Promotional',
            user: req.session.user,
            linkActive: 'cart',
            promo: req.session.promo
        })

    }

    else {

        res.render('login', {
            title: 'Login',
            linkActive: 'login',
            user: req.session.user,
            err: 'Please login to view the requested page.'
        })

    }
    
})

router.post('/reset', async function (req, res, next) {
    req.session.promo = undefined
    res.redirect('/promotional')
})

router.post('/save', async function (req, res, next) {
    if (req.body.promocode !== '') {
        req.session.promo = [req.body.promocode, req.body.promotype]
    }
    res.redirect('/cart')
})

module.exports = router