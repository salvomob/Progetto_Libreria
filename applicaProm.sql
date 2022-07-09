USE PROGETTO_DB;
DELIMITER $$

CREATE PROCEDURE applicaProm()
BEGIN
    DECLARE a,b,c,i INT DEFAULT 0;
    SET a = 10;
    SET b = 10;
    SET c = 10;
    SET i = 0;
    WHILE i<a DO
      UPDATE Libri l,A a
        SET CodProm = 'A'
		WHERE a.CodLibro = l.CodLibro;
		SET i = i+1;
    END WHILE;
    SET i = 0 ;
    WHILE i<b DO
      UPDATE Libri l, B b
        SET CodProm = 'B'
		WHERE b.CodLibro = l.CodLibro;
		SET i = i+1;
    END WHILE;
    SET i = 0 ;
    WHILE i<b DO
      UPDATE Libri l, C c
        SET CodProm = 'C'
		WHERE c.CodLibro = l.CodLibro;
		SET i = i+1;
    END WHILE;

END $$
DELIMITER ;
