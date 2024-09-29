# Projeto de Substituição de Páginas

Este projeto simula um algoritmo de substituição de páginas utilizando três estratégias diferentes: FIFO (First In, First Out), OTM (Ótimo) e LRU (Least Recently Used). O projeto foi desenvolvido em C++ e inclui métodos para calcular e exibir métricas de desempenho dos algoritmos.

## Estrutura do Projeto

```
/build            # Contém os arquivos gerados pela compilação
/src              # Código fonte (.cpp e .h)
/instances       # Arquivos de entrada (ex: instancias.txt)
/docs            # Arquivo .pdf com a descrição do projeto
Makefile          # Arquivo Makefile para gerenciar a compilação e execução
build.sh          # Script para compilar o projeto
```

## Pré-requisitos

- **Compilador C++:** O projeto foi desenvolvido e testado com `g++`.
- **make:** Opcional, para usar o `Makefile`. Caso não tenha o `make` instalado, você pode usar os scripts de shell fornecidos.

## Compilação e Execução

### Usando o Makefile

Para compilar o projeto usando o `Makefile`, execute o seguinte comando no diretório principal:

```bash
make
```

Isso irá compilar o código e gerar o executável `avob_page_replacement`.

Para limpar os arquivos gerados, use:

```bash
make clean
```

Para compilar e executar o programa com a instância 1, use:

```bash
make run
```


Para compilar e executar o programa com um arquivo de instância específico, use:

```bash
make run INSTANCES_FILE=instances/instance1.txt
```

### Usando Scripts de Shell

Se o `make` não estiver disponível, você pode usar os scripts de shell fornecidos:

- **Compilar o Projeto:**

  ```bash
  ./build.sh
  ```

- **Executar o Projeto com a instancia 1:**

  ```bash
  ./build/avob_page_replacement
  ```

- **Executar o Projeto com uma instãncia específica:**

  ```bash
  ./build/avob_page_replacement instances/instance2.txt
  ```

## Arquivos

- **`src/`**: Contém o código fonte do projeto.
  - `main.cpp`: Ponto de entrada do programa.
  - `PageReplacement.cpp` / `PageReplacement.h`: Implementação e declaração da classe `PageReplacement`.
- **`instances/`**: Contém arquivos de entrada (ex: `instancia1.txt`).
- **`Makefile`**: Arquivo para gerenciar a compilação usando `make`.
- **`build.sh`**: Script para compilar o projeto.

## Uso

1. **Prepare o Arquivo de Entrada:**
   - Coloque seus arquivos de entrada na pasta `instances/`. O formato do arquivo deve ser:
     ```
     numero_de_quadros_da_memória
     numero_da_pagina_1
     numero_da_pagina_2
     numero_da_pagina_3
     .
     .
     .
     numero_da_pagina_n
     ```

2. **Compile o Projeto:**
   - Usando `make` ou o script `build.sh`.

3. **Execute o Programa:**
   - Usando `make run INSTANCE_FILE=path_to_file` ou executando o executável `./build/page_replacement path_to_file`.
