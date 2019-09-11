#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct node *next;
};

typedef struct Node *node;

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
    for (int i = 0; tmp->next != NULL; i++)
    {
        if (tmp->data == value)
        {
            return i;
        }

        tmp = tmp->next;
    }
    return -1;
}

void print_ll(node head)
{
    node p = head;
    while (p->next != NULL)
    {
        p = p->next;
        printf("%d\n", p->data);
    }
}

int main(int argc, char const *argv[])
{
    return 0;
}
