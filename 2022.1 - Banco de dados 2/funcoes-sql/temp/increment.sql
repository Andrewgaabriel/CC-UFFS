DROP FUNCTION increment(value int);
CREATE FUNCTION increment(value int)
RETURNS int
AS
$$
declare
  new_value int;
begin
  new_value = value + 1;
  RETURN new_value;
 end;
$$
Language plpgsql;