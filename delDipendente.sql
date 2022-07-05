create trigger delDipendente AFTER DELETE ON Dipendenti
FOR EACH ROW 
	delete from VenditeDipendenti 
	where CodDipendente = OLD.CodDipendente

