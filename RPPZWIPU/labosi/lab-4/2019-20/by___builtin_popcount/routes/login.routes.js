const express = require('express');
const router = express.Router();
const User = require('../models/UserModel');

//ZADATAK: vrati login stranicu
router.get('/', function (req, res, next) {
    res.render('login', {
        title: 'Log in',
        linkActive: 'login',
        user: req.session.user,
        err: undefined,
    });
});

//ZADATAK: postupak prijave korisnika
router.post('/', function (req, res, next) {
    (async () => {
        let user = await User.fetchByUsername(req.body.user);

        if (user.id === undefined) {
            res.render('Login', {
                title: 'Log in',
                linkActive: 'login',
                user: req.session.user,
                err: 'Unknown username',
            });
            return;
        }

        if (!user.checkPassword(req.body.password)) {
            res.render('Login', {
                title: 'Log in',
                linkActive: 'login',
                user: req.session.user,
                err: 'Wrong password',
            });
            return;
        }

        req.session.user = user;
        res.redirect('/');
    })();
});


module.exports = router;