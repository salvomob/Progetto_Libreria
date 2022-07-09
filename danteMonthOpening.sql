SET GLOBAL event_scheduler=1;
USE PROGETTO_DB;
CREATE EVENT DanteOpening
ON SCHEDULE EVERY '1' YEAR
STARTS '2022-05-01 00:00:00' --inizio promozione mese nascita Dante Alighieri
DO
	UPDATE Autori
	SET MeseAutore = true
	WHERE Nome = 'Dante'
	AND Cognome = 'Alighieri';
