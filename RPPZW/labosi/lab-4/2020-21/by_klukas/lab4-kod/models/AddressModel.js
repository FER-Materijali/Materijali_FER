const db = require('../db')

//razred Address enkapsulira adresu korisnika web trgovine
//jedan korisnik može imati 1..n adresa
module.exports = class Address {
    
    //konstruktor adrese
    constructor(user, name, street, code, town, country) {
        this.id = undefined
        this.user_id = user.id
        this.name = name
        this.street = street
        this.code = code
        this.town = town
        this.country = country
    }

    //dohvat polja adresa iz baze podataka, vezanih uz navedenog korisnika
    static async fetchByUser(user) {
       
        let results = await dbGetAddressByUserId(user.id)
        let addresses = []

        for(let result of results) {
            let newaddr = new Address(user, result.name, result.street, result.code, result.town, result.country)
            newaddr.id = result.id
            addresses.push(newaddr) 
        }
        return addresses
    }

    //da li je adrese pohranjena u bazu podataka?
    isPersisted() {
        return this.id !== undefined
    }

    //pohrana adrese u bazu podataka
    async persist() {
        try {
            let addrID = await dbNewAddress(this)
            this.id = addrID
        } catch(err) {
            console.log("ERROR persisting address data: " + JSON.stringify(this))
            throw err
        }
    }
}

//dohvat adresa iz baze podataka, vezanih uz id korisnika (id iz tablice users)
dbGetAddressByUserId = async (user_id) => {
    const sql = `SELECT id, user_id, name, street, code, town, country
    FROM address WHERE user_id = ` + user_id;
    try {
        const result = await db.query(sql, []);
        return result.rows;
    } catch (err) {
        console.log(err);
        throw err
    }
}

//umetanje zapisa o adresi u bazu podataka
dbNewAddress = async (addr) => {
    const sql = "INSERT INTO address (user_id, name, street, code, town, country) VALUES ('" +
        addr.user_id + "', '" + addr.name + "', '" + addr.street + "', '" + 
        addr.code + "', '" + addr.town + "', '" + addr.country + "') RETURNING id";
    try {
        const result = await db.query(sql, []);
        return result.rows[0].id;
    } catch (err) {
        console.log(err);
        throw err
    }
}
