DROP TRIGGER logs on contents;
DROP FUNCTION logs();

CREATE FUNCTION logs()
RETURNS TRIGGER
AS
$$
DECLARE
    currentU varchar(255);
    currentD date;
BEGIN
    SELECT current_user INTO currentU;
    SELECT current_date INTO currentD;

    NEW.c_user = currentU;
    NEW.c_date = currentD;
  
    RETURN NEW;

    END;
$$
Language plpgsql;


CREATE TRIGGER logs BEFORE UPDATE ON contents  
    FOR EACH ROW EXECUTE PROCEDURE logs();