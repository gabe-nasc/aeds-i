#include <stdio.h>
#include <stdlib.h>

struct nodeA {
    int data;
    struct nodeA *pai;
    struct nodeA *menor;
    struct nodeA *maior;
    struct nodeB *amgs;
};

struct nodeB {
    int data;
    struct nodeB *pai;
    struct nodeB *menor;
    struct nodeB *maior;
};

struct nodeA* allocA(int data){
    struct nodeA *new = (struct nodeA *) malloc(sizeof(struct nodeA));
    new->data = data;
    new->pai = NULL;
    new->maior = NULL;
    new->menor = NULL;
    new->amgs = NULL;

    return new;
}

struct nodeB* allocB(int data){
    struct nodeB *new = (struct nodeB *) malloc(sizeof(struct nodeB));
    new->data = data;
    new->pai = NULL;
    new->maior = NULL;
    new->menor = NULL;

    return new;
}

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

void insertA(struct nodeA *head, int data){
    if (head->data > data)
    {
        if (head->menor == NULL)
        {
            head->menor = allocA(data);
            head->menor->pai = head;
            return;
        }
;
        insertA(head->menor, data);
    }
    else
    {
        if (head->maior == NULL)
        {
            head->maior = allocA(data);
            head->maior->pai = head;
            return;
        }
        insertA(head->maior, data);
    }
}

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

void print_ordem(struct nodeA *head)
{
    if (head != NULL)
    {
        print_ordem(head->menor);
        printf("%d ", head->data);
        print_ordem(head->maior);
    }
}

int main(int argc, char const *argv[])
{
    return 0;
}