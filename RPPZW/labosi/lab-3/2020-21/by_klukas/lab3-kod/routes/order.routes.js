var express = require('express')
var router = express.Router()
var db = require("../db/index")

router.get('/', async function(req, res, next) {

    var categories = (await db.query('select * from categories order by id asc')).rows
    var inventory = (await db.query('select * from inventory order by id asc')).rows

    for (category of categories) {
        category.inventory = []
        for (item of inventory) {
            if (item.categoryid == category.id) {
                category.inventory.push(item)
            }
        }
    }

    res.render('order', {
        title: 'Order',
        linkActive: 'order',
        categories: categories,
    })
})

module.exports = router