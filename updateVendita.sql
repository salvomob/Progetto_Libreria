create trigger updateVendita AFTER INSERT ON Vendite
FOR EACH ROW
	UPDATE VenditeDipendenti v
	SET NumeroVendite = NumeroVendite + 1
	WHERE v.CodDipendente = NEW.CodDipendente;

