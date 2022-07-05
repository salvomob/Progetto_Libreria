create trigger insCliente AFTER INSERT ON Clienti
FOR EACH ROW 
	insert into TesseraAcquisti values(NEW.CodCliente,0);
