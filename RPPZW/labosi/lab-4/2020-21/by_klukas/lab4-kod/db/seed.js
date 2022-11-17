const {
    Pool
} = require('pg');

const pool = new Pool({
    user: 'postgres',
    host: 'localhost',
    database: 'web-lab4',
    password: 'bazepodataka',
    port: 5432,
});


const sql_create_categories = `CREATE TABLE categories (
    id int GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    name text NOT NULL UNIQUE,
    description text NOT NULL,
    seasonal text NOT NULL
)`;

const sql_create_category_id_index = `CREATE UNIQUE INDEX idx_categoryId ON categories(id)`;


const sql_create_inventory = `CREATE TABLE inventory (
    id int GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    name text NOT NULL UNIQUE,
    price numeric NOT NULL,
    categoryId int REFERENCES categories(id),
    imageUrl text NOT NULL
)`;

const sql_create_inventory_id_index = `CREATE UNIQUE INDEX idx_inventoryId ON inventory(id)`;
const sql_create_inventory_category_index = `CREATE INDEX idx_inventoryCategory ON inventory(categoryId)`;


const sql_create_users = `CREATE TABLE users (
    id int GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    user_name text NOT NULL UNIQUE,
    first_name text NOT NULL,
    last_name text NOT NULL,
    email text NOT NULL,
    password text NOT NULL,
    role text
)`;

const sql_create_users_id_index = `CREATE UNIQUE INDEX idx_usersId ON users(id)`;
const sql_create_users_name_index = `CREATE UNIQUE INDEX idx_usersName ON users(user_name)`;


const sql_create_address = `CREATE TABLE address (
    id int GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    user_id int REFERENCES users(id),
    name text NOT NULL,
    street text NOT NULL,
    code text NOT NULL,
    town text NOT NULL,
    country text NOT NULL
)`;

const sql_create_address_user_index = `CREATE UNIQUE INDEX idx_addressUser ON address(id, user_id)`;


const sql_create_cart = `CREATE TABLE cart (
    user_id int REFERENCES users(id),
    inventory_id int REFERENCES inventory(id),
    items int NOT NULL,
    PRIMARY KEY (user_id, inventory_id)
)`;

const sql_create_cart_user_id_index = `CREATE INDEX idx_cartUserId ON cart(user_id)`;


const sql_create_order = `CREATE TABLE orders (
    id int GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    order_date date NOT NULL,
    user_id int REFERENCES users(id),
    address json NOT NULL,
    cart json NOT NULL
)`;

const sql_create_order_user_index = `CREATE INDEX idx_orderUserId ON orders(user_id)`;


const sql_create_history = `CREATE TABLE history (
    id int GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    user_id int REFERENCES users(id),
    inventory_id int REFERENCES inventory(id),
    history_date date NOT NULL
)`;

const sql_create_history_index = `CREATE INDEX idx_historyUser ON history(user_id)`;


const sql_create_sessions = `CREATE TABLE session (
    sid varchar NOT NULL COLLATE "default",
    sess json NOT NULL,
    expire timestamp(6) NOT NULL
  )
  WITH (OIDS=FALSE);`

const sql_create_session_index1 = `ALTER TABLE session ADD CONSTRAINT session_pkey PRIMARY KEY (sid) NOT DEFERRABLE INITIALLY IMMEDIATE`
const sql_create_session_index2 = `CREATE INDEX IDX_session_expire ON session(expire)`

const sql_insert_inventory = `INSERT INTO inventory (
    name, price, categoryId, imageUrl)
    VALUES 
    ('Tulip', 10, 1, 'https://i.imgur.com/Ttir6mp.jpg'),
    ('Lavender', 15, 1, 'https://i.imgur.com/gH33WyT.jpg'),
    ('Fuchsia', 50, 1, 'https://i.imgur.com/s27QJBL.jpg'),
    ('Daisy', 30, 1, 'https://i.imgur.com/Agarl4v.jpg'),
    ('Orchid', 90, 2, 'https://i.imgur.com/Dx4q8uE.jpg'),
    ('Fittonia', 80, 2, 'https://i.imgur.com/G9JfR3S.jpg'),
    ('Showel', 150, 3, 'https://i.imgur.com/BcjgzeT.jpg'),
    ('Small showel', 50, 3, 'https://i.imgur.com/L80eL1e.jpg'),
    ('Rake', 100, 3, 'https://i.imgur.com/I5ctUan.jpg'),
    ('Tulip (1 kg)', 200, 4, 'https://i.imgur.com/WUYYzBG.jpg');
`;

const sql_insert_category = `INSERT INTO categories (name, description, seasonal) VALUES 
    ('Flowers', 'Flowers make us smile', 'Yes'),
    ('Indoor plants', 'Bring nature inside', 'No'),
    ('Tools', 'Every gardener needs good tools', 'No'),
    ('Seeds', 'Grow your own plants', 'No'),
    ('Pots', 'Many sizes and styles', 'No'),
    ('Fertilizers', 'Essential nutrients', 'No');
`;

const sql_insert_users = `INSERT INTO users (user_name, first_name, last_name, email, password, role) VALUES ('admin', 'Adminko', 'Administratović', 'null@admin', 'admin', 'admin')`

const sql_insert_address = `INSERT INTO address (user_id, name, street, code, town, country) VALUES (1, 'Dragi Admin', 'Za konzolom b.b.', '42', 'Igdje', 'Globalija')`

let table_names = [
    "categories",
    "inventory",
    "users",
    "address",
    "cart",
    "order",
    "history",
    "sessions"
]

let tables = [
    sql_create_categories,
    sql_create_inventory,
    sql_create_users,
    sql_create_address,
    sql_create_cart,
    sql_create_order,
    sql_create_history,
    sql_create_sessions
];

let table_data = [
    sql_insert_category,
    sql_insert_inventory,
    sql_insert_users,
    sql_insert_address,
    undefined,
    undefined,
    undefined,
    undefined
]

let indexes = [
    sql_create_category_id_index,
    sql_create_inventory_id_index,
    sql_create_inventory_category_index,
    sql_create_users_id_index,
    sql_create_order_user_index,
    sql_create_history_index,
    sql_create_session_index1,
    sql_create_session_index2
];

if ((tables.length != table_data.length) || (tables.length != table_names.length)) {
    console.log("tables, names and data arrays length mismatch.")
    return
}

//create tables and populate with data (if provided) 

(async () => {
    console.log("Creating and populating tables");
    for (let i = 0; i < tables.length; i++) {
        console.log("Creating table " + table_names[i] + ".");
        try {
            await pool.query(tables[i], [])
            console.log("Table " + table_names[i] + " created.");
            if (table_data[i] !== undefined) {
                try {
                    await pool.query(table_data[i], [])
                    console.log("Table " + table_names[i] + " populated with data.");
                } catch (err) {
                    console.log("Error populating table " + table_names[i] + " with data.")
                    return console.log(err.message);
                }
            }
        } catch (err) {
            console.log("Error creating table " + table_names[i])
            return console.log(err.message);
        }
    }

    console.log("Creating indexes");
    for (let i = 0; i < indexes.length; i++) {
        try {
            await pool.query(indexes[i], [])
            console.log("Index " + i + " created.")
        } catch (err) {
            console.log("Error creating index " + i + ".")
        }
    }
})()
