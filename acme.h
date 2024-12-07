typedef struct cliente{
    int ID;
    char nomeCliente[80];
    char nomeEmpresa[80];
    char departamento[80];
    char telefoneFixo[80];
    char telefoneCelular[80];
    char email[80];
} CLIENTE;

typedef struct elemento* Lista;


Lista *criaLista();

void abortaPrograma();

// Verificadores

int tamanhoLista(Lista *li);

int listaCheia(Lista *li);

int listaVazia(Lista *li);

// 1 - Inserir Contato

int insereOrdenado(Lista *li, CLIENTE cl);

// 2 - Consultar Lista Completa

// --- foo

// 3 - Consultar por ID

int consultaID(Lista *li, int ID, CLIENTE *cl);

// 4 - Consultar por Nome

// --- foo

// 5 - Editar contato por ID

// --- foo

// 6 - Remover Contato por ID

int removeOrdenado(Lista *li , int ID);

// 7- Salvar dados e Fechar programa

void apagaLista(Lista *li);
