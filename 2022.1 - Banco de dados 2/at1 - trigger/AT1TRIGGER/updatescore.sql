DROP TRIGGER updatescore on contents;
DROP FUNCTION updatescore();
CREATE FUNCTION updatescore()

RETURNS TRIGGER
AS
$$
DECLARE

  temp record;
  dID int;

BEGIN

FOR temp IN SELECT d.director_id
            FROM contents c JOIN content_directors cd ON c.content_id=cd.content_id
                            JOIN directors d ON d.director_id=cd.director_id
            WHERE c.content_id = NEW.content_id

  LOOP

    dID := temp.director_id;

    UPDATE score SET media = (
                        SELECT avg(imdb_score) FROM contents c
                              JOIN content_directors cd ON c.content_id=cd.content_id
                              JOIN directors d ON d.director_id=cd.director_id
                        WHERE d.director_id = dID)
    WHERE director_id = dID;

  END LOOP;

  RETURN NEW;
  
end;
$$
Language plpgsql;


CREATE TRIGGER updatescore AFTER UPDATE ON contents  
    FOR EACH ROW EXECUTE PROCEDURE updatescore();


