//uvoz modula
const express = require('express')
const app = express()
const path = require('path')
const pg = require('pg')
const db = require('./db')
const session = require('express-session')
const pgSession = require('connect-pg-simple')(session)
const cart = require('./models/CartModel')

//uvoz modula s definiranom funkcionalnosti ruta
const homeRouter = require('./routes/home.routes')
const orderRouter = require('./routes/order.routes')
const loginRoute = require('./routes/login.routes')
const logoutRoute = require('./routes/logout.routes')
const signupRoute = require('./routes/signup.routes')
const cartRoute = require('./routes/cart.routes')
const userRoute = require('./routes/user.routes')
const checkoutRoute = require('./routes/checkout.routes')
const promotionalRouter = require('./routes/promotional.routes')

//middleware - predlošci (ejs)
app.set('views', path.join(__dirname, 'views'))
app.set('view engine', 'ejs')

//middleware - statički resursi
app.use(express.static(path.join(__dirname, 'public')))

//middleware - dekodiranje parametara
app.use(express.urlencoded({ extended: true }))

//####################### ZADATAK #######################

app.use(session({
    store: new pgSession({
        pool: db.pool,
    }),
    secret: "web-lab4",
    resave: false,
    saveUninitialized: true
}))

app.use((req, res, next) => {

    if (req.session.cart === undefined || req.session.cart.invalid) {
        req.session.cart = cart.createCart();
    }
    
    next();
})

//#######################################################


//definicija ruta
app.use('/', homeRouter)
app.use('/order', orderRouter)
app.use('/login', loginRoute)
app.use('/logout', logoutRoute)
app.use('/signup', signupRoute)
app.use('/cart', cartRoute)
app.use('/user', userRoute)
app.use('/checkout', checkoutRoute)
app.use('/promotional', promotionalRouter)

//pokretanje poslužitelja na portu 3000
app.listen(3000)