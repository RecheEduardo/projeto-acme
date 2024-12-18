# Projeto ACME 
**Projeto em C utilizando estruturas de dados dinâmicas para administração de uma empresa**  

**Desenvolvido por:**

**DIEGO ROCHA VITALI**  
**EDUARDO RECHE MARTINS**  

## PROJETO ACME  
**GUARULHOS - 2024**

---

## SUMÁRIO
1. [Introdução](#1-introdução)  
2. [Funcionamento do Programa](#2-funcionamento-do-programa)  
   2.1 [main.c](#21-mainc)  
   2.2 [acme.c](#22-acmec)  
      - [2.2.1 criaLista](#221-crialista)  
      - [2.2.2 carregarDados](#222-carregardados)  
      - [2.2.3 abortaPrograma](#223-abortaprograma)  
      - [2.2.4 exibeMenu](#224-exibemenu)  
      - [2.2.5 exibirDadosCliente](#225-exibirdadoscliente)  
      - [2.2.6 tamanhoLista](#226-tamanholista)  
      - [2.2.7 listaCheia](#227-listacheia)  
      - [2.2.8 listaVazia](#228-listavazia)  
      - [2.2.9 coletaDados](#229-coletadados)  
      - [2.2.10 insereOrdenado](#2210-insereordenado)  
      - [2.2.11 exibirListaCompleta](#2211-exibirlistacompleta)  
      - [2.2.12 consultaID](#2212-consultaid)  
      - [2.2.13 consultaNome](#2213-consultanome)  
      - [2.2.14 editarCliente](#2214-editarcliente)  
      - [2.2.15 removeOrdenado](#2215-removeordenado)  
      - [2.2.16 salvarClientes](#2216-salvarclientes)  
      - [2.2.17 apagaLista](#2217-apagalista)  
3. [Principais Problemas Identificados](#3-principais-problemas-identificados)  
   3.1 [Duplicidade de IDs](#31-duplicidade-de-ids)  
   3.2 [Pesquisa por Nome Composto/Completo](#32-pesquisa-por-nome-compostocompleto)  
   3.3 [Editar Usuários](#33-editar-usuários)  
4. [Considerações Finais](#4-considerações-finais)  

---

## 1. Introdução
Este projeto é um sistema de gerenciamento de clientes desenvolvido para a empresa fictícia **ACME**. Ele utiliza uma lista encadeada para armazenar os dados dos clientes, como ID, nome, empresa, telefone e e-mail, permitindo realizar diversas operações, como adicionar, buscar, editar, remover e salvar clientes. 

O sistema trabalha com um arquivo binário para armazenamento de dados. Assim, sempre que o programa for iniciado, o usuário poderá continuar seu gerenciamento de clientes de onde parou. Ele foi projetado para ser simples de usar, com um menu interativo que guia o usuário por todas as funcionalidades disponíveis.

---

## 2. Funcionamento do Programa
O sistema utiliza duas estruturas principais:  
- **CLIENTE**: Contém informações como ID, nome, empresa, departamento, telefone fixo, telefone celular e e-mail.  
- **elemento**: Estrutura utilizada para criar os nós da lista encadeada, onde cada nó contém um cliente e um ponteiro para o próximo nó.  

### 2.1 main.c
A função `main` organiza o programa:  
- Inicializa uma lista encadeada para armazenar os clientes.  
- Carrega os dados do arquivo binário `clientes.bin`, caso exista.  
- Exibe um menu principal para realizar operações como inserir, consultar, editar, remover e salvar clientes, chamando funções específicas para cada funcionalidade.  

### 2.2 acme.c
O arquivo `acme.c` contém todas as funções do programa organizadas para facilitar o uso. Abaixo estão suas funcionalidades:  

#### 2.2.1 criaLista
- Aloca memória para a lista e inicializa o ponteiro como `NULL`.  
- Retorna um ponteiro para a lista, caso a alocação seja bem-sucedida.  

#### 2.2.2 carregarDados
- Carrega os dados dos clientes a partir de um arquivo binário.  
- Insere os clientes na lista utilizando `insereOrdenado`.  

#### 2.2.3 abortaPrograma
- Exibe uma mensagem de erro e encerra o programa em caso de falhas críticas.  

#### 2.2.4 exibeMenu
- Exibe as opções disponíveis, como inserir cliente, buscar cliente e salvar lista.  

#### 2.2.5 exibirDadosCliente
- Recebe um ponteiro para um cliente e exibe suas informações formatadas na tela.  

#### 2.2.6 tamanhoLista
- Retorna o número de elementos na lista, percorrendo os nós até o final.  

#### 2.2.7 listaCheia
- Retorna `0`, pois uma lista dinâmica não possui limite de tamanho.  

#### 2.2.8 listaVazia
- Retorna `1` se o ponteiro da lista for nulo; caso contrário, retorna `0`.  

#### 2.2.9 coletaDados
- Coleta dados do cliente fornecidos pelo usuário e os armazena em uma estrutura `CLIENTE`.  

#### 2.2.10 insereOrdenado
- Insere um cliente na lista de forma ordenada pelo ID.  

#### 2.2.11 exibirListaCompleta
- Percorre a lista e exibe todos os clientes.  

#### 2.2.12 consultaID
- Busca um cliente pelo ID e retorna `1` se encontrado, ou `0` caso contrário.  

#### 2.2.13 consultaNome
- Busca clientes pelo nome, realizando uma pesquisa case-insensitive.  

#### 2.2.14 editarCliente
- Solicita o ID do cliente, exibe seus dados atuais, e coleta novos dados para substituí-lo.  

#### 2.2.15 removeOrdenado
- Remove um cliente pelo ID, ajustando os ponteiros da lista.  

#### 2.2.16 salvarClientes
- Salva os dados dos clientes no arquivo binário.  

#### 2.2.17 apagaLista
- Libera a memória alocada para todos os nós da lista.  

---

## 3. Principais Problemas Identificados
Durante o desenvolvimento, alguns problemas foram enfrentados, como:  

### 3.1 Duplicidade de IDs
- **Problema:** O programa permitia cadastrar clientes com IDs duplicados.  
- **Solução:** Foi implementada uma verificação que impede a inserção de IDs já existentes.  

### 3.2 Pesquisa por Nome Composto/Completo
- **Problema:** A busca por nome era sensível a termos específicos, não retornando resultados de nomes compostos.  
- **Solução:** Substituição de funções de strings inadequadas pela função `strstr`.  

### 3.3 Editar Usuários
- **Problema:** A edição exigia múltiplas funções para substituir os dados de cada campo.  
- **Solução:** O cliente antigo foi excluído e um novo cliente foi criado em seu lugar.  

---

## 4. Considerações Finais
O sistema de gerenciamento de clientes para a empresa fictícia **ACME** demonstrou a eficácia das listas encadeadas para armazenamento e manipulação de dados.  

Os problemas identificados durante o desenvolvimento, como duplicidade de IDs, busca por nomes compostos e edição de dados, foram solucionados de forma eficaz, garantindo a funcionalidade do sistema.  

A escolha de um arquivo binário para persistência de dados e a implementação de um menu interativo tornaram o sistema prático e funcional, entregando uma solução robusta e intuitiva.  
