SET GLOBAL local_infile=1;
SET GLOBAL log_bin_trust_function_creators = 1;
source /home/salvatore/Scrivania/progetto_database/crea_tabelle.sql
source /home/salvatore/Scrivania/progetto_database/insCliente.sql
source /home/salvatore/Scrivania/progetto_database/delCliente.sql
source /home/salvatore/Scrivania/progetto_database/insDipendente.sql
source /home/salvatore/Scrivania/progetto_database/delDipendente.sql
source /home/salvatore/Scrivania/progetto_database/updateVendita.sql
LOAD DATA LOCAL INFILE "autori.txt" INTO TABLE Autori
FIELDS TERMINATED BY ','
LINES TERMINATED BY '\n';
LOAD DATA LOCAL INFILE "promozioni.txt" INTO TABLE Promozioni
FIELDS TERMINATED BY ','
LINES TERMINATED BY '\n';
LOAD DATA LOCAL INFILE "mansioni.txt" INTO TABLE Mansioni
FIELDS TERMINATED BY ','
LINES TERMINATED BY '\n';
LOAD DATA LOCAL INFILE "clienti.txt" INTO TABLE Clienti
FIELDS TERMINATED BY ','
LINES TERMINATED BY '\n';
LOAD DATA LOCAL INFILE "dipendenti.txt" INTO TABLE Dipendenti
FIELDS TERMINATED BY ','
LINES TERMINATED BY '\n';
LOAD DATA LOCAL INFILE "libri.txt" INTO TABLE Libri
FIELDS TERMINATED BY ','
LINES TERMINATED BY '\n';
source /home/salvatore/Scrivania/progetto_database/danteMonthOpening.sql
source /home/salvatore/Scrivania/progetto_database/danteMonthClosure.sql
source /home/salvatore/Scrivania/progetto_database/camilleriMonthOpening.sql
source /home/salvatore/Scrivania/progetto_database/camilleriMonthClosure.sql
source /home/salvatore/Scrivania/progetto_database/pirandelloMonthOpening.sql
source /home/salvatore/Scrivania/progetto_database/pirandelloMonthClosure.sql
source /home/salvatore/Scrivania/progetto_database/smithMonthOpening.sql
source /home/salvatore/Scrivania/progetto_database/smithMonthClosure.sql
source /home/salvatore/Scrivania/progetto_database/rowlingMonthOpening.sql
source /home/salvatore/Scrivania/progetto_database/rowlingMonthClosure.sql
source /home/salvatore/Scrivania/progetto_database/worstsellers.sql
source /home/salvatore/Scrivania/progetto_database/bestsellers.sql
source /home/salvatore/Scrivania/progetto_database/refreshAcquisti.sql
source /home/salvatore/Scrivania/progetto_database/refreshVendite.sql
source /home/salvatore/Scrivania/progetto_database/refreshTrePiùUno.sql
source /home/salvatore/Scrivania/progetto_database/refreshSeiPiùUno.sql
source /home/salvatore/Scrivania/progetto_database/refreshNovePiùUno.sql
source /home/salvatore/Scrivania/progetto_database/applicaProm.sql
source /home/salvatore/Scrivania/progetto_database/calcolaPromo.sql
source /home/salvatore/Scrivania/progetto_database/calcolaStipendio.sql
source /home/salvatore/Scrivania/progetto_database/calcolaStipendi.sql
source /home/salvatore/Scrivania/progetto_database/mensili.sql
source /home/salvatore/Scrivania/progetto_database/calcolaPrezzo.sql
source /home/salvatore/Scrivania/progetto_database/acquisto.sql
/*
in here all the LOAD DATA LOCAL INFILE -> to be completed
*/
