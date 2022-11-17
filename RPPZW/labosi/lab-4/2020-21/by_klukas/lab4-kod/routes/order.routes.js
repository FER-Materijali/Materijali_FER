const express = require('express');
const router = express.Router();
const db = require('../db');

router.get('/', async function (req, res, next) {
    const sqlCategories = `SELECT * FROM categories ORDER BY id;`;
    const sqlInventory = `SELECT * FROM inventory ORDER BY categoryid, id;`;
    try {
        const resultCategories = (await db.query(sqlCategories, [])).rows;
        const resultInventory = (await db.query(sqlInventory, [])).rows;
        let categoryItemMap = {};
        for (let category of resultCategories) {
            categoryItemMap[category.id] = [];
        }
        for (let item of resultInventory) {
            categoryItemMap[item.categoryid].push(item);
        }
        res.render("order", {
            title: 'Order',
            categories: resultCategories,
            categoryItemMap: categoryItemMap,
            user: req.session.user,
            linkActive: 'order',
        });
    } catch (err) {
        console.log(err);
    }
});

module.exports = router;