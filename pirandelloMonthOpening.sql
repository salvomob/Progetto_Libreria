SET GLOBAL event_scheduler=1;
USE PROGETTO_DB;
CREATE EVENT PirandelloOpening
ON SCHEDULE EVERY '1' YEAR
STARTS '2022-06-01 00:00:00' 
DO
	UPDATE Autori
	SET MeseAutore = true
	WHERE Nome = 'Luigi'
	AND Cognome = 'Pirandello';
