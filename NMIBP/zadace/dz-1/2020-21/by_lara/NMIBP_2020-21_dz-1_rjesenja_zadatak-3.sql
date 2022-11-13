SELECT title, array_agg(DISTINCT city ORDER BY city)
FROM inventory, film, store, address, city
WHERE inventory.film_id = film.film_id
AND inventory.store_id = store.store_id
AND store.address_id = address.address_id
AND address.city_id = city.city_id
AND similarity(title, 'geldfingr') > 0.15
GROUP BY title
ORDER BY title
