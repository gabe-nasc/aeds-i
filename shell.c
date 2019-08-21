#include <stdio.h>

int shell(int *array, int n){
    for (int step = n/2; step > 0; step /= 2)
    {
        for (int i = step; i < n; i += 1){
            int tmp = array[i];

            int j;
            for (j = i; j >= step && array[j-step] > tmp; j-= step){
                array[j] = array[j-step];
            }
            array[j] = tmp;
        }
    }
    return 0;
}

int main() {
    int l[1010], n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &l[i]);
    }

    shell(l, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", l[i]);
    }

    puts("");

    return 0;
}