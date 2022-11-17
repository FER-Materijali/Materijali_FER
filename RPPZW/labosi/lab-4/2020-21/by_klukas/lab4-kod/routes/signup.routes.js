const express = require('express');
const router = express.Router();
const User = require('../models/UserModel')
const Address = require('../models/AddressModel')


//vrati signup stranicu
router.get('/', function (req, res, next) {
    res.render('signup', {
        title: 'Register a new user',
        linkActive: 'signup',
        user: req.session.user,
        err: undefined
    });
});

router.post('/', function (req, res, next) {

    (async () => {
        //provjeri istovjetnost unesenenih zaporki
        if (req.body.password1 !== req.body.password2) {
            res.render('Signup', {
                title: 'Register a new user',
                linkActive: 'signup',
                user: req.session.user,
                err: "Password entries do not match"
            });
            return;
        }

        //dobavi podatke o korisniku iz baze podataka
        let user = await User.fetchByUsername(req.body.username);
        let userEmail = await User.fetchByEmail(req.body.email);

        //ako korisnik postoji, javi grešku
        if (user.id !== undefined) {
            res.render('Signup', {
                title: 'Register a new user',
                linkActive: 'signup',
                user: req.session.user,
                err: "Username already exists"
            });
            return;
        } else if (userEmail.id !== undefined) {
            res.render('Signup', {
                title: 'Register a new user',
                linkActive: 'signup',
                user: req.session.user,
                err: "Email already exists"
            });
            return;
        }

        //registriraj novog korisnika
        user = new User(req.body.username, req.body.firstName, req.body.lastName, req.body.email, req.body.password1);
        await user.persist();

        //stvori adresu korisnika
        address = new Address(user, user.first_name + " " + user.last_name, req.body.street, req.body.postcode, req.body.city, req.body.country);
        await address.persist();
        //####################### ZADATAK #######################
        // registracija novog korisnika

        // Potrebno je dodati sljedeću funkcionalnost:
        // - ako je prijava uspjela, povezati sjednicu s registriranim korisnikom
        // - napraviti redirect na home stranicu

        //#######################################################

        req.session.user = user
        res.redirect('/')
    })()

});


module.exports = router;