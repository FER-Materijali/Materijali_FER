const db = require('../db')
//const User = require('../models/UserModel')
//const Address = require('../models/AddressModel')
//const Cart = require('../models/CartModel')

//razred Order enkapsulira zaključenu narudžbu korisnika
module.exports = class Order {
    
    //konstruktor narudžbe
    constructor(user, address, cart, date) {
        
        this.id = undefined                             //id narudžbe, dodjeljuje se tijekom pohrane u bazu podataka (tablica orders)
        this.date = date                                //datum narudžbe (timestamp), postavlja se kod stvaranja zapisa u db
        this.user_id = user.id                          //id korisnika u tablici users
        this.cart = JSON.stringify(cart)                //sadržaj narudžbe kao serijalizirani (JSON) sadržaj košarice
        this.address = JSON.stringify(address)          //adresa dostave kao serijalizirani objekt (JSON) adrese
    }

    //dohvat polja narudžbi, koje su povezane s danim korisnikom
    static async fetchByUser(user) {
       
        let results = await dbGetOrdersByUserId(user.id)
        let orders = []

        for(let result of results) {
            let neworder = new Order(user, result.address, result.cart, result.order_date)
            neworder.id = result.id
            orders.push(neworder) 
        }

        return orders
    }

    //da li je narudžba pohranjena u bazu podataka?
    isPersisted() {
        return this.id !== undefined
    }

    //pohrana narudžbe u bazu podataka
    async persist() {
        try {
            let orderID = await dbNewOrder(this)
            this.id = orderID
        } catch(err) {
            console.log("ERROR persisting order data: " + JSON.stringify(this))
            throw err
        }
    }
}

//dohvat narudžbi iz baze podataka, vezanih uz id korisnika (id iz tablice users)
dbGetOrdersByUserId = async (user_id) => {
    const sql = `SELECT id, order_date, user_id, address, cart
    FROM orders WHERE user_id = ` + user_id;
    try {
        const result = await db.query(sql, []);
        return result.rows;
    } catch (err) {
        console.log(err);
        throw err
    }
}

//umetanje zapisa o narudžbi u bazu podataka
dbNewOrder = async (order) => {
    const sql = "INSERT INTO orders (order_date, user_id, address, cart) VALUES (current_timestamp, '" +
        order.user_id + "', '" + order.address + "', '" + order.cart + "') RETURNING id";
    try {
        const result = await db.query(sql, []);
        return result.rows[0].id;
    } catch (err) {
        console.log(err);
        throw err
    }
}