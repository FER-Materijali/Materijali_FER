const express = require('express');
const router = express.Router();

router.get('/', function (req, res, next) {
    res.render('home', {
        title: 'Home',
        user: req.session.user,
        linkActive: 'home'
    });
});

module.exports = router;