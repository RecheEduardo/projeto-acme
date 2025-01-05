<p align="center">
   <img src="https://readme-typing-svg.herokuapp.com?font=Century+Gothic&weight=800&size=48&pause=1000&color=F7F7F7&center=true&vCenter=true&width=435&lines=%E2%99%A6%EF%B8%8F+Blogalizando+%E2%99%A6%EF%B8%8F" alt="Typing SVG" />  
</p>

---

## 👥 Um projeto acadêmico de Estrutura de Dados do IFSP desenvolvido por
### • Eduardo Reche Martins | <a href="https://github.com/RecheEduardo" target="_blank">Github</a> | <a href="https://www.linkedin.com/in/eduardorechemartins/" target="_blank">LinkedIn</a>
### • Diego Rocha Vitali | <a href="https://github.com/Diego-Vitali" target="_blank">Github</a> | <a href="https://www.linkedin.com/in/diego-vitali-625619288/" target="_blank">LinkedIn</a>

---

## ⚙️ **Resumo do Projeto**
O programa **ACME** é uma aplicação desenvolvida em linguagem C para gerenciar uma lista de clientes. Ele utiliza uma estrutura dinâmica (lista encadeada) e fornece funcionalidades como inserção, edição, busca, exclusão e armazenamento de dados em arquivo binário.  

**💻 Recomendação de uso:** Este projeto é ideal para ser executado no ambiente **Code::Blocks**.

---

## 🌟 **Principais Funcionalidades**
- **📥 Inserção de clientes:** Adiciona clientes à lista de forma ordenada por ID.  
- **🔍 Busca personalizada:** Pesquisa clientes pelo ID ou por parte do nome.  
- **✏️ Edição de dados:** Permite alterar informações de um cliente existente.  
- **❌ Remoção de clientes:** Remove um cliente da lista com base no ID.  
- **📂 Persistência:** Salva ou carrega os dados em um arquivo binário `clientes.bin`.  
- **📄 Exibição:** Lista todos os clientes ou apenas um cliente específico.

---

## 🔗 **Estrutura do Projeto**
1. **Criação e gerenciamento da lista**
   - Lista encadeada implementada para armazenar clientes dinamicamente.
2. **Manipulação de dados**
   - Inserção ordenada, remoção, busca e edição de clientes.
3. **Armazenamento persistente**
   - Dados são salvos e carregados do arquivo `clientes.bin`.

---

## 📋 **Detalhamento das Funções**

### 📂 **Funções Estruturais**
- **`Lista *criaLista()`**  
  Cria e inicializa uma lista encadeada. Retorna um ponteiro para a lista.  

- **`void abortaPrograma()`**  
  Encerra o programa em caso de erros graves, exibindo mensagens de erro ao usuário.

---

### 🔍 **Funções de Busca e Exibição**
- **`int consultaID(Lista *li, int ID, CLIENTE *cl)`**  
  Busca um cliente pelo ID na lista. Retorna 1 se encontrado ou 0 caso contrário.  

- **`int consultaNome(Lista *li, char nome[80])`**  
  Pesquisa por clientes cujo nome contenha uma sequência específica de caracteres (insensível a maiúsculas/minúsculas). Retorna o número de clientes encontrados.  

- **`void exibirListaCompleta(Lista *li)`**  
  Exibe todos os clientes cadastrados na lista, incluindo seus dados completos.

- **`void exibirDadosCliente(CLIENTE *cl)`**  
  Exibe os dados de um cliente específico, formatando as informações de forma clara.

---

### ✍️ **Funções de Modificação**
- **`int insereOrdenado(Lista *li, CLIENTE cl)`**  
  Insere um novo cliente na lista, mantendo a ordenação por ID.  

- **`int editarCliente(Lista *li, int ID)`**  
  Permite modificar os dados de um cliente existente com base no ID.  

- **`int removeOrdenado(Lista *li, int ID)`**  
  Remove um cliente da lista pelo ID e ajusta os ponteiros da estrutura para preservar a integridade.

---

### 💾 **Funções de Persistência**
- **`int carregarDados(FILE *f, Lista *li)`**  
  Carrega os dados dos clientes armazenados no arquivo binário `clientes.bin` e os insere na lista.  

- **`int salvarClientes(FILE *f, Lista *li)`**  
  Grava todos os clientes da lista no arquivo binário, garantindo a persistência dos dados.  

- **`void apagaLista(Lista *li)`**  
  Libera toda a memória alocada para a lista, removendo todos os clientes.  

---

## 📄 **Formato dos Dados do Cliente**
Cada cliente cadastrado possui os seguintes atributos:  
- **ID:** Identificador único.  
- **Nome:** Nome completo do cliente.  
- **Empresa:** Nome da empresa associada ao cliente.  
- **Departamento:** Setor relacionado à empresa.  
- **Telefone Fixo e Celular:** Contato telefônico.  
- **Email:** Endereço eletrônico para contato.

---

## 🌟 **Como Usar**
1. **Compile e execute o programa em um ambiente compatível (recomendado: Code::Blocks).**  
2. **Siga o menu principal e escolha uma das opções abaixo:**  
```text
OPÇÃO 1 - INSERIR CLIENTE  
OPÇÃO 2 - EXIBIR LISTA COMPLETA  
OPÇÃO 3 - EXIBIR CLIENTE  
OPÇÃO 4 - BUSCAR CLIENTE POR NOME  
OPÇÃO 5 - EDITAR CLIENTE  
OPÇÃO 6 - REMOVER CLIENTE  
OPÇÃO 7 - SALVAR E SAIR  
```

3. **Preencha as informações solicitadas com atenção para evitar erros.**  
4. **Não esqueça de salvar os dados antes de sair!**

---

## 💡 **Dicas Importantes**
- Utilize nomes únicos para clientes para facilitar buscas e edições.  
- Sempre utilize a opção "Salvar" antes de sair para evitar perda de dados.  
- Utilize IDs consecutivos para manter a ordenação e facilitar o gerenciamento.  

---
