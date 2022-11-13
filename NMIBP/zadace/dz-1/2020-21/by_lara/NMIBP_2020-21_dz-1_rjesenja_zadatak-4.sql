CREATE TEMP TABLE kvartal
(rbrKvartal int);
INSERT INTO kvartal VALUES ( 1), ( 2), ( 3), ( 4);

SELECT *
FROM crosstab (
'SELECT DISTINCT title,
    CASE
        WHEN EXTRACT(MONTH FROM payment_date) IN (1,2,3) THEN 1
        WHEN EXTRACT(MONTH FROM payment_date) IN (4,5,6) THEN 2
        WHEN EXTRACT(MONTH FROM payment_date) IN (7,8,9) THEN 3
        WHEN EXTRACT(MONTH FROM payment_date) IN (10,11,12) THEN 4
    END as rbrKvartal,

    SUM (amount) OVER
    (PARTITION BY title,  
    CASE
        WHEN EXTRACT(MONTH FROM payment_date) IN (1,2,3) THEN 1
        WHEN EXTRACT(MONTH FROM payment_date) IN (4,5,6) THEN 2
        WHEN EXTRACT(MONTH FROM payment_date) IN (7,8,9) THEN 3
        WHEN EXTRACT(MONTH FROM payment_date) IN (10,11,12) THEN 4
    END)
FROM payment, rental, inventory, film
WHERE payment.rental_id = rental.rental_id
AND rental.inventory_id = inventory.inventory_id
AND inventory.film_id = film.film_id
AND fulltext @@ to_tsquery(''english'', ''fanci | amus'')
GROUP BY title, payment_date, amount
ORDER BY title
',
'SELECT rbrKvartal FROM kvartal ORDER BY rbrKvartal')
AS pivotTable (filmTitle varchar, q1 numeric(10,2), q2 numeric(10,2), q3 numeric(10,2), q4 numeric(10,2))