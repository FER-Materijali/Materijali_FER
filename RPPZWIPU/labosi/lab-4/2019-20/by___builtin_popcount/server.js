//uvoz modula
const express = require('express');
const app = express();
const path = require('path');
const pg = require('pg');
const db = require('./db');
const session = require('express-session');
const pgSession = require('connect-pg-simple')(session);
const cart = require('./models/CartModel');
const UserData = require('./models/UserData');

//uvoz modula s definiranom funkcionalnosti ruta
const homeRouter = require('./routes/home.routes');
const orderRouter = require('./routes/order.routes');
const loginRoute = require('./routes/login.routes');
const logoutRoute = require('./routes/logout.routes');
const signupRoute = require('./routes/signup.routes');
const cartRoute = require('./routes/cart.routes');
const userRoute = require('./routes/user.routes');
const checkoutRoute = require('./routes/checkout.routes');

//middleware - predlošci (ejs)
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');

//middleware - statički resursi
app.use(express.static(path.join(__dirname, 'public')));

//middleware - dekodiranje parametara
app.use(express.urlencoded({extended: true}));

//middleware - upravljanje sjednicama (+ trajne sjednice u bazi podataka)
//ZADATAK: postaviti express-sessions midlleware, trajnost sjedničkog kolačića 1 dan,
//pohrana sjednica u postgres bazu korštenjem connect-pg-simple modula
app.use(session({
    store: new pgSession({
        pool: db.pool,
    }),
    secret: 'FER WiM',
    resave: false,
    saveUninitialized: true,
    cookie: {maxAge: 24 * 60 * 60 * 1000}, // 1 dan
}));

app.use((req, res, next) => {
    if (req.session.user) {
        const user = req.session.user;
        const userData = req.app.userData;

        if (!userData.userExists(user.email)) {
            userData.createUser(user.email);
        }

        const userDataUser = userData.getUser(user.email);

        if (userDataUser.cart === undefined || userDataUser.cart.invalid) {
            userDataUser.cart = cart.createCart();
        }

        req.session.cart = userDataUser.cart;
    } else if (req.session.cart === undefined || req.session.cart.invalid) {
        req.session.cart = cart.createCart();
    }
    next();
});

app.use((req, res, next) => {
    next();
});

app.use((req, res, next) => {
    if (req.session.history === undefined) {
        req.session.history = [];
    }
    next();
});

//definicija ruta
app.use('/', homeRouter);
app.use('/order', orderRouter);
app.use('/login', loginRoute);
app.use('/logout', logoutRoute);
app.use('/signup', signupRoute);
app.use('/cart', cartRoute);
app.use('/user', userRoute);
app.use('/checkout', checkoutRoute);

app.userData = new UserData('users.json');
app.userData.initialize(true);

//pokretanje poslužitelja na portu 3000
app.listen(3000);