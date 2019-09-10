#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int *array;
    int size;
    int used;
} darray;

void alloc_array(darray *a, int init_size){
    a->array = (int *) malloc(init_size*sizeof(int));
    a->size = init_size;
    a->used = 0;
}

void add_front(darray *a, int elem){
    if (a->used == a->size)
    {
        a->size += 1;
        a->array = (int *) realloc(a->array, (a->size)*sizeof(int));
    }
    a->array[a->used] = elem;
    a->used += 1;
}

void add_back(darray *a, int elem){
    darray tmp;
    alloc_array(&tmp, (a->used)+1);

    for (size_t i = 0; i < a->used; i++)
    {
        tmp.array[i+1] = a->array[i];
    }

    tmp.array[0] = elem;
    a->array = tmp.array;
}

void pop_front(darray *a){  
    darray tmp;
    alloc_array(&tmp, (a->used)-1);

    for (int i = 0; i < (a->used)-1; i++)
    {
        add_front(&tmp, a->array[i]);
    }

    a->size = tmp.size;
    a->used = tmp.used;
    free(a->array);
    a->array = tmp.array;    
}

void pop_back(darray *a){
    darray tmp;
    alloc_array(&tmp, (a->used)-1);

    for (int i = 1; i < (a->used); i++)
    {
        add_front(&tmp, a->array[i]);
    }
    a->size = tmp.size;
    a->used = tmp.used;
    free(a->array);
    a->array = tmp.array;
}

int main() {
    int n;
    darray lista;
    scanf("%d", &n);
    alloc_array(&lista, n);

    for (size_t i = 0; i < n; i++)
    {   
        add_front(&lista, i);
        printf("%d", lista.array[i]);
    }
    puts("");

    add_front(&lista, n);
    
    for (size_t i = 0; i < lista.used; i++)
    {
        printf("%d", lista.array[i]);
    }
    puts("");

    pop_front(&lista);
    pop_front(&lista);
    pop_front(&lista);

    for (size_t i = 0; i < lista.used; i++)
    {
        printf("%d", lista.array[i]);
    }
    puts("");

    pop_back(&lista);

    for (size_t i = 0; i < lista.used; i++)
    {
        printf("%d", lista.array[i]);
    }
    puts("");

    add_back(&lista, n*4);

    for (size_t i = 0; i < lista.used; i++)
    {
        printf("%d", lista.array[i]);
    }
    puts("");

    return 0;
}