/** 
 * @file
 * @brief Header de funções do Social-BST
*/

/**
 * @brief Node A, utilizado na BST principal que guarda as informações sobre cada pessoa
*/
struct nodeA {
    int data; /**< Valor do node*/
    char nome[101]; /**< Nome da pessoa*/
    struct nodeA *pai; /**< Ponteiro para o node diretamente acima (pai)*/
    struct nodeA *menor; /**< Ponteiro para o node menor*/
    struct nodeA *maior; /**< Ponteiro para o node maior*/
    struct nodeB *amgs; /**< Ponteiro para um NodeB que é cabeça da arvore de amizades*/
};

/** 
 * @brief Node B, utilizado nas BSTs que guardam as amizades de cada pessoa 
*/
struct nodeB {
    int data; /**< Valor do node*/
    struct nodeB *pai; /**< Ponteiro para o node diretamente acima (pai)*/
    struct nodeB *menor; /**< Ponteiro para o node menor*/
    struct nodeB *maior; /**< Ponteiro para o node maior*/
};

/**
 * \brief Função auxiliar que alloca em memoria um espaço para um Node A
 * @param data Valor do node
 * @param nome Nome associado ao node
 * @return Ponteiro para o novo nó
*/
struct nodeA* allocA(int data, char *nome){
    struct nodeA *new = (struct nodeA *) malloc(sizeof(struct nodeA));
    
    strcpy(new->nome, nome);
    new->data = data;

    new->maior = NULL;
    new->menor = NULL;
    new->amgs = NULL;
    new->pai = NULL;

    return new;
}
/**
 * \brief Função auxiliar que alloca em memoria um espaço para um Node B
 * @param data Valor do node
 * @return Ponteiro para o novo nó
*/
struct nodeB* allocB(int data){
    struct nodeB *new = (struct nodeB *) malloc(sizeof(struct nodeB));
    new->data = data;
    new->pai = NULL;
    new->maior = NULL;
    new->menor = NULL;

    return new;
}
/**
 * \brief Função que busca em uma BST do tipo A um determinado node pelo seu valor
 * @param head Ponteiro para um nó inicial de tipo A que será percorrido
 * @param data Valor do nó que deve ser buscado
 * @return Ponteiro para o nó buscado caso dê certo, caso contrário será NULL
*/
struct nodeA* find(struct nodeA* head, int data)
{

    if (head == NULL || head->data == data)
    {
       return head;
     }

    if (head->data < data)
    {
       return find(head->maior, data);
    }

    return find(head->menor, data);
}

/**
 * \brief Função que busca em uma BST do tipo B um determinado node pelo seu valor
 * @param head Ponteiro para um nó inicial de tipo B que será percorrido
 * @param data Valor do nó que deve ser buscado
 * @return Ponteiro para o nó buscado caso dê certo, caso contrário será NULL
*/
struct nodeB* findB(struct nodeB* head, int data)
{

    if (head == NULL || head->data == data)
    {
       return head;
     }

    if (head->data < data)
    {
       return findB(head->maior, data);
    }

    return findB(head->menor, data);
}

/**
 * \brief Função que dada uma BST do tipo A, insere um novo nó no local apropriado
 * @param head Ponteiro para o nó de tipo A a partir do qual o novo nó será inserido
 * @param data Valor do nó a ser inserido
 * @param nome Nome da pessoa a ser cadastrada
*/
void insertA(struct nodeA *head, int data, char *nome){
    if (head->data > data)
    {
        if (head->menor == NULL)
        {
            head->menor = allocA(data, nome);
            head->menor->pai = head;
            return;
        }
;
        insertA(head->menor, data, nome);
    }
    else
    {
        if (head->maior == NULL)
        {
            head->maior = allocA(data, nome);
            head->maior->pai = head;
            return;
        }
        insertA(head->maior, data, nome);
    }
}
/**
 * \brief Função auxiliar à insertB, faz um trabalho similar a insertA
 * @param head Ponteiro para o nó de tipo A a partir do qual o novo nó será inserido
 * @param data Valor do nó a ser inserido 
*/
void insertB_aux(struct nodeB *head, int data){
    if (head->data > data)
    {
        if (head->menor == NULL)
        {
            head->menor = allocB(data);
            head->menor->pai = head;
            return;
        }
;
        insertB_aux(head->menor, data);
    }
    else
    {
        if (head->maior == NULL)
        {
            head->maior = allocB(data);
            head->maior->pai = head;
            return;
        }
        insertB_aux(head->maior, data);
    }
}
/**
 * \brief Função que dada uma BST do tipo A, cria uma conexão entre dois de seus nós inserindo um novo nó em suas BSTs de tipo B
 * @param head Ponteiro para o inicio da arvore a qual 
 * @param p1 Valor do nó de tipo A (1)
 * @param p2 Valor do nó de tipo A (2)
*/
void insertB(struct nodeA *head, int p1, int p2){
    struct nodeA *ptr1 = find(head, p1);
    struct nodeA *ptr2 = find(head, p2);
    
    if (ptr1->amgs == NULL)
    {
        ptr1->amgs = allocB(p2);
    }
    else
    {
        insertB_aux(ptr1->amgs, p2);
    }
    

    if (ptr2->amgs == NULL)
    {
        ptr2->amgs = allocB(p1);
    }
    else
    {
        insertB_aux(ptr2->amgs, p1);
    }
    
}
/**
 * \brief Função que verifica se dois nó de tipo A possuem conexão através de seus nós de tipo B
 * @param p1 Pessoa 1
 * @param p2 Pessoa 2
 * @return 1 caso exista a conexão, 0 caso contrário
*/
int consulta_amizade(struct nodeA *head, int a, int b){
    struct nodeA *p1 = find(head, a);

    if (findB(p1->amgs, b) != NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }    
}
/**
 * \brief Função que imprime no terminal os id's de uma BST do tipo A em ordem crescente
 * @param head Ponteiro para a cabeça da BST do tipo A
*/
void print_ordemA(struct nodeA *head)
{
    if (head != NULL)
    {
        print_ordemA(head->menor);
        printf("%d %s\n", head->data, head->nome);
        print_ordemA(head->maior);
    }
}

