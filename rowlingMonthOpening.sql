SET GLOBAL event_scheduler=1;
USE PROGETTO_DB;
CREATE EVENT RowlingOpening
ON SCHEDULE EVERY '1' YEAR
STARTS '2022-07-01 00:00:00' --inizio promozione mese nascita J K Rowling
DO
	UPDATE Autori
	SET MeseAutore = true
	WHERE Nome = 'J K'
	AND Cognome = 'Rowling';
