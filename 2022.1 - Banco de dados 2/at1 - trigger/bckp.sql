DROP TRIGGER atContents on contents;
DROP FUNCTION atContents();
CREATE FUNCTION atContents()

RETURNS TRIGGER
AS
$$
declare
  nmedia numeric;
  dID int;
  temp int;
begin

  /* ! ELE RETORNA UMA COLUNA COM VÁRIOS ID, PRECISO DESCOBRIR COMO MANIPULAR ESSES
   IDS PARA FAZER USO NA HORA DO CALCULO DA MÉDIA */
   /* ANTES DE ALTERAR ESSE PARA FUNCIONAR DEVE-SE REATUALIZAR A TABELA SCORE (foram feitas atualizações ) */
  /* select d.director_id into dID from contents c join content_directors cd
  on c.content_id=cd.content_id join directors d on d.director_id=cd.director_id
  where c.content_id = NEW.content_id; */

  FOR temp in 
    select d.director_id from contents c join content_directors cd
  on c.content_id=cd.content_id join directors d on d.director_id=cd.director_id
  where c.content_id = NEW.content_id
  
  LOOP

    select avg(c.imdb_score) into nmedia from contents c
    join content_directors cd on c.content_id=cd.content_id
    join directors d on d.director_id=cd.director_id
    where d.director_id = temp group by d.name;

    UPDATE score set media = nmedia where director_id = temp;
  
  END LOOP;


  RETURN NEW;
end;
$$
Language plpgsql;


CREATE TRIGGER atContents AFTER UPDATE ON contents  
    FOR EACH ROW EXECUTE PROCEDURE atContents();


