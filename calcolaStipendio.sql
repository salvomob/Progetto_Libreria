USE PROGETTO_DB;
delimiter $$

CREATE FUNCTION CalcolaStipendio(IdDip INT)
RETURNS FLOAT 
BEGIN
	DECLARE X,A FLOAT DEFAULT 0;
	DECLARE Y,Z INT DEFAULT 0;
	SELECT CodMansione INTO Y
	FROM Dipendenti d
	WHERE d.CodDipendente = IdDip;
	SELECT Salariobase INTO X
	FROM Mansioni
	WHERE CodMansione = Y;
	IF Y = 1 THEN
		SELECT NumeroVendite INTO Z
		FROM VenditeDipendenti
		WHERE CodDipendente = IdDip;
		SET Z = 10 * FLOOR(Z / 10);
		IF Z > 100 THEN
			SET Z = 100;
		END IF;	
		SELECT CompensoExtra INTO A
		FROM Bonus
		WHERE NumeroVendite = Z;
		SET X = X + A;
	END IF;
	RETURN X * 1.0;
END $$
delimiter ;
