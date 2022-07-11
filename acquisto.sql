USE PROGETTO_DB;

DELIMITER $$

CREATE PROCEDURE Acquisto(
	IN IdCliente INT,
	IN IdDipendente INT,
	IN IdLibro INT
)
BEGIN
	DECLARE P VARCHAR(1);
	DECLARE N INT DEFAULT 0;
	SELECT CodProm INTO P
	FROM Libri
	WHERE CodLibro = IdLibro;
	SELECT AcquistiMensili INTO N
	FROM TesseraAcquisti
	WHERE CodCliente = IdCliente;
	IF N = 4 THEN
		INSERT INTO Vendite(CodCliente,CodDipendente,CodLibro,Data,CodProm,TrePiùUno) values(IdCliente,IdDipendente,IdLibro,CURDATE(),P,true);
	ELSEIF N = 7 THEN
		INSERT INTO Vendite(CodCliente,CodDipendente,CodLibro,Data,CodProm,SeiPiùUno) values(IdCliente,IdDipendente,IdLibro,CURDATE(),P,true);
	ELSEIF N = 10 THEN
		INSERT INTO Vendite(CodCliente,CodDipendente,CodLibro,Data,CodProm,NovePiùUno) values(IdCliente,IdDipendente,IdLibro,CURDATE(),P,true);
	ELSE
		INSERT INTO Vendite(CodCliente,CodDipendente,CodLibro,Data,CodProm) values(IdCliente,IdDipendente,IdLibro,CURDATE(),P);		
	END IF;
END $$
DELIMITER ;
