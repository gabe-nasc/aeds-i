#include <stdio.h>

int part(int *array, int esq, int dir){
    int i = esq, j = dir;

    int pivot = array[(esq+dir)/2];

    while(i < j)
    {
        while(array[i] < pivot)
        {
            i += 1;
        }

        while(array[j] > pivot)
        {
            j -= 1;
        }

        if (i < j)
        {
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
        else
        {
            break;
        }
    }
    return j;
}

int quick(int *array, int esq, int dir){
    if (esq < dir)
    {
        int pivot = part(array, esq, dir);
        quick(array, esq, pivot);
        quick(array, pivot+1, dir);
    }
}

int main(){
    int n, v[1010];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    quick(v, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    puts("");

    return 0;
}