USE PROGETTO_DB;

delimiter %%

CREATE PROCEDURE CalcolaStipendi()
BEGIN		
	DROP TABLE IF EXISTS StipendiMensili;
	CREATE TABLE StipendiMensili(CodDipendente INT,Salario FLOAT DEFAULT 0)ENGINE=INNODB DEFAULT charset=utf8;
	INSERT INTO StipendiMensili(CodDipendente) SELECT DISTINCT CodDipendente FROM Dipendenti;
	UPDATE StipendiMensili sm, Dipendenti d
	SET sm.Salario = CalcolaStipendio(sm.CodDipendente)
	WHERE d.CodDipendente = sm.CodDipendente ;
END %%
delimiter ;
