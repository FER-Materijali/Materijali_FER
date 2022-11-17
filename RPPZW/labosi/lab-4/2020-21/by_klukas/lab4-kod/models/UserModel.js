const db = require('../db')

//razred User enkapsulira korisnika web trgovine
module.exports = class User {
    
    //konstruktor korisnika
    constructor(username, first_name, last_name, email, password, role="user") {
        this.id = undefined
        this.user_name = username
        this.first_name = first_name
        this.last_name = last_name
        this.email = email
        this.password = password
        this.role = role
    }

    //dohvat korisnika na osnovu korisničkog imena
    static async fetchByUsername(username) {

        let results = await dbGetUserByName(username)
        let newUser = new User()

        if( results.length > 0 ) {
            newUser = new User(results[0].user_name, results[0].first_name, 
                results[0].last_name, results[0].email, results[0].password, results[0].role)
            newUser.id = results[0].id
        }
        return newUser
    }

    //dohvat korisnika na osnovu email adrese
    static async fetchByEmail(email) {

        let results = await dbGetUserByEmail(email)
        let newUser = new User()

        if( results.length > 0 ) {
            newUser = new User(results[0].user_name, results[0].first_name, 
                results[0].last_name, results[0].email, results[0].password, results[0].role)
            newUser.id = results[0].id
        }
        return newUser
    }

    //dohvat korisnika na osnovu id korisnika (tablica users)
    static async fetchByUserId(id) {
       
        let results = await dbGetUserById(id)
        let newUser = new User()

        if( results.length > 0 ) {
            newUser = new User(results[0].user_name, results[0].first_name, 
                results[0].last_name, results[0].email, results[0].password, results[0].role)
            newUser.id = results[0].id
        }
        return newUser
    }

    //da li je korisnik pohranjen u bazu podataka?
    isPersisted() {
        return this.id !== undefined
    }

    //provjera zaporke
    checkPassword(password) {
        return this.password ? this.password == password : false
    }

    //pohrana korisnika u bazu podataka
    async persist() {
        try {
            let userID = await dbNewUser(this)
            this.id = userID
        } catch(err) {
            console.log("ERROR persisting user data: " + JSON.stringify(this))
            throw err
        }
    }

}

//dohvat korisnika iz baze podataka na osnovu korisničkog imena (stupac user_name)
dbGetUserByName = async (user_name) => {
    const sql = `SELECT id, user_name, first_name, last_name, email, password, role
    FROM users WHERE user_name = '` + user_name + `'`;
    try {
        const result = await db.query(sql, []);
        return result.rows;
    } catch (err) {
        console.log(err);
        throw err
    }
};

//dohvat korisnika iz baze podataka na osnovu email adrese (stupac email)
dbGetUserByEmail = async (user_email) => {
    const sql = `SELECT id, user_name, first_name, last_name, email, password, role
    FROM users WHERE email = '` + user_email + `'`;
    try {
        const result = await db.query(sql, []);
        return result.rows;
    } catch (err) {
        console.log(err);
        throw err
    }
};

//dohvat korisnika iz baze podataka na osnovu id korisnika (stupac id)
dbGetUserById = async (user_id) => {
    const sql = `SELECT id, user_name, first_name, last_name, email, password, role
    FROM users WHERE id = ` + user_id;
    try {
        const result = await db.query(sql, []);
        return result.rows;
    } catch (err) {
        console.log(err);
        throw err
    }
}

//umetanje zapisa o korisniku u bazu podataka
dbNewUser = async (user) => {
    const sql = "INSERT INTO users (user_name, first_name, last_name, email, password, role) VALUES ('" +
        user.user_name + "', '" + user.first_name + "', '" + user.last_name + "', '" + 
        user.email + "', '" + user.password + "', '" + user.role + "') RETURNING id";
    try {
        const result = await db.query(sql, []);
        return result.rows[0].id;
    } catch (err) {
        console.log(err);
        throw err
    }
}
