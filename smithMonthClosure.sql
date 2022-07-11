SET GLOBAL event_scheduler=1;
USE PROGETTO_DB;
CREATE EVENT SmithClosure
ON SCHEDULE EVERY '1' YEAR
STARTS '2022-01-31 23:59:59' --fine promozione mese nascita Wilbur Smith
DO
	UPDATE Autori
	SET MeseAutore = false
	WHERE Nome = 'Wilbur'
	AND Cognome = 'Smith';
