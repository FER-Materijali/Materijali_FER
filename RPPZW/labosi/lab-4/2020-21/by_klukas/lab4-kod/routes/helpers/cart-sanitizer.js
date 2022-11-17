function cartSanitizer(req, res, next) {

    if ((req.session.cart !== undefined) && (req.session.cart.invalid === true)) {
        delete req.session.cart;
        console.log("Cart in inconsistent state");
        req.session.save(() => {
            //redirekcija na osnovnu stranicu
            res.redirect('/cart');
        });
    } else {
        console.log("Cart state OK");
        next();
    }
}

module.exports = cartSanitizer;