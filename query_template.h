#define query_cod_libro (char*) "SELECT * FROM Libri WHERE CodLibro = " 
#define query_tit_libro (char*) "SELECT * FROM Libri WHERE Titolo = " 
#define query_cod_autore (char*) "SELECT * FROM Autori WHERE CodAutore = " 
#define query_sur_autore (char*) "SELECT * FROM Autori WHERE Cognome = "
#define query_cod_cliente (char*) "SELECT * FROM Clienti WHERE CodCliente = " 
#define query_sur_cliente (char*) "SELECT * FROM Clienti WHERE Cognome = " 
#define query_cod_dipendente (char*) "SELECT * FROM Dipendenti WHERE CodDipendente = " 
#define query_sur_dipendente (char*) "SELECT * FROM Dipendenti WHERE Cognome = " 
#define query_bestseller (char*) "SELECT * FROM BestSellers"
#define query_ins_libro (char*) "INSERT INTO Libri(Titolo,CodAutore,AnnoPrimaPubblicazione,PrezzoBase,Tipologia,Link,CodiceDownload,CodProm) VALUES("
#define query_ins_autori (char*) "INSERT INTO Autori(Nome,Cognome,AnnoNascita,AnnoMorte,MeseAutore) VALUES("
#define query_ins_clienti (char*) "INSERT INTO Clienti(Nome,Cognome,Indirizzo,CodiceFiscale) VALUES("
#define query_ins_dipendenti (char*) "INSERT INTO Dipendenti(Nome,Cognome,Indirizzo,CodiceFiscale,CodMansione) VALUES("
#define query_del_cod_libro (char*) "DELETE FROM Libri WHERE CodLibro = " 
#define query_del_tit_libro (char*) "DELETE FROM Libri WHERE Titolo = " 
#define query_del_cod_autore (char*) "DELETE FROM Autori WHERE CodAutore = " 
#define query_del_sur_autore (char*) "DELETE FROM Autori WHERE (Nome = "
#define query_del_cod_cliente (char*) "DELETE FROM Clienti WHERE CodCliente = " 
#define query_del_sur_cliente (char*) "DELETE FROM Clienti WHERE (Nome = " 
#define query_del_cod_dipendente (char*) "DELETE FROM Dipendenti WHERE CodDipendente = " 
#define query_del_sur_dipendente (char*) "DELETE FROM Dipendenti (WHERE Nome = " 
#define query_calcola_prezzo (char*) "SELECT CalcolaPrezzo("
#define query_acquisto (char*) "CALL Acquisto("
#define query_all_libri (char*) "SELECT * FROM Libri"
#define query_all_clienti (char*) "SELECT * FROM Clienti"
#define query_all_autori (char*) "SELECT * FROM Autori"
#define query_all_dipendenti (char*) "SELECT * FROM Dipendenti"