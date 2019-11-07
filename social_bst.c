#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Node A, utilizado na BST principal que guarda as informações sobre cada pessoa
struct nodeA {
    int data;
    char nome[101];
    struct nodeA *pai;
    struct nodeA *menor;
    struct nodeA *maior;
    struct nodeB *amgs;
};

// Node B, utilizado nas BST's que guardam as amizades de cada pessoa
struct nodeB {
    int data;
    struct nodeB *pai;
    struct nodeB *menor;
    struct nodeB *maior;
};

// Função auxiliar que alloca em memoria um espaço para um Node A
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

// Função auxiliar que alloca em memoria um espaço para um Node B
struct nodeB* allocB(int data){
    struct nodeB *new = (struct nodeB *) malloc(sizeof(struct nodeB));
    new->data = data;
    new->pai = NULL;
    new->maior = NULL;
    new->menor = NULL;

    return new;
}

// Função que busca em uma BST do tipo A um determinado node pelo seu valor
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

// Função que busca em uma BST do tipo B um determinado node pelo seu valor
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

// Função que dada uma BST do tipo A, insere um novo node no local apropriado
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

// Função auxiliar à insertB, faz um trabalho similar a insertA
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

// Função que dada uma BST do tipo B, insere um novo node no local apropriado
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

// Função que verifica se duas pessoas possuem uma amizade
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

// Função que imprime no terminal os id's de uma BST do tipo A em ordem crescente
void print_ordemA(struct nodeA *head)
{
    if (head != NULL)
    {
        print_ordemA(head->menor);
        printf("%d %s\n", head->data, head->nome);
        print_ordemA(head->maior);
    }
}

// Função que imprime no terminal os id's de uma BST do tipo B em ordem crescente
void print_ordemB(struct nodeB *head)
{
    if (head != NULL)
    {
        print_ordemB(head->menor);
        printf("%d ", head->data);
        print_ordemB(head->maior);
    }
}

// Função que busca uma pessoa e imprime todos os seus dados
void info(struct nodeA *head, int data){
    struct nodeA *ptr = find(head, data);
    printf("%s\nID: %d\nAmizades: ", ptr->nome, ptr->data);
    print_ordemB(ptr->amgs);
    puts("");
}

int main(int argc, char const *argv[])
{
    struct nodeA *head; // Cabeça da BST principal
    int count = 1; // Contador de pessoas
    char cmd[120]; // Comando inserido pelo usuário

    while (1)
    {
        printf(">> ");
        scanf("%[^\n]%*c", cmd);
        puts("");

        // Imprime a lista de comandos suportados
        if (!strcmp(cmd, "help"))
        {
            puts("help - mostra ajuda com comandos");
            puts("new x - adiciona uma nova pessoa (x) na rede");
            puts("bsc x - busca as informações de x");
            puts("nfd x y - adicionar uma nova amizade entre (x) e (y)");
            puts("chk x y - checar se existe amizade entre (x) e (y)");
            puts("prt - imprime todas as pessoas na rede");
        }
        //
        else if (!strncmp(cmd, "new", 3))
        {
            if (head == NULL)
            {
                head = allocA(count, cmd+4);
            }
            else
            {
                insertA(head, count, cmd+4);
            }
            count += 1;
        }
        else if (!strncmp(cmd, "nfd", 3))
        {
            int p1, p2;
            sscanf(cmd, "%*s %d %d", &p1, &p2);
            insertB(head, p1, p2);
        }
        else if (!strncmp(cmd, "chk", 3))
        {
            int p1, p2;
            sscanf(cmd, "%*s %d %d", &p1, &p2);
            printf("%d\n", consulta_amizade(head, p1, p2));
        }
        else if (!strncmp(cmd, "prt", 3))
        {
            print_ordemA(head);
            puts("");
        }
        else if (!strncmp(cmd, "bsc", 3))
        {

            int p1;
            sscanf(cmd, "%*s %d", &p1);
            info(head, p1);
        }
        else if (!strcmp(cmd, "quit"))
        {
            break;
        }
        
    }

    return 0;
}