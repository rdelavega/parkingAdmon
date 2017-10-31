-- 1. Estacionamientos	mas	visitados.

SELECT address AS parked
FROM p1_parking
LEFT JOIN p1_park USING(id_parking)
GROUP BY address
HAVING count(id_parking) =
  (SELECT count(id_parking) AS parked
   FROM p1_park
   GROUP BY id_parking
   ORDER BY parked DESC
   LIMIT 1)
ORDER BY parked DESC;

-- 2. Personas	que	mas	estacionamientos	visitan

SELECT concat(l_name,' ',l_name2,', ',name) AS nombre
FROM p1_park
LEFT JOIN p1_vehicle USING(record)
LEFT JOIN p1_users USING(id_user)
GROUP BY id_user
HAVING count(DISTINCT id_parking) =
  (SELECT count(DISTINCT id_parking)
   FROM p1_park
   LEFT JOIN p1_vehicle USING(record)
   LEFT JOIN p1_users USING(id_user)
   GROUP BY id_user
   ORDER BY count(DISTINCT id_parking) DESC
   LIMIT 1);

-- 3. Lista	de	todos	los	estacionamientos	disponibles	en	una	zona	determinada

SELECT address
FROM p1_parking
LEFT JOIN p1_sector USING(id_sector)
LEFT JOIN p1_park USING(id_parking)
WHERE exitof IS NULL
  AND id_sector = %d
GROUP BY id_parking
HAVING count(id_park) < avg(sizeof);

-- 4. Lista	de	todos	los	usuarios	que	estan	registrados	en	el	sistema	de	estacionamientos

SELECT concat(l_name,' ',l_name2,', ',name) AS nombre
FROM p1_users
ORDER BY l_name;

-- 5. Lista	de	los	horarios	de	un	estacionamiento	en	particular

SELECT DAY,
       startof,
       endof
FROM p1_schedule
LEFT JOIN p1_parking USING(id_parking)
WHERE id_parking = %d
ORDER BY DAY;

--6. Lista	de	las	colonias	a	las	que	mas	llegan	los	visitantes.

SELECT name
FROM p1_park
LEFT JOIN p1_parking USING(id_parking)
LEFT JOIN p1_sector USING(id_sector)
GROUP BY id_sector
HAVING count(id_park) =
  (SELECT count(id_park)
   FROM p1_park
   LEFT JOIN p1_parking USING(id_parking)
   GROUP BY id_sector
   ORDER BY count(id_park) DESC
   LIMIT 1);

-- 7. Hora	en	la	que	mas	hay	gente	en	un	estacionamiento	o	zona	determinada.
-- Estacionamiento

SELECT hour(entryof)
FROM p1_park
LEFT JOIN p1_parking USING(id_parking)
WHERE id_parking = %d
GROUP BY hour(entryof)
HAVING count(id_park) =
  (SELECT count(id_park)
   FROM p1_park
   LEFT JOIN p1_parking USING(id_parking)
   WHERE id_parking = %d
   GROUP BY hour(entryof)
   ORDER BY count(id_park) DESC
   LIMIT 1);

-- Zona

SELECT hour(entryof)
FROM p1_park
LEFT JOIN p1_parking USING(id_parking)
LEFT JOIN p1_sector USING(id_sector)
WHERE id_sector = %d
GROUP BY hour(entryof)
HAVING count(id_park) =
  (SELECT count(id_park)
   FROM p1_park
   LEFT JOIN p1_parking USING(id_parking)
   LEFT JOIN p1_sector USING(id_sector)
   WHERE id_sector = %d
   GROUP BY hour(entryof)
   ORDER BY count(id_park) DESC
   LIMIT 1);

-- 8. Numero	de	lugares	disponibles	en	un	estacionamiento	determinado.

DROP FUNCTION IF EXISTS p1_resta;


DELIMITER $
CREATE FUNCTION p1_resta (x INT, y INT) RETURNS INT BEGIN DECLARE res INT;
SET res = x - y; RETURN res; END$
DELIMITER ;


SELECT p1_resta(sizeof,count(id_park)) AS disponibles
FROM p1_parking
LEFT JOIN p1_park USING(id_parking)
WHERE id_parking = %d
  AND exitof IS NULL
GROUP BY id_parking
HAVING count(id_park) < avg(sizeof);

-- 9. Tipo	de	lugares	 (parquimetro	o	estacionamiento)	que	una	persona	en	particular	ha	usado	dentro
-- de	un	periodo	de	tiempo	especifico

SELECT record,
       date(entryof),
       tp.typeof
FROM p1_park
LEFT JOIN p1_vehicle USING(record)
LEFT JOIN p1_users USING(id_user)
LEFT JOIN p1_parking USING(id_parking)
LEFT JOIN p1_type AS tp USING(id_type)
WHERE id_user = 5
  AND date(entryof) >= '2017-06-27'
  AND date(entryof) <= '2017-08-02'
ORDER BY date(entryof);

-- 10. Monto	 total	 que	 ha	 gastado	 una	 persona	 en	 particular	 en	 estacionamientos	 en	 un	 periodo	 de
-- tiempo	en	particular,	desglosado	por	parquimetros	y	estacionamientos	publicos

DROP FUNCTION IF EXISTS p1_rate;


DELIMITER $
CREATE FUNCTION p1_rate (x INT, y FLOAT) RETURNS FLOAT BEGIN DECLARE res FLOAT;
SET res = (x/60)*y; RETURN res; END$
DELIMITER ;


SELECT ty.typeof,
       sum(p1_rate(timestampdiff(MINUTE,entryof,exitof),rate)) AS total
FROM p1_park
LEFT JOIN p1_vehicle USING(record)
LEFT JOIN p1_users USING(id_user)
LEFT JOIN p1_parking AS prki USING(id_parking)
LEFT JOIN p1_type AS ty USING(id_type)
WHERE exitof IS NOT NULL
  AND id_user = 4
  AND date(entryof) >= '2017-02-01'
  AND date(entryof) <= '2017-02-02'
GROUP BY id_type;
