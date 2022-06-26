# **Incrementando variável global utilizando semaforos e alternância entre as threads**

## **Como executar:**
    
    ```bash
    $ cd at3-semaphore
    $ make
    $ ./main
    ```

# **Problema:**




## **Empregando semáforos, resolva o seguinte problema:**

- A partir de uma thread principal criar 3 threads;

- Cada thread executa, basicamente, a mesma tarefa que consiste em incrementar uma variável global
inicializada com valor zero (0); no entanto, a cada rodada envolvendo todas as threads, cada thread
incrementa a variável global uma única vez. Além disso, a alternância entre as threads dá-se sempre
em ordem crescente de identificadores. Assumir identificadores das threads incrementais iniciando-se
a primeira thread com ID=0. Exemplo: assumindo-se que  as 3 threads tem ids 0, 1 e 2, ter-se-á a
seguinte apresentação de incremento da variável global:

    - thread 0: global = 1;
    - thread 1: global = 2;
    - thread 2: global = 3;
    - thread 0: global = 4;
    - thread 1: global = 5;