SET GLOBAL event_scheduler=1;
USE PROGETTO_DB;
CREATE EVENT BestSellersCreation
ON SCHEDULE EVERY '1' MONTH
STARTS '2022-07-05 11:00:00'
DO
	DROP TABLE IF EXISTS BestSellers;
	CREATE TABLE BestSellers SELECT CodLibro, count(*) AS NumeroVendite
	FROM Vendite
	GROUP BY CodLibro
	ORDER BY count(*) DESC
	LIMIT 10;
