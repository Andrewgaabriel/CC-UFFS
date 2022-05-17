UPDATE contents set imdb_score = 5 where content_id = 2; 

select title, imdb_score  from contents where content_id = 2;


/* BUSCA QUE RETORNA NOME DO DIRETOR, MEDIA DA TABELA SCORE,  */
select d.name, s.media from score s join directors d on s.director_id = d.director_id join 
content_directors cd on d.director_id=cd.director_id join contents c on c.content_id=cd.content_id
where c.content_id = 2;  

/* BUSCA QUE RETORNA A MEDIA JA CALCULADA + NOME DO DIRETOR*/
select d.name, avg(c.imdb_score) from contents c
    join content_directors cd on c.content_id=cd.content_id
    join directors d on d.director_id=cd.director_id
    where c.content_id = 2 group by d.name;


/* BUSCA PELO ID DO DIRETOR (busca a media na tabela score) */
select d.name, s.media from score s join directors d on s.director_id = d.director_id join 
content_directors cd on d.director_id=cd.director_id join contents c on c.content_id=cd.content_id
where d.director_id = 1 group by d.name, s.media; 

/* BUSCA PELO ID DO DIRETOR (calcula a media inves de buscar direto na tabela score - PARA VERIFICAÇÃO) */
select d.name, avg(c.imdb_score) from contents c
    join content_directors cd on c.content_id=cd.content_id
    join directors d on d.director_id=cd.director_id
    where d.director_id = 1 group by d.name;



/* RETORNA TABELA COM DIRETOR + MEDIA*/

select d.name, avg(c.imdb_score) from contents c
    join content_directors cd on c.content_id=cd.content_id
    join directors d on d.director_id=cd.director_id
    group by d.name;

 

 



/* FUNÇÃO QUE INSERE OS DADOS DENTRO DA TABELA SCORE */
INSERT INTO score(director_id, name, media) 
SELECT d.director_id, d.name, avg(c.imdb_score) from contents c
    join content_directors cd on c.content_id=cd.content_id 
    join directors d on d.director_id=cd.director_id
    group by d.director_id, d.name;


/* FUNÇÃO QUE DESCOBRE O NOME DOS DIRETORES + ID DO DIRETO -  DO FILME PELO ID */
select d.name, d.director_id, c.title from contents c
    join content_directors cd on c.content_id=cd.content_id
    join directors d on d.director_id=cd.director_id
    where c.content_id = 19;



/* função que retorna id do filme, titulo do filme, score, nome do diretor, id do diretor*/
select c.content_id, c.title,c.imdb_score, d.name, d.director_id  from contents c
    join content_directors cd on c.content_id=cd.content_id
    join directors d on d.director_id=cd.director_id
    where d.director_id = 58 group by d.name, c.title, d.director_id, c.imdb_score, c.content_id;