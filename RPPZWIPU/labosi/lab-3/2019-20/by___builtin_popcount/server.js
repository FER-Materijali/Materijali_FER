/*
    Ovaj file je uz manje izmjene preuzet iz primjera 8 u 9. lekciji (Dinamički web 2)
    https://gitlab.com/fer-wim1/docs/-/blob/master/src/9.%20DYN-WEB-2/pr08-MVC-mybooks-validation/server.js
 */

const express = require('express');
const app = express();
const path = require('path');

const homeRouter = require('./routes/home.routes');
const orderRouter = require('./routes/order.routes');
const managementRouter = require('./routes/management.routes');

app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');

app.use(express.static(path.join(__dirname, 'public')));

app.use(express.urlencoded({extended: true}));
app.use('/', homeRouter);
app.use('/order', orderRouter);
app.use('/management', managementRouter);


app.listen(3000);
