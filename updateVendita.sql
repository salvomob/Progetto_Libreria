delimiter //
create trigger updateVendita AFTER INSERT ON Vendite
FOR EACH ROW
BEGIN
	UPDATE VenditeDipendenti v
	SET NumeroVendite = NumeroVendite + 1
	WHERE v.CodDipendente = NEW.CodDipendente;
	UPDATE TesseraAcquisti t
	SET AcquistiMensili = AcquistiMensili + 1
	WHERE t.CodCliente = NEW.CodCliente;
	IF NEW.TrePiùUno = true THEN
		UPDATE Clienti c
		SET c.TrePiùUno = true
		WHERE NEW.CodCliente = c.CodCliente;
	END IF;
	IF NEW.SeiPiùUno = true THEN
		UPDATE Clienti c
		SET c.SeiPiùUno = true
		WHERE NEW.CodCliente = c.CodCliente;
	END IF;
	IF NEW.NovePiùUno = true THEN
		UPDATE Clienti c
		SET c.NovePiùUno = true
		WHERE NEW.CodCliente = c.CodCliente;
	END IF;
END //
delimiter ;
