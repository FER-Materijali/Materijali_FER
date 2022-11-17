async function addItemToCart(id) {
    response = await fetch('/cart/add/' + id);
    if (!response.ok) {
        alert("Error adding the product to the cart");

    } else {
        location.reload();

    }
}

async function removeItemFromCart(id) {
    response = await fetch('/cart/remove/' + id);
    if (!response.ok) {
        alert("Error removing the product from the cart");

    } else {
        location.reload();
    }
}