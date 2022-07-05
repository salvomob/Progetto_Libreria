create trigger delCliente AFTER DELETE ON Clienti
FOR EACH ROW 
	delete from TesseraAcquisti 
	where CodCliente = OLD.CodCliente
