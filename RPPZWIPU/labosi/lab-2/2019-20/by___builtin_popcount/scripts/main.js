let getCart = function () {
    let cart = localStorage.getItem("cart");

    if (cart === null) {
        // Ako u lokalnoj pohrani nema košarice, vraća prazan objekt
        return {};
    } else {
        return JSON.parse(cart);
    }
};

let setCart = function (cart) {
    // Uklanja sve proizvode čija je količina 0
    for (let productId in cart) {
        if (cart[productId] === 0) {
            delete cart[productId];
        }
    }

    localStorage.setItem("cart", JSON.stringify(cart));

    updateCartDisplay();
};

let updateCartDisplay = function () {
    let cartItemsElement = document.querySelector("#cart-items");
    let cart = getCart();

    cartItemsElement.textContent = Object.keys(cart).length;
};

updateCartDisplay();