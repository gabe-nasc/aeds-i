#include <stdio.h>
#include <stdlib.h>

void add_top(int **array, int n){
    size_t size = sizeof(array)/sizeof(int);
    *array = realloc(*array, (size+1)*sizeof(int));
    puts("not yet");
    array[size+1] = n;
    puts("gallahad");
}

int main() {
    int n;

    // scanf("%d", &n);

    int *lista = malloc(4*sizeof(int));

    for (size_t i = 0; i < 4; i++)
    {   
        lista[i] = i;
        printf("%d", lista[i]);
    }
    puts("");

    add_top(&lista, 5);
    for (size_t i = 0; i < 5; i++)
    {
        printf("%d", lista[i]);
    }
    puts("");
    return 0;
}