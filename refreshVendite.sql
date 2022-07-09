SET GLOBAL event_scheduler=1;
USE PROGETTO_DB;
CREATE EVENT RefreshVendite
ON SCHEDULE EVERY '1' MONTH
STARTS '2022-07-05 11:00:00'
DO
	UPDATE VenditeDipendenti
	SET NumeroVendite = 0;
	UPDATE VenditeMensili
	SET NumeroVendite = 0;
