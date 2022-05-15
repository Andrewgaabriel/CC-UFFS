DROP TRIGGER update10s on employee;
DROP FUNCTION update10s();
CREATE FUNCTION update10s() 
RETURNS trigger AS $$
    BEGIN
        IF NEW.name IS NULL THEN
            RAISE EXCEPTION 'Nome não pode ser nulo';
        END IF;
        IF NEW.salary IS NULL THEN
            RAISE EXCEPTION 'Salário não pode ser nulo';
        END IF;
        
        IF NEW.salary < 0 THEN
            RAISE EXCEPTION 'Salário não pode ser negativo';
        END IF;

        /* ATUALIZA SALÁRIO ANTES DE GUARDAR NO BANCO */
        NEW.salary = NEW.salary * 1.10;

        RETURN NEW;
    END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER update10s BEFORE INSERT OR UPDATE ON employee  
    FOR EACH ROW EXECUTE PROCEDURE update10s();


