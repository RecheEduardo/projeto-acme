// Eduardo Reche Martins - GU3054209
// Diego Rocha Vitali - GU3053873

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

void exibeMenu();

void exibirDadosCliente(CLIENTE *cl);


// Verificadores
int tamanhoLista(Lista *li);

int listaCheia(Lista *li);

int listaVazia(Lista *li);


// Coleta dados do cliente
CLIENTE coletaDados();
int carregarDados(FILE *f, Lista *li);


// 1 - Inserir Cliente
int insereOrdenado(Lista *li, CLIENTE cl);

// 2 - Consultar Lista Completa
void exibirListaCompleta(Lista *li);

// 3 - Consultar por ID
int consultaID(Lista *li, int ID, CLIENTE *cl);

// 4 - Consultar por Nome
int consultaNome(Lista *li, char nome[80]);

// 5 - Editar cliente por ID
int editarCliente(Lista *li, int ID);

// 6 - Remover cliente por ID
int removeOrdenado(Lista *li , int ID);

// 7- Salvar dados e Fechar programa
int salvarClientes(FILE *f, Lista *li);
void apagaLista(Lista *li);