/**
 * \brief Função que imprime no terminal os id's de uma BST do tipo B em ordem crescente
 * @param head Ponteiro para a cabeça da BST do tipo B
*/
void print_ordemB(struct nodeB *head)
{
    if (head != NULL)
    {
        print_ordemB(head->menor);
        printf("%d ", head->data);
        print_ordemB(head->maior);
    }
}

/**
 * \brief Função que busca um nó e imprime todos os seus dados
 * @param head Ponteiro para o nó cabeça da BST em que este nó está inserido
 * @param data Valor do nó a ser mostrado
*/
void info(struct nodeA *head, int data){
    struct nodeA *ptr = find(head, data);
    printf("%s\nID: %d\nAmizades: ", ptr->nome, ptr->data);
    print_ordemB(ptr->amgs);
    puts("");
}


/**
 * \brief Função que deleta um nó de uma BST de tipo B
 * @param head Ponteiro para o nó cabeça da BST
 * @param data Valor do nó a ser deletado
 * @return Ponteiro para o nó cabeça da BST modificada
*/
struct nodeB *deleteB(struct nodeB *head, int data){
    if (head == NULL){
        return head;
    } 

    if (data < head->data){
        head->menor = deleteB(head->menor, data); 
    }

    else if (data > head->data){
        head->maior = deleteB(head->maior, data); 
    }

    else
    { 
        if (head->menor == NULL) 
        { 
            struct nodeB *tmp = head->maior; 
            free(head); 
            return tmp; 
        } 
        
        else if (head->maior == NULL) 
        { 
            struct nodeB *tmp = head->menor; 
            free(head); 
            return tmp; 
        } 

        struct nodeB *tmp;
        tmp = head->maior;
        while(tmp != NULL && tmp->menor != NULL){
            tmp = tmp->menor;
        }

        head->data = tmp->data;
        head->maior = deleteB(head->maior, tmp->data); 
    } 
    return head;
}

/**
 * \brief Função que deleta um nó de uma BST de tipo A
 * @param head Ponteiro para o nó cabeça da BST
 * @param data Valor do nó a ser deletado
 * @return Ponteiro para o nó cabeça da BST modificada
*/
struct nodeA *deleteA(struct nodeA *head, int data){
    if (head == NULL){
        return head;
    } 

    if (data < head->data){
        head->menor = deleteA(head->menor, data); 
    }

    else if (data > head->data){
        head->maior = deleteA(head->maior, data); 
    }

    else
    { 
        if (head->menor == NULL) 
        { 
            struct nodeA *tmp = head->maior; 
            free(head); 
            return tmp; 
        } 
        
        else if (head->maior == NULL) 
        { 
            struct nodeA *tmp = head->menor; 
            free(head); 
            return tmp; 
        } 

        struct nodeA *tmp;
        tmp = head->maior;
        while(tmp != NULL && tmp->menor != NULL){
            tmp = tmp->menor;
        }

        head->data = tmp->data;
        head->amgs = tmp->amgs;
        head->maior = deleteA(head->maior, tmp->data); 
    } 
    return head;
}
/**
 * \brief Função que deleta um nó de todas as BSTs de Amizades de todos os nós de uma BST de tipo A
 * @param head Ponteiro para o nó cabeça da BST de tipo A
 * @param data Valor do nó a ser deletado
*/
void deleteAmgs(struct nodeA *head, int data){
    if (head != NULL)
    {
        head->amgs = deleteB(head->amgs, data);
        deleteAmgs(head->menor, data);
        deleteAmgs(head->maior, data);
    }
}

int dfs(int **matriz, int *marca, int inicio, int tam) {
	marca[inicio] = 1;
	for (int i = 1; i <= tam; i++){
	    if(matriz[inicio][i] && !marca[i]) {
		    printf("\n %d->%d",v,i);
		    int x = dfs(matriz, marca, i, tam);
	    }
    }
}