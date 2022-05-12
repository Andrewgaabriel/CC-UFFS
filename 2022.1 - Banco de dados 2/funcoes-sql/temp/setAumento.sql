DROP FUNCTION setAumento(fator float, idX int);
CREATE FUNCTION setAumento(fator float, idX int)

RETURNS table(nome varchar(50), salary float)
AS
$$
declare
  fatorX float;
begin
    fatorX = fator/100;
    update employee u set salary = u.salary + (u.salary * fatorX) where u.id > idX;
    


    RETURN query select u.name, u.salary from employee u;

    end;
$$
Language plpgsql;