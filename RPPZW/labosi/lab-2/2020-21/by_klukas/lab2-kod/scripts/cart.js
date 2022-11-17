let getData = function () {
    var cartTemplateHeader = document.querySelector("#cart-template-header");
    var cartTemplatItem = document.querySelector("#cart-template-item");
    var cartTemplate = cartTemplateHeader.content.cloneNode(true);
    var cart = document.querySelector(".cart");
    cart.appendChild(cartTemplate);

    var basket = localStorage.getItem("basket");

    if (basket) {
        basket = JSON.parse(basket)
        for (el in basket) {
            var item = basket[el];
            if (item["count"] > 0) {
                var cartItem = cartTemplatItem.content.cloneNode(true)
                cartItem.querySelector(".cart-item-title").innerHTML = item["name"];
                cartItem.querySelector(".cart-item-price").innerHTML = item["price"] + " kn";
                cartItem.querySelector(".cart-item-quantity").value = item["count"];
                cartItem.querySelector(".cart-item-total-price").innerHTML = item["count"] * item["price"] + " kn";
                
                totalPrice += item["count"] * item["price"];

                cart.appendChild(cartItem);
            }
        }
    }

    var total = document.querySelector("#cart-total-template").content.cloneNode(true);
    if (localStorage.getItem("count")) {
        total.querySelector(".cart-total > div").innerHTML = "Total: " + totalPrice;
    } else {
        total.innerHTML = "Total: 0";
    }

    cart.appendChild(total);

}

var totalPrice = 0;

getData();