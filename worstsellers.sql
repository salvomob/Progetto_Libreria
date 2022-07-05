SET GLOBAL event_scheduler=1;
USE PROGETTO_DB;
CREATE EVENT WorstSellersCreation
ON SCHEDULE EVERY '1' MONTH
STARTS '2022-07-05 11:00:00'
DO
	DROP TABLE IF EXISTS WorstSellers;
	CREATE TABLE WorstSellers SELECT CodLibro, count(*) AS NumeroVendite
	FROM Vendite
	GROUP BY CodLibro
	ORDER BY count(*) ASC
	LIMIT 10;	
