DROP TRIGGER check_orc on employee;
DROP FUNCTION check_orçamento();

CREATE FUNCTION check_orçamento() RETURNS TRIGGER AS $$
DECLARE
    orc_permitido float;
    orc_gasto float;
BEGIN
    SELECT orçamento INTO orc_permitido
    FROM departamento
    WHERE id = NEW.dep_id;
    
    SELECT INTO orc_gasto SUM(salario)
    FROM employee
    WHERE dep_id = NEW.dep_id;

    IF (orc_gasto+New.salary) > orc_permitido
    THEN
        RAISE EXCEPTION 'Orçamento acima do teto permitido [id:%] by [%]', NEW.id, (orc_gasto - orc_permitido);
    END IF;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;


CREATE trigger check_orc 
BEFORE 
INSERT ON employee 
for each row execute procedure check_orçamento();

 
