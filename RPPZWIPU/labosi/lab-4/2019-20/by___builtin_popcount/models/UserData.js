const fs = require('fs');

class UserData {

    constructor(filename) {
        this.filename = filename;
        this.users = {};
    }


    initialize(force) {

        let unparsed_data;
        try {
            unparsed_data = fs.readFileSync(this.filename);
        } catch (err) {
            console.log('ERROR loading user data registry: ' + err);
            if (force === true) {
                this.store();
                unparsed_data = '{}';
            } else
                throw err;
        }

        try {
            this.users = JSON.parse(unparsed_data);
        } catch (err) {
            console.log('ERROR parsing user data registry: ' + err);
            throw err;
        }
    }

    store() {
        try {
            fs.writeFileSync(this.filename, JSON.stringify(this.users));
        } catch (err) {
            console.log('ERROR saving user data registry: ' + err);
            throw err;
        }
    }


    getUser(username) {
        return this.users[username];
    }

    userExists(user) {
        return this.users[user] !== undefined;
    }

    //Napomena: samo username parametar je bitan, ostali ne moraju biti navedeni!
    createUser(username, password, email, force) {
        if (this.userExists(username) && !force)
            return undefined;

        let newUser = {username, password, role: 'user', email, created: Date.now(), preferences: {}};
        this.users[username] = newUser;
        return newUser;
    }
}

module.exports = UserData;