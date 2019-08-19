#include <stdlib.h>
#include <stdio.h>

void printa(int *array, int size){
    for (int i=0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void merge(int *array, int l, int m, int r)
{
    int nr = r - m;
    int nl = m - l + 1;

    int i, j, k, right[nr], left[nl];

    for (i = 0; i < nl; ++i)
    {
        left[i] = array[l+i];
    }

    for (j = 0; j < nr; ++j)
    {
        right[j] = array[m+1+j];
    }

    i = 0;
    j = 0;
    k = l;

    while(i < nl && j < nr)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < nl)
    {
        array[k] = left[i];
        i++;
        k++;
    }

    while(j < nr)
    {
        array[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int *array, int left, int right)
{
    if (left < right)
    {
        int m = left+(right-left)/2;

        merge_sort(array, left, m);
        merge_sort(array, m+1, right);

        merge(array, left, m, right);
    }
}

int main(int argc, char const *argv[])
{
    int n, nums[1010];

    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &nums[i]);
    }

    printa(nums, n);

    merge_sort(nums, 0, n-1);

    printa(nums, n);



    return 0;
}