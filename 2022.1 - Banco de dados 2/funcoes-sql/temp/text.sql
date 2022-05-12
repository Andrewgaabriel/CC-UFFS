DROP FUNCTION rtext(value text);
CREATE FUNCTION rtext(value text)
RETURNS text
AS
$$

begin
  RETURN value;
 end;
$$
Language plpgsql;