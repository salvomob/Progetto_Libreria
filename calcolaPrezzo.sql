USE PROGETTO_DB;

DELIMITER $$

CREATE FUNCTION CalcolaPrezzo(IdLibro int,IdCliente int)
RETURNS FLOAT
BEGIN
	DECLARE X,Y,Z FLOAT DEFAULT 0;
	DECLARE P VARCHAR(1);
	DECLARE N INT DEFAULT 0;
	DECLARE M BOOLEAN DEFAULT false;
	SELECT PrezzoBase INTO X
	FROM Libri
	WHERE CodLibro = IdLibro;
	SELECT CodProm INTO P
	FROM Libri
	WHERE CodLibro = IdLibro;
	SELECT AcquistiMensili INTO N
	FROM TesseraAcquisti
	WHERE CodCliente = IdCliente;
	SELECT MeseAutore INTO M
	FROM Autori a, Libri l
	WHERE a.CodAutore = l.CodAutore
	AND l.CodLibro = IdLibro;
	IF N = 3 THEN
		SET X = X - (X/20);
	END IF;
	IF N = 6 THEN
		SET X = X - (X/10);
	END IF;
	IF N = 9 THEN
		SET X = X - (X/5);
	END IF;
	IF P IS NOT NULL OR P != '' THEN
		SELECT Sconto INTO Y
		FROM Promozioni
		WHERE CodProm = P;
		SET X = X - (X*Y);
	END IF;
	IF M = true THEN
		SET X = X - (X/10);
	END IF;
	RETURN X;
	
END	$$
delimiter ;
