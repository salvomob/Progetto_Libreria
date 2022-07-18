SET GLOBAL event_scheduler=1;
USE PROGETTO_DB;
CREATE EVENT RefreshAcquisti
ON SCHEDULE EVERY '1' MONTH
STARTS '2022-06-30 11:00:00'
DO
	UPDATE TesseraAcquisti
	SET AcquistiMensili = 0;
