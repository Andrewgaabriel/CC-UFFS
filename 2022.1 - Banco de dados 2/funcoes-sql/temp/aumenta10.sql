DROP FUNCTION aumenta10();
CREATE FUNCTION aumenta10()
RETURNS table(nome varchar(50), salary float)
AS
$$
declare
  media float;
begin

    update employee u set salary = u.salary + (u.salary * 0.1);
    


    RETURN query select u.nome, u.salary from employee u;

    end;
$$
Language plpgsql;