const db = require('../db')

//stvori košaricu (stvara običan JavaScript objekt - ograničenje zbog
//načina pohrane podataka iz sjedničkog objekta u trajnu memoriju - polje tablice
//baze podataka - sjednički objekt se serijalizira u jedan JSON objekt !!!)
function createCart() {
    let newCart = {}
    newCart.totalAmount = 0
    newCart.items = {}

    return newCart
}

//osvježi ukupnu vrijednost košarice
function update(cart) {

    cart.totalAmount = 0
    for(let item of Object.values(cart.items)) 
        cart.totalAmount += item.price * item.quantity
}

//dodaj jedan ili više komada nekog artikla u košaricu
async function addItemToCart(cart, id, quantity) {
        
    //dohvati zapis artikla u košarici
    let itemObject = cart.items[id]
    
    //ako artikl ne postoji u košarici, stvori novi objet artikla
    if( itemObject === undefined ) {
        itemObject = {id: id, name: undefined, price: undefined, quantity: 0, imageurl: undefined}
        cart.items[id] = itemObject
    }
    
    //pokušaj dobaviti ime, cijenu i url slike artikla
    if(itemObject.price === undefined) {
        if( itemData = await getItemData(id) ) {
            itemObject.name = itemData.name
            itemObject.price = itemData.price
            itemObject.imageurl = itemData.image
        }
    }

    //povećaj brojnost artikla
    itemObject.quantity = itemObject.quantity + quantity

    //ažuriraj ukupnu cijenu košarice
    update(cart)
    
    //console.log("CART MODEL: addItem: " + JSON.stringify(cart))
}

//makni jedan ili više komada nekog artikla iz košarice
async function removeItemFromCart(cart, id, quantity) {

    //dohvati objekt artikla iz košarice
    let itemObject = cart.items[id]

    //ako artikl postoji u košarici
    if( itemObject ) {

        //smanji brojnost artikla u košarici
        let newQuantity = Math.max(0, itemObject.quantity - quantity)

        //ako je nova brojnost nula, izbaci ga iz košarice
        if( newQuantity )
            itemObject.quantity = newQuantity
        else
            delete cart.items[id]
    }

    //ažuriraj ukupnu cijenu košarice
    update(cart)
}

//dohvati podatke o artiklu iz baze podataka
async function getItemData(id) {
        
    const sql = `SELECT name, price, imageurl FROM inventory WHERE id = ` + id;
    try {
        const result = await db.query(sql, []);
        return {
            name: result.rows[0].name,
            price: result.rows[0].price, 
            image: result.rows[0].imageurl
        } 
    } catch (err) {
        console.log(err);
        throw err
    }
    return undefined
}

module.exports = {
    createCart,
    addItemToCart,
    removeItemFromCart
}