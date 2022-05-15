DROP TRIGGER att on contents;
DROP FUNCTION att();

CREATE FUNCTION att()
RETURNS TRIGGER
AS
$$
declare
    currentU varchar(255);
    currentD date;
begin
    select current_user into currentU;
    select current_date into currentD;
/*     insert into contents(c_user, c_date) values (currentU, currentD); */
    /* update contents set c_user = currentU, c_date = currentD where content_id = NEW.content_id; */
    NEW.c_user = currentU;
    NEW.c_date = currentD;
  

    RETURN NEW;

    end;
$$
Language plpgsql;


CREATE TRIGGER att BEFORE UPDATE ON contents  
    FOR EACH ROW EXECUTE PROCEDURE att();