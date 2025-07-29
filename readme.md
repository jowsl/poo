# O projeto - Gerenciador de Sistema de Controle de Voo em Aeroporto

Para compilar o nosso projeto, demos preferencia ao uso do `Make`, que é uma ferramenta de automação de compilação. Para isso, você deve ter o Make instalado em seu sistema. 

O make vai ler o arquivo `Makefile` que contém as instruções de compilação e linkagem dos arquivos fonte do projeto.
Gerando o executável `main` a partir dos arquivos `.c` e `.h` presentes no diretório.

# Compilação e Execução do Projeto

```bash
make
```
E para executar o jogo, use:

```bash
./main
```

Nosso projeto foi dividido usando menus e sub-menus que vão executar as funcionalidades do jogo.
Cara valor entrado leva para uma case do if, que por si chamará uma função específica.

# Gravação 


- Salvar / Carregar 
- Extra - Salvar Estatísticas 
