WITH RECURSIVE zaposlenici(staff_id, lname, fname, zaposlenik)
AS
(
    SELECT staff_id, last_name, first_name, staff_id
    FROM staff
    UNION
    SELECT zaposlenici.staff_id, lname, fname, staff.staff_id
    FROM zaposlenici, staff
    WHERE zaposlenik = sup_staff_id
)
SELECT 
	zaposlenici.staff_id, 
    lname, 
    fname, 
	COUNT(DISTINCT title) AS cntDistFilm
FROM zaposlenici, rental, inventory, film
WHERE zaposlenik = rental.staff_id
AND inventory.inventory_id = rental.inventory_id
AND inventory.film_id = film.film_id
GROUP BY zaposlenici.staff_id, lname, fname
ORDER BY staff_id