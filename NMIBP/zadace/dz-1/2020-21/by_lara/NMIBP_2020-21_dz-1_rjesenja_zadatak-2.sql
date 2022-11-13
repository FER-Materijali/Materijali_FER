WITH RECURSIVE zaposlenici 
AS (
	(
	SELECT st.staff_id, st.sup_staff_id, st.last_name, st.first_name, st.address_id, pay.amount as amount
	FROM staff st, rental rent, payment pay
	WHERE st.staff_id = rent.staff_id	 
	AND pay.rental_id = rent.rental_id
	)
	UNION ALL
	(
	SELECT st.staff_id, st.sup_staff_id, st.last_name, st.first_name, st.address_id, zap.amount
	FROM staff st, zaposlenici zap 
    WHERE st.staff_id = zap.sup_staff_id
	)
)



SELECT 
    rank() over (ORDER BY sum(zaposlenici.amount) desc) as rankCompany, 
    rank() over (PARTITION BY country ORDER BY sum(zaposlenici.amount) DESC) AS rankCountry,
    country, 
    zaposlenici.staff_id, zaposlenici.last_name, zaposlenici.first_name, 
    SUM(zaposlenici.amount) AS totAmnt
FROM country, city, address, zaposlenici 
WHERE country.country_id = city.country_id
AND city.city_id = address.city_id 
AND zaposlenici.address_id = address.address_id
GROUP BY country, zaposlenici.staff_id, zaposlenici.last_name, zaposlenici.first_name
ORDER BY rankCompany, rankCountry