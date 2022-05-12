DROP FUNCTION insereDados(id int, name varchar(50), birthyear int, salary float);
CREATE FUNCTION insereDados(idT int, nameT varchar(50), birthyearT int, salaryT float)

RETURNS table(id int, nome varchar(50), birthyear int,salary float)
AS
$$
declare
    currentU varchar(255);
    currentD date;
begin
    select current_user into currentU;
    select current_date into currentD;
    insert into employee(id, name, birthyear, salary, c_user, c_date) values (idT, nameT, birthyearT, salaryT, currentU, currentD);
  

    RETURN query select u.id, u.name, u.birthyear, u.salary from employee u;

    end;
$$
Language plpgsql;