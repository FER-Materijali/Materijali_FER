const express = require('express');
const router = express.Router();
const User = require('../models/UserModel')


router.get('/', function (req, res, next) {

    res.render('login', {
        title: 'Login',
        linkActive: 'login',
        user: req.session.user,
        err: undefined
    })
})

router.post('/', async function (req, res, next) {

    let user = undefined
    user = await User.fetchByUsername(req.body.user)

    if (user && user.checkPassword(req.body.password)) {
        req.session.user = user
        res.redirect('/')
    }

    else {
        res.render('login', {
            title: 'Login',
            linkActive: 'login',
            user: req.session.user,
            err: 'User does not exist or incorrect password.'
        })
    }

})

module.exports = router;