/*
    Ovaj file je baziran na primjeru 8 u 9. lekciji (Dinamički web 2)
    https://gitlab.com/fer-wim1/docs/-/blob/master/src/9.%20DYN-WEB-2/pr08-MVC-mybooks-validation/routes/books.routes.js

    Način korištenja _order.ejs u templatesima se može vidjeti u primjeru 8 u 9. lekciji (Dinamički web 2)
    https://gitlab.com/fer-wim1/docs/-/blob/master/src/9.%20DYN-WEB-2/pr08-MVC-mybooks-validation/views/addBook.ejs
 */

const express = require('express');
const router = express.Router();
const db = require('../db');
const {
    body,
    validationResult,
} = require('express-validator');


router.get('/', function (req, res) {
    res.render('management', {
        title: 'Management',
        linkActive: 'management',
    });
});

/*********************************************
 *   1. zadatak: Dodavanje novog proizvoda   *
 *********************************************/

router.get('/additem', async function (req, res) {
    const categories = (await db.query('SELECT * FROM categories ORDER BY id')).rows;

    res.render('addItem', {
        title: 'Add Item',
        linkActive: 'management',
        categorySelect: {
            id: 'categoryId',
            name: 'categoryId',
            list: categories.map(category => ({
                name: category.name,
                value: category.id,
            })),
        },
    });
});

router.post(
    '/additem',
    [
        body('name')
            .trim()
            .isLength({min: 3, max: 20}),
        body('price')
            .trim()
            .isInt({min: 0, max: 99999})
            .toInt(),
        body('imageUrl')
            .trim()
            .isURL(),
    ],
    async function (req, res) {
        const errors = validationResult(req);

        if (!errors.isEmpty()) {
            res.render('error', {
                title: 'Add Item',
                linkActive: 'management',
                errors: errors.array(),
            });
        } else {
            try {
                await db.query(
                    'INSERT INTO inventory (name, price, categoryid, imageurl) VALUES ($1, $2, $3, $4)',
                    [
                        req.body.name,
                        req.body.price,
                        req.body.categoryId,
                        req.body.imageUrl,
                    ],
                );
                res.redirect('/management');
            } catch (err) {
                res.render('error', {
                    title: 'Add Item',
                    linkActive: 'management',
                    errors: 'none',
                    errDB: err.message,
                });
            }
        }
    }
);


/*********************************************
 *  2. zadatak: Izmjena postojećeg proizvoda *
 *********************************************/

router.get('/updateitem', async function (req, res) {
    const [categories, items] = (await Promise.all([
        db.query('SELECT * FROM categories'),
        db.query('SELECT * FROM inventory'),
    ])).map(result => result.rows);

    res.render('updateItem', {
        title: 'Update Item',
        linkActive: 'management',
        categorySelect: {
            id: 'categoryId',
            name: 'categoryId',
            list: categories.map(category => ({
                name: category.name,
                value: category.id,
            })),
        },
        itemSelect: {
            id: 'itemId',
            name: 'itemId',
            list: items.map(item => ({
                name: item.name,
                value: item.id,
            })),
        },
    });
});

router.post(
    '/updateitem',
    [
        body('name')
            .trim()
            .isLength({min: 3, max: 20}),
        body('price')
            .trim()
            .isInt({min: 0, max: 99999})
            .toInt(),
        body('imageUrl')
            .trim()
            .isURL(),
    ],
    async function (req, res) {
        const errors = validationResult(req);

        if (!errors.isEmpty()) {
            res.render('error', {
                title: 'Update Item',
                linkActive: 'management',
                errors: errors.array(),
            });
        } else {
            try {
                await db.query(
                    'UPDATE inventory SET name = $1, price = $2, categoryid = $3, imageurl = $4 WHERE id = $5',
                    [
                        req.body.name,
                        req.body.price,
                        req.body.categoryId,
                        req.body.imageUrl,
                        req.body.itemId,
                    ],
                );
                res.redirect('/management');
            } catch (err) {
                res.render('error', {
                    title: 'Update Item',
                    linkActive: 'management',
                    errors: 'none',
                    errDB: err.message,
                });
            }
        }
    }
);


/*********************************************
 * 3. zadatak: Brisanje postojećeg proizvoda *
 *********************************************/

router.get('/deleteitem', async function (req, res) {
    res.render('deleteItem', {
        title: 'Delete Item',
        linkActive: 'management',
        items: (await db.query('SELECT * FROM inventory ORDER BY id')).rows,
    });
});

router.post(
    '/deleteitem',
    [
        body('itemId')
            .toInt()
            .custom(async id => {
                const items = (await db.query('SELECT * FROM inventory')).rows;
                const item = items.find(item => (item.id === id));

                if (item === undefined) {
                    return Promise.reject();
                }
                return Promise.resolve();
            }),
    ],
    async function (req, res) {
        const errors = validationResult(req);

        console.log(errors);

        if (!errors.isEmpty()) {
            res.render('error', {
                title: 'Delete Item',
                linkActive: 'management',
                errors: errors.array(),
            });
        } else {
            try {
                await db.query('DELETE FROM inventory WHERE id = $1', [req.body.itemId]);
                res.redirect('/management');
            } catch (err) {
                res.render('error', {
                    title: 'Delete Item',
                    linkActive: 'management',
                    errors: 'none',
                    errDB: err.message,
                });
            }
        }
    }
);


/*********************************************
 *   4. zadatak: Dodavanje nove kategorije   *
 *********************************************/

router.get('/addcategory', async function (req, res) {
    res.render('addCategory', {
        title: 'Add Category',
        linkActive: 'management',
    });
});

router.post(
    '/addcategory',
    [
        body('name')
            .trim()
            .isLength({min: 3, max: 18}),
        body('description')
            .trim()
            .isLength({min: 5, max: 35}),
        body('seasonal')
            .isIn(['No', 'Yes']),
    ],
    async function (req, res) {
        const errors = validationResult(req);

        if (!errors.isEmpty()) {
            res.render('error', {
                title: 'Add Category',
                linkActive: 'management',
                errors: errors.array(),
            });
        } else {
            try {
                await db.query(
                    'INSERT INTO categories (name, description, seasonal) VALUES ($1, $2, $3)',
                    [
                        req.body.name,
                        req.body.description,
                        req.body.seasonal,
                    ],
                );
                res.redirect('/management');
            } catch (err) {
                res.render('error', {
                    title: 'Add Category',
                    linkActive: 'management',
                    errors: 'none',
                    errDB: err.message,
                });
            }
        }
    }
);


/*********************************************
 *  5. zadatak: Izmjena postojeće kategorije *
 *********************************************/

router.get('/updatecategory', async function (req, res) {
    const categories = (await db.query('SELECT * FROM categories ORDER BY id')).rows;

    res.render('updateCategory', {
        title: 'Update Category',
        linkActive: 'management',
        categorySelect: {
            id: 'categoryId',
            name: 'categoryId',
            list: categories.map(category => ({
                name: category.name,
                value: category.id,
            })),
        },
    });
});

router.post(
    '/updatecategory',
    [
        body('name')
            .trim()
            .isLength({min: 3, max: 18}),
        body('description')
            .trim()
            .isLength({min: 5, max: 35}),
        body('seasonal')
            .isIn(['No', 'Yes']),
    ],
    async function (req, res) {
        const errors = validationResult(req);

        if (!errors.isEmpty()) {
            res.render('error', {
                title: 'Update Category',
                linkActive: 'management',
                errors: errors.array(),
            });
        } else {
            try {
                await db.query(
                    'UPDATE categories SET name = $1, description = $2, seasonal = $3 WHERE id = $4',
                    [
                        req.body.name,
                        req.body.description,
                        req.body.seasonal,
                        req.body.categoryId,
                    ],
                );
                res.redirect('/management');
            } catch (err) {
                res.render('error', {
                    title: 'Update Category',
                    linkActive: 'management',
                    errors: 'none',
                    errDB: err.message,
                });
            }
        }
    }
);


module.exports = router;
