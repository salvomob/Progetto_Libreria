SET GLOBAL event_scheduler=1;
USE PROGETTO_DB;
CREATE EVENT WorstSellersCreation
ON SCHEDULE EVERY '1' MONTH
STARTS '2022-07-05 11:00:00'
DO
	select 'ciao';
	DROP TABLE IF EXISTS WorstSellers;
	DROP TABLE IF EXISTS VenditeMensili;
	CREATE TABLE VenditeMensili(
		CodLibro int,
		NumeroVendite int DEFAULT 0
	)ENGINE=INNODB DEFAULT charset=utf8;
	INSERT INTO VenditeMensili(CodLibro) SELECT DISTINCT CodLibro FROM Libri;
	UPDATE VenditeMensili vm,Vendite v
	SET vm.NumeroVendite = vm.NumeroVendite + 1
	WHERE MONTH(Data) = MONTH(CURRENT_DATE())
	AND YEAR(Data) = YEAR(CURRENT_DATE())
	AND vm.CodLibro = v.CodLibro;
	CREATE TABLE WorstSellers SELECT CodLibro, NumeroVendite
	FROM VenditeMensili
	ORDER BY NumeroVendite ASC
	LIMIT 30;
