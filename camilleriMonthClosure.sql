SET GLOBAL event_scheduler=1;
USE PROGETTO_DB;
CREATE EVENT CamilleriClosure
ON SCHEDULE EVERY '1' YEAR
STARTS '2022-09-30 23:59:59' 
DO
	UPDATE Autori
	SET MeseAutore = false
	WHERE Nome = 'Andrea'
	AND Cognome = 'Camilleri';
