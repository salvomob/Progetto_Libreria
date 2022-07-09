SET GLOBAL event_scheduler=1;
USE PROGETTO_DB;
CREATE EVENT SmithClosure
ON SCHEDULE EVERY '1' YEAR
STARTS '2022-01-31 23:59:59' --fine promozione mese nascita Wilbour Smith
DO
	UPDATE Autori
	SET MeseAutore = false
	WHERE Nome = 'Wilbour'
	AND Cognome = 'Smith';
