DROP FUNCTION removehighmedia();
CREATE FUNCTION removehighmedia()

RETURNS table(nome varchar(50), salary float)
AS
$$
declare
  media float;
begin
    select avg(e.salary) into media from employee e;
    delete from employee em where em.salary < media;
  

    RETURN query select u.name, u.salary from employee u;

    end;
$$
Language plpgsql;