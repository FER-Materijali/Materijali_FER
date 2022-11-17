const express = require('express');
const router = express.Router();

//ZADATAK:
// - obrisati sadržaj košarice
// - odjaviti registriranog korisnika iz sustava
// - napraviti redirect na osnovnu stranicu
router.get('/', function (req, res, next) {
    req.session.user = undefined;
    req.session.cart = undefined;
    req.session.history = undefined;

    req.session.destroy((err) => {
        if (err) {
            console.log(err);
            res.sendStatus(500);
        } else {
            res.redirect('/');
        }
    });

});

module.exports = router;