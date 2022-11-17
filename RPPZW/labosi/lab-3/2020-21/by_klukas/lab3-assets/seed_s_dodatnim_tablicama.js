const {Pool} = require('pg');

const pool = new Pool({
    user: 'postgres',
    host: 'localhost',
    database: 'web1-lab3',
    password: '-',
    port: 5432,
});

const sql_create_inventory = `DROP TABLE IF EXISTS inventory;
    CREATE TABLE inventory (
    id int GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    name text NOT NULL UNIQUE,
    price numeric NOT NULL,
    categoryId int NOT NULL,
    imageUrl text NOT NULL,
    colors text NOT NULL
)`;

const sql_create_categories = `DROP TABLE IF EXISTS categories;
    CREATE TABLE categories (
    id int GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    name text NOT NULL UNIQUE,
    description text NOT NULL,
    seasonal text NOT NULL
)`;

const sql_insert_inventory = `INSERT INTO inventory (
    name, price, categoryId, imageUrl, colors)
    VALUES 
    ('Tulip', 10, 1, 'https://i.imgur.com/Ttir6mp.jpg', 'white, red, yellow'),
    ('Lavender', 15, 1, 'https://i.imgur.com/gH33WyT.jpg', 'blue'),
    ('Fuchsia', 50, 1, 'https://i.imgur.com/s27QJBL.jpg', 'red-purple, white-purple, white-pink'),
    ('Daisy', 30, 1, 'https://i.imgur.com/Agarl4v.jpg', 'white'),
    ('Orchid', 90, 2, 'https://i.imgur.com/Dx4q8uE.jpg', 'green, white, purple'),
    ('Fittonia', 80, 2, 'https://i.imgur.com/G9JfR3S.jpg', 'green, red'),
    ('Showel', 150, 3, 'https://i.imgur.com/BcjgzeT.jpg', 'metal'),
    ('Small showel', 50, 3, 'https://i.imgur.com/L80eL1e.jpg', 'metal'),
    ('Rake', 100, 3, 'https://i.imgur.com/I5ctUan.jpg', 'metal'),
    ('Tulip (1 kg)', 200, 4, 'https://i.imgur.com/WUYYzBG.jpg', 'white, red, yellow');
`;

const sql_insert_category = `INSERT INTO categories (name, description, seasonal) VALUES 
    ('Flowers', 'Flowers make us smile', 'Yes'),
    ('Indoor plants', 'Bring nature inside', 'No'),
    ('Tools', 'Every gardener needs good tools', 'No'),
    ('Seeds', 'Grow your own plants', 'No'),
    ('Pots', 'Many sizes and styles', 'No'),
    ('Fertilizers', 'Essential nutrients', 'No');
`;

const sql_create_experts = `DROP TABLE IF EXISTS experts;
    CREATE TABLE experts (
    id int GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    name text NOT NULL,
    surname text NOT NULL,
    email text NOT NULL,
    employedsince numeric NOT NULL,
    expertsince numeric NOT NULL,
    expertFor int NOT NULL
)`;

const sql_insert_experts = `INSERT INTO experts (name, surname, email, employedsince, expertsince, expertFor) VALUES 
    ('Filip', 'Tulipovski', 'filip.tulipovski@flowershop.fer.hr', 2012, 2015, 1),
    ('Ružica', 'Ružić', 'ruzica.ruzic@flowershop.fer.hr', 2002, 1999, 3),
    ('Ivančica', 'Cvjetić', 'ivancica.cvjetic@flowershop.fer.hr', 2009, 2010, 2),
    ('Sunčica', 'Horvat', 'suncica.horvat@flowershop.fer.hr', 2011, 2005, 5),
    ('Hrvoje', 'Hortenzijo', 'hrvoje.hortenzijo@flowershop.fer.hr', 1995, 1990, 7),
    ('Jagoda', 'Jagodić', 'jagoda.jagodic@flowershop.fer.hr', 2019, 2020, 8),
    ('Iris', 'Leptirić', 'iris.leptiric1989@flowershop.fer.hr', 2000, 2001, 2),
    ('Narcisa', 'Spring', 'narcisa.spring@flowershop.fer.hr', 1998, 2005, 5),
    ('Lily Rose', 'Žutić Zayan', 'lily-rose.zutic-zayan22@flower.shop.hr', 1997, 2005, 1);
`;

const sql_create_suppliers = `DROP TABLE IF EXISTS suppliers;
    CREATE TABLE suppliers (
    id int GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    name text NOT NULL,
    country text NOT NULL,
    county text NOT NULL,
    email text NOT NULL,
    supplierSince numeric NOT NULL,
    supplierFor int NOT NULL
)`;

const sql_insert_suppliers = `INSERT INTO suppliers (name, country, county, email, supplierSince, supplierFor) VALUES 
    ('Štihača d.o.o.', 'Croatia', 'Zagreb', 'stihaca@stihanje.hr', 2002, 7),
    ('Trn u oku, j.d.o.o', 'Croatia', 'Istria', 'trn@oko.hr', 2010, 1),
    ('Vesele vile, d.d.', 'Croatia', 'Karlovac', 'vesele@vile.hr', 2019, 10),
    ('Šareni vrt, d.o.o.', 'Croatia', 'Split-Dalmatia', 'sareni.vrt@boje.hr', 2011, 5),
    ('Cvjetić, j.d.o.o.', 'Croatia', 'Osijek-Baranja', 'cvjetic@cvjetic.hr', 2012, 7),
    ('Slatka Marelica, d.d.', 'Croatia', 'Varaždin', 'slatka@marelica.hr', 2020, 8);
`;

pool.query(sql_create_inventory, [], (err, result) => {
    if (err) {
        return console.error(err.message);
    }
    console.log("Successful creation of the 'inventory' table");
    pool.query(sql_insert_inventory, [], (err, result) => {
        if (err) {
            return console.error(err.message);
        }
    });
});

pool.query(sql_create_categories, [], (err, result) => {
    if (err) {
        return console.error(err.message);
    }
    console.log("Successful creation of the 'categories' table");
    pool.query(sql_insert_category, [], (err, result) => {
        if (err) {
            return console.error(err.message);
        }
    });
});

pool.query(sql_create_experts, [], (err, result) => {
    if (err) {
        return console.error(err.message);
    }
    console.log("Successful creation of the 'experts' table");
    pool.query(sql_insert_experts, [], (err, result) => {
        if (err) {
            return console.error(err.message);
        }
    });
});

pool.query(sql_create_suppliers, [], (err, result) => {
    if (err) {
        return console.error(err.message);
    }
    console.log("Successful creation of the 'suppliers' table");
    pool.query(sql_insert_suppliers, [], (err, result) => {
        if (err) {
            return console.error(err.message);
        }
    });
});