SET GLOBAL event_scheduler=1;
USE PROGETTO_DB;
CREATE EVENT PirandelloClosure
ON SCHEDULE EVERY '1' YEAR
STARTS '2022-06-30 23:59:59' --fine promozione mese nascita Pirandello
DO
	UPDATE Autori
	SET MeseAutore = false
	WHERE Nome = 'Luigi'
	AND Cognome = 'Pirandello';
