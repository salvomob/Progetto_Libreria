SET GLOBAL event_scheduler=1;
USE PROGETTO_DB;
CREATE EVENT DanteClosure
ON SCHEDULE EVERY '1' YEAR
STARTS '2022-05-31 23:59:59' --fine promozione mese nascita Dante Alighieri
DO
	UPDATE Autori
	SET MeseAutore = false
	WHERE Nome = 'Dante'
	AND Cognome = 'Alighieri';
