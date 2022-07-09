SET GLOBAL event_scheduler=1;
USE PROGETTO_DB;
CREATE EVENT SmithOpening
ON SCHEDULE EVERY '1' YEAR
STARTS '2022-01-01 00:00:00' --inizio promozione mese nascita Wilbour Smith
DO
	UPDATE Autori
	SET MeseAutore = true
	WHERE Nome = 'Wilbour'
	AND Cognome = 'Smith';
