/*
    Ovaj file je baziran na primjeru 4 u 9. lekciji (Dinamički web 2)
    https://gitlab.com/fer-wim1/docs/-/blob/master/src/9.%20DYN-WEB-2/pr04s18-MVC-mybooks-readonly/routes/books.routes.js
 */

const express = require('express');
const router = express.Router();
const db = require('../db');


router.get('/', async function (req, res) {
    /*
        Koristim Promise.all kako bi se zahtjevi na bazu mogli izvršavati istovremeno.
        Moguće je i napisati nešto ovakvo, ali onda server čeka da prvi zahtjev završi prije nego se započne drugi:

        const categories = (await db.query('SELECT * FROM categories')).rows;
        const items = (await db.query('SELECT * FROM inventory')).rows;
     */
    const [categories, items] = (await Promise.all([
        db.query('SELECT * FROM categories'),
        db.query('SELECT * FROM inventory'),
    ])).map(result => result.rows);

    // Iteriram po objektima u nizu category, i dodajem im array samo s proizvodima koji su u toj kategoriji.
    for (const category of categories) {
        category.items = items.filter(item => (item.categoryid === category.id));
    }

    res.render('order', {
        title: 'Order',
        linkActive: 'order',
        categories: categories,
    });
});

module.exports = router;
