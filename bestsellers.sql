SET GLOBAL event_scheduler=1;
USE PROGETTO_DB;
CREATE EVENT BestSellersCreation
ON SCHEDULE EVERY '1' MONTH
STARTS '2022-06-30 23:59:00'
DO
	DROP TABLE IF EXISTS BestSellers;
	CREATE TABLE BestSellers SELECT CodLibro, NumeroVendite
	FROM VenditeMensili
	ORDER BY NumeroVendite DESC
	LIMIT 10;
