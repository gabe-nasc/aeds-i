#include "stdio.h"

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

    selection(l, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", l[i]);
    }

    puts("");
    return 0;
}