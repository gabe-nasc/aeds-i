#include "stdio.h"

// Utility function to print arrays
void printa(int *array, int size){
    for (int i=0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n"); 
}

// Selection sort for Integers
void selection(int *list, int sz){
    for (int i = 0; i < sz-1; i++)
    {
        int mini = i;
        for (int j = i+1; j < sz; j++)
        {
            if (list[j] < list[mini])
            {
                mini = j;
            }
        }

        int aux;

        aux = list[i];
        list[i] = list[mini];
        list[mini] = aux;
    }
}

int main() {
    int c[1010], i, n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &c[i]);
    }
    
    printa(c, n);

    selection(c, n);

    printa(c, n);
    return 0;
}