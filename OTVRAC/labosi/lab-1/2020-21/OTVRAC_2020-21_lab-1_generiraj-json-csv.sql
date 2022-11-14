/*
1. labos iz OR
za skup podataka treba generirati .json i .csv fileove direktno iz baze
to se može napraviti na bezbroj načina
ovo je primjer pomoću SQL upita
*/

COPY (
    SELECT array_to_json(array_agg(row_to_json(t))) FROM (
        SELECT 
            podaci.atr_1, 
            podaci.atr_2, 
            podaci.atr_3,

            COALESCE(json_agg(
                        json_build_object(
                            'podatr_slozen_1', povezani_podaci.podatr_slozen_1, 
                            'atr_slozen_2', podaci2.atr_slozen_2)) 
                        FILTER (WHERE povezani_podaci.podatr_slozen_1 IS NOT NULL), '[]') 
                    AS atr_slozen,

            podaci.atr_4, 
            podaci.atr_5,
            podaci.atr_6, 
            podaci.atr_7, 
            podaci.atr_8, 
            podaci.atr_9, 
            podaci.wikipedia_handle

        FROM podaci LEFT JOIN povezani_podaci NATURAL JOIN podaci2
        ON podaci.atr_2 = povezani_podaci.atr_2
        GROUP BY podaci.atr_2
        ) t ) 

TO 'C://temp/podaci.txt' --kasnije preimenuj u podaci.json

-----------------------------------------------------------------------------------

COPY (
    SELECT 
        podaci.atr_1, 
        podaci.atr_2, 
        podaci.atr_3, 

		string_agg(povezani_podaci.podatr_slozen_1 || '-' || podaci2.atr_1, ';') as atr_slozen,

		podaci.atr_4, 
        podaci.atr_5,
		podaci.atr_6, 
        podaci.atr_7, 
        podaci.atr_8, 
		podaci.atr_9, 
        podaci.wikipedia_handle
        
    FROM podaci LEFT JOIN povezani_podaci NATURAL JOIN podaci2
	ON podaci.atr_2 = povezani_podaci.atr_2
    GROUP BY podaci.atr_2) 
	
TO 'C://temp/podaci.csv' with DELIMITER ',' CSV HEADER;