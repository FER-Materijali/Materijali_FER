/*
    Ovaj file je uz manje izmjene preuzet iz primjera 8 u 9. lekciji (Dinamički web 2)
    https://gitlab.com/fer-wim1/docs/-/blob/master/src/9.%20DYN-WEB-2/pr08-MVC-mybooks-validation/routes/home.routes.js
 */

const express = require('express');
const router = express.Router();


router.get('/', function (req, res) {
    res.render('home', {
        title: 'Home',
        linkActive: 'home',
    });
});

module.exports = router;
