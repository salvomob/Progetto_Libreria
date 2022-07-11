SET GLOBAL event_scheduler=1;
USE PROGETTO_DB;
CREATE EVENT RowlingClosure
ON SCHEDULE EVERY '1' YEAR
STARTS '2022-07-31 23:59:59' 
DO
	UPDATE Autori
	SET MeseAutore = false
	WHERE Nome = 'J K'
	AND Cognome = 'Rowling';
