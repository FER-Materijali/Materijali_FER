var express = require('express')
var router = express.Router()
var db = require("../db/index")
var { body, validationResult } = require('express-validator')

router.get('/:id([0-9]+)', async function(req, res, next) {

    let id = parseInt(req.params.id);

    var item = (await db.query("select * from inventory where id = $1", [id])).rows[0]

    if (!item) res.status(404).send("The item you asked for does not exist!")

    else {
        var category = (await db.query("select * from categories where id = $1", [item.categoryid])).rows[0]

        var suppliers = (await db.query("select * from suppliers where supplierfor = $1", [id])).rows

        res.render('item', {
            title: item.name,
            linkActive: 'order',
            item: item,
            category: category,
            suppliers: suppliers,
            index: id
        }) 
    }

})

router.get('/:id([0-9]+)/addsupplier', async function(req, res, next) {

    let id = parseInt(req.params.id);

    var item = (await db.query("select * from inventory where id = $1", [id])).rows[0]

    if (!item) res.status(404).send("The item you asked for does not exist!")

    else {

        res.render('addSupplier', {
            linkActive: 'order',
            item: item,
        })

    }

})

router.post('/:id/addsupplier', 
    [
        body('name').trim().isLength({min: 2, max: 22}),
        body('country').trim().isLength({min: 2, max: 22}),
        body('county').trim().isLength({min: 2, max: 22}),
        body('email').trim().isEmail(),
        body('suppliersince').trim().isInt({min: 1945, max: 2021}).toInt()
    ],
    async function(req, res, next) {

        var err = validationResult(req);

        var id = parseInt(req.params.id)

        console.log(req.body)

        console.log(err)

        if (err.isEmpty()) {

            try {

                await db.query(
                    "insert into suppliers (name, country, county, email, suppliersince, supplierFor) values ($1, $2, $3, $4, $5, $6)",
                    [req.body.name, req.body.country, req.body.county, req.body.email, req.body.suppliersince, id]
                )

                res.redirect(`/item/${id}`)

            } catch (error) {

                console.log(error.message)

                res.render('error', {
                    title: "Error",
                    linkActive: "order",
                    errors: err.array(),
                    errDB: error.message,
                    itemID: id
                })
               
            }

        } else {
            res.render('error', {
                title: "Error",
                linkActive: "order",
                errors: err.array(),
                itemID: id
            })
        }

})

module.exports = router