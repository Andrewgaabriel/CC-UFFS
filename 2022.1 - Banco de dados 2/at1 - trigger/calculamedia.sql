DROP TRIGGER atContents on contents;
DROP FUNCTION atContents();
CREATE FUNCTION atContents()

RETURNS TRIGGER
AS
$$
DECLARE
  nmedia numeric;
  temp int;
  dID int;
  DECLARE teste1 CURSOR FOR
  SELECT d.director_id
  FROM contents c JOIN content_directors cd
  ON c.content_id=cd.content_id JOIN directors d ON d.director_id=cd.director_id
  WHERE c.content_id = NEW.content_id;
begin

  /* ! ELE RETORNA UMA COLUNA COM VÁRIOS ID, PRECISO DESCOBRIR COMO MANIPULAR ESSES
   IDS PARA FAZER USO NA HORA DO CALCULO DA MÉDIA */
   /* ANTES DE ALTERAR ESSE PARA FUNCIONAR DEVE-SE REATUALIZAR A TABELA SCORE (foram feitas atualizações ) */
  /* select d.director_id into dID from contents c join content_directors cd
  on c.content_id=cd.content_id join directors d on d.director_id=cd.director_id
  where c.content_id = NEW.content_id; */

  

  --OPEN teste1; /* TESTE1 TEM OS IDS DOS DIRETORES QUE DEVEM TER SUAS MEDIAS ALTERADAS */

  FETCH FIRST FROM teste1 INTO dID;

  /* FOR dID IN teste1 LOOP
    UPDATE score SET media = (SELECT avg(imdb_score) FROM contents c JOIN content_directors cd
    ON c.content_id=cd.content_id JOIN directors d ON d.director_id=cd.director_id
    WHERE d.director_id = dID)
    WHERE director_id = dID;
  END LOOP; */

  WHILE (found) LOOP

    SELECT avg(c.imdb_score) INTO nmedia FROM contents c
    JOIN content_directors cd ON c.content_id=cd.content_id
    JOIN directors d ON d.director_id=cd.director_id
    WHERE d.director_id = dID group by d.name;

    UPDATE score set media = nmedia where director_id = dID;

    FETCH NEXT FROM teste1 INTO dID;

  END LOOP;

  CLOSE teste1;

  RETURN NEW;
end;
$$
Language plpgsql;


CREATE TRIGGER atContents AFTER UPDATE ON contents  
    FOR EACH ROW EXECUTE PROCEDURE atContents();


