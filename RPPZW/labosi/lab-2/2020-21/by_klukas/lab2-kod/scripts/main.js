let getData = async function () {
    let response = await fetch("https://web1lab2.azurewebsites.net/categories");
    let data = await response.json();
    addCategories(data);
}

let addCategories = async function (categories) {
    let main = document.querySelector('main');
    let categoryTemplate = document.querySelector('#category-template');
    let productTemplate = document.querySelector('#product-template');

    for (let index = 0; index < categories.length; index++) {
        let category = categoryTemplate.content.cloneNode(true);
        let categoryTitleElement = category.querySelector('.decorated-title > span');
        categoryTitleElement.textContent = categories[index].name;

        let path = `https://web1lab2.azurewebsites.net/products?categoryId=${categories[index].id}`;
        let categoryContent = await fetch(path);
        let categoryContentData = await categoryContent.json();

        let categoryGallery = category.querySelector(".gallery");

        if (categoryContentData.length > 0) {
            for (el of categoryContentData) {
                let product = productTemplate.content.cloneNode(true);

                let id = el.id
                id = id.toString()
                if (!basket[id]) {
                    let newProduct = basket[id] = {};
                    newProduct["count"] = 0;
                    newProduct["price"] = el.price;
                    newProduct["name"] = el.name;
                    newProduct["categoryId"] = el.categoryId;
                    newProduct["imageUrl"] = el.imageUrl;
                }
                
                product.querySelector(".photo-box-image").src = el.imageUrl;
                product.querySelector(".photo-box-title").innerHTML = el.name;
                product.querySelector(".photo-box").setAttribute("data-id", el.id);
                product.querySelector(".cart-btn").addEventListener("click", (event) => {
                    let id = event.target.parentNode.getAttribute("data-id");
                    basket[id]["count"] = basket[id]["count"] + 1;
                    updateCart();
                });

                categoryGallery.appendChild(product);
            }

            main.appendChild(category);

        }
        
    }

};

function updateCart() {
    count++;
    let cartItems = document.querySelector('#cart-items');
    cartItems.innerHTML = count;
    localStorage.setItem("basket", JSON.stringify(basket));
    localStorage.setItem("count", JSON.stringify(count));
};

if (localStorage.getItem("basket") && localStorage.getItem("count")) {
    var basket = JSON.parse(localStorage.getItem("basket"));
    var count = JSON.parse(localStorage.getItem("count"));
}
else {
    var basket = {};
    var count = 0;
    localStorage.setItem("basket", JSON.stringify(basket));
    localStorage.setItem("count", JSON.stringify(count));
}

document.querySelector('#cart-items').innerHTML = JSON.parse(localStorage.getItem("count"));
getData();
