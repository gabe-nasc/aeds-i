#include <stdio.h>
#include <stdlib.h>

// struct Node
// {
//     int data;
//     struct node *next;
// };

// typedef struct Node *node;

typedef struct Node
{
    int data;
    struct node *next;
} * node;

// Starts a new node
node create_node()
{
    node new;
    new = (node)malloc(sizeof(struct Node));
    new->next = NULL;
    return new;
}

// Add a new node to the list
node add_node(node head, int value)
{
    node tmp, p;
    tmp = create_node();

    tmp->data = value;
    if (head == NULL)
    {
        head = tmp;
    }
    else
    {
        p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = tmp;
    }
    return head;
}

int find(node head, int value)
{
    node tmp;
    tmp = head;
    for (int i = 0;; i++)
    {
        if (tmp->data == value)
        {
            return i;
        }

        if (tmp->next == NULL)
        {
            break;
        }

        tmp = tmp->next;
    }
    return -1;
}

node add_node_start(node head, int data)
{
    node new, tmp = head;

    new = create_node();
    new->next = tmp;
    new->data = data;

    return new;
}

node remove_node(node head)
{
    node prox, tmp = head;
    for (int i = 0;; i++)
    {
        prox = tmp->next;
        if (prox->next == NULL)
        {
            free(prox);
            tmp->next = NULL;
            return head;
        }
        tmp = prox;
    }
}

node remove_node_start(node head)
{
    node prox, tmp = head;

    prox = tmp->next;
    free(tmp);

    return prox;
}

void print_ll(node head)
{
    node p = head;
    while (p->next != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("%d ", p->data);
    puts("");
}

node insert_ordered(node head, int n)
{
    node prox, tmp, new;
    tmp = head;
    if (tmp->data > n)
    {
        return add_node_start(head, n);
    }
    
    tmp = tmp->next;
    prox = tmp->next;
    while (1)
    {
        if (prox == NULL)
        {
            return add_node(head, n);
        }
        
        if (prox->data >= n)
        {
            new = create_node();
            new->data = n;
            new->next = prox;
            tmp->next = new;

            return head;
        }
        
        tmp = tmp->next;
        prox = tmp->next;
    }
}

node reverse_ll(node head)
{
    node agr, prox, ant;
    agr = head;

    ant = NULL;
    for (int i = 0;; i++)
    {
        prox = agr->next;

        agr->next = ant;

        if (prox == NULL)
        {
            return agr;
        }

        ant = agr;
        agr = prox;
    }
}

int main(int argc, char const *argv[])
{
    return 0;
}