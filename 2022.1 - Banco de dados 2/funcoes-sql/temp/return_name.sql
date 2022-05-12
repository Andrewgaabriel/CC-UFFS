CREATE TABLE IF NOT EXISTS usuario(id int, nome varchar(50));



DROP FUNCTION return_name();
CREATE FUNCTION return_name()
RETURNS table(nome varchar(50))
AS
$$
declare
  media float;
begin
  select avg(id) into media from usuario;
  RETURN query select u.nome from usuario u where id > media;
 end;
$$
Language plpgsql;