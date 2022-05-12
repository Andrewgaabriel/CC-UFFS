
DROP FUNCTION calcula_valor(op int, value float);
CREATE FUNCTION calcula_valor(op int, value float)
RETURNS float
AS
$$
declare
  new_value float;
begin

    if op = 1 then
        new_value = value + (value * 0.05);
    else
        new_value = value + (value * 0.01);
    end if;

    RETURN new_value;

    end;
$$
Language plpgsql;
