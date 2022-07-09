CREATE DATABASE PROGETTO_DB;
USE PROGETTO_DB;

create table Promozioni(
	CodProm ENUM('A','B','C') NOT NULL,
	Sconto float,
	PRIMARY KEY(CodProm)
)ENGINE=INNODB DEFAULT charset=utf8;

create table Autori(
	codAutore int NOT NULL AUTO_INCREMENT,
	Nome varchar(15),
	Cognome varchar(15),
	AnnoNascita Year(4),
	AnnoMorte Year(4),
	MeseAutore BOOLEAN DEFAULT false,
	PRIMARY KEY(CodAutore)
) ENGINE=INNODB DEFAULT charset=utf8;

create table Libri(
	CodLibro int NOT NULL AUTO_INCREMENT,
	Titolo varchar(15) NOT NULL,
	codAutore int NOT NULL,
	AnnoPrimaPubblicazione YEAR(4),
	PrezzoBase float,
	Tipologia ENUM('CARTACEO','AUDIOLIBRO','EBOOK','MISTO'),
	Link varchar(40),
	CodiceDownload varchar(10),
	CodProm ENUM('A','B','C'),
	PRIMARY KEY (CodLibro),
	FOREIGN KEY (CodAutore)
	REFERENCES Autori(CodAutore),
	FOREIGN KEY (CodProm)
	REFERENCES Promozioni(CodProm)
	ON DELETE CASCADE
)ENGINE=INNODB DEFAULT charset=utf8;

create table Clienti(
	CodCliente int NOT NULL AUTO_INCREMENT,
	Nome varchar(15),
	Cognome varchar(15),
	Indirizzo varchar(40),
	CodiceFiscale varchar(16),
	TrePiùUno BOOLEAN DEFAULT false,
	SeiPiùUno BOOLEAN DEFAULT false,
	NovePiùUno BOOLEAN DEFAULT false,
	PRIMARY KEY(CodCliente)
)ENGINE=INNODB DEFAULT charset=utf8;

create table Mansioni(
	CodMansione int NOT NULL AUTO_INCREMENT,
	Descrizione varchar(255),
	Salariobase int,
	PRIMARY KEY(CodMansione)
)ENGINE=INNODB DEFAULT charset=utf8;

create table Dipendenti(
	CodDipendente int NOT NULL AUTO_INCREMENT,
	Nome varchar(15),
	Cognome varchar(15),
	Indirizzo varchar(40),
	CodiceFiscale varchar(16) UNIQUE NOT NULL,
	CodMansione int NOT NULL,
	PRIMARY KEY(CodDipendente),
	FOREIGN KEY (CodMansione)
	REFERENCES Mansioni(CodMansione)
	ON DELETE CASCADE
)ENGINE=INNODB DEFAULT charset=utf8;

create table Vendite(
	ProgressivoVendita int NOT NULL AUTO_INCREMENT,
	CodCliente int NOT NULL,
	CodDipendente int NOT NULL,
	CodLibro int NOT NULL,
	Data date,
	CodProm ENUM('A','B','C'),	
	TrePiùUno BOOLEAN DEFAULT false,
	SeiPiùUno BOOLEAN DEFAULT false,
	NovePiùUno BOOLEAN DEFAULT false,
	PRIMARY KEY(ProgressivoVendita,CodCliente,CodDipendente,CodLibro,Data),
	FOREIGN KEY(CodCliente)
	REFERENCES Clienti(CodCliente),
	FOREIGN KEY(CodDipendente)
	REFERENCES Dipendenti(CodDipendente),
	FOREIGN KEY(CodLibro)
	REFERENCES Libri(CodLibro),
	FOREIGN KEY (CodProm)
	REFERENCES Promozioni(CodProm)
)ENGINE=INNODB DEFAULT charset=utf8;

create table TesseraAcquisti(
	CodCliente int NOT NULL,
	AcquistiMensili int,
	PRIMARY KEY(CodCliente),
	FOREIGN KEY(CodCliente)
	REFERENCES Clienti(CodCliente)
	ON DELETE CASCADE
)ENGINE=INNODB DEFAULT charset=utf8;


create table VenditeDipendenti(
	CodDipendente int NOT NULL,
	NumeroVendite int DEFAULT 0,
	PRIMARY KEY(CodDipendente),
	FOREIGN KEY(CodDipendente)
	REFERENCES Dipendenti(CodDipendente)
	ON DELETE CASCADE
)ENGINE=INNODB DEFAULT charset=utf8;

create table Bonus(
	NumeroVendite int,
	CompensoExtra int,
	PRIMARY KEY(NumeroVendite)	
)ENGINE=INNODB DEFAULT charset=utf8;
