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

void add_top(darray *a, int elem){
    if (a->used == a->size)
    {
        a->size += 1;
        a->array = (int *) realloc(a->array, (a->size)*sizeof(int));
    }
    a->array[a->used] = elem;
    a->used += 1;
}

void pop_top(darray *a){  
    darray tmp;
    alloc_array(&tmp, (a->used)-1);

    for (int i = 0; i < (a->used)-1; i++)
    {
        add_top(&tmp, a->array[i]);
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
        add_top(&lista, i);
        printf("%d", lista.array[i]);
    }
    puts("");

    add_top(&lista, n);
    
    for (size_t i = 0; i < lista.used; i++)
    {
        printf("%d", lista.array[i]);
    }
    pop_top(&lista);
    pop_top(&lista);
    pop_top(&lista);
    for (size_t i = 0; i < lista.used; i++)
    {
        printf("%d", lista.array[i]);
    }
    puts("");
    return 0;
}