SELECT details.*,
    rank() OVER 
        (PARTITION BY details.year ORDER BY details.numRentalsYear DESC) AS rank
FROM (
    SELECT DISTINCT
    EXTRACT(YEAR FROM rental.return_date) AS year, 
    title,
    COUNT(inventory.film_id) OVER 
        (PARTITION BY inventory.film_id, EXTRACT(YEAR FROM rental.return_date)) AS numRentalsYear
    FROM rental, inventory, film
    WHERE rental.inventory_id = inventory.inventory_id
    AND inventory.film_id = film.film_id
    AND EXTRACT(YEAR FROM rental.return_date) IS NOT NULL
    GROUP BY rental.return_date, title, inventory.film_id
) details
ORDER BY year,rank, title