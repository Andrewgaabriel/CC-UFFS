
DROP FUNCTION update_salary();
CREATE FUNCTION update_salary()
RETURNS table(id int, nome varchar(50), salario float)
AS
$$

begin

    update users u set salario = calcula_valor(1, u.salario) where u.salario < 10000;
    update users u set salario = calcula_valor(2, u.salario) where u.salario > 10000;


    RETURN query select u.id, u.nome, u.salario from users u;

    end;
$$
Language plpgsql;
