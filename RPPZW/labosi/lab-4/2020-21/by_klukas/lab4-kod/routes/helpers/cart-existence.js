function cartExistence(req, res, next) {
    //mora bit definirana košarica
    if (req.session.cart === undefined) {
        console.log("Cart object non existing.");
        //redirekcija na osnovnu stranicu
        res.redirect('/');
    } else {
        console.log("Cart object existing.");
        next();
    }
}

module.exports = cartExistence;