SET GLOBAL event_scheduler=1;
USE PROGETTO_DB;
CREATE EVENT SmithOpening
ON SCHEDULE EVERY '1' YEAR
STARTS '2022-01-01 00:00:00' 
DO
	UPDATE Autori
	SET MeseAutore = true
	WHERE Nome = 'Wilbur'
	AND Cognome = 'Smith';
