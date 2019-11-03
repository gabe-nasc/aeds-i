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

void insert_A(struct nodeA *head, int data){
    if (head->data > data)
    {
        if (head->menor == NULL)
        {
            head->menor = allocA(data);
            head->menor->pai = head;
            return;
        }
        
        insert_A(head->menor, data);
    }
    else
    {
        if (head->maior == NULL)
        {
            head->maior = allocA(data);
            head->maior->pai = head;
            return;
        }
        insert_A(head->maior, data);
    }
}

int main(int argc, char const *argv[])
{
    return 0;
}
