#include "stdio.h"

void insertion(int *list, int n){
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
    int n, l[1010];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &l[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", l[i]);
    }
    puts("");

    insertion(l, n);
    // selection(l, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", l[i]);
    }

    puts("");
    return 0;
}