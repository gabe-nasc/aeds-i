#include "stdio.h"
#include "string.h"

// Utility function to print arrays
void printa(char *array, int size){
    for (int i=0; i < size; i++){
        printf("%c", array[i]);
    }
    printf("\n"); 
}

// Insertion sort for characters, case sensitive
void insertion(char *list, int n){
    for (int i = 1; i < n; i++)
    {
        int j = i;
        int t = list[i]; // Current integer

        // Move integer to the right if it is smaller than current number
        while (j > 0 && list[j-1] > t)
        {
            list[j] = list[j-1];
            j = j-1;
        }
        list[j] = t;
    }
}

int main() {
    char c[1010];

    scanf("%s", c);
    int n = strlen(c);

    printa(c, n);

    insertion(c, n);

    printa(c, n);
    return 0;
}