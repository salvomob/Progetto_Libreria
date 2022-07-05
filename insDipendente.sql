create trigger insDipendente AFTER INSERT ON Dipendenti
FOR EACH ROW
	insert into VenditeDipendenti values(NEW.CodDipendente,0)
