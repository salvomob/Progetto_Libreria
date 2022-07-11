SET GLOBAL event_scheduler=1;
USE PROGETTO_DB;
CREATE EVENT CamilleriOpening
ON SCHEDULE EVERY '1' YEAR
STARTS '2022-09-01 00:00:00' 
DO
	UPDATE Autori
	SET MeseAutore = true
	WHERE Nome = 'Andrea'
	AND Cognome = 'Camilleri';
