#include <stdio.h>

int heaper(int *array, int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && array[left] > array[largest])
    {
        largest = left;
    }

    if (right < n && array[right] > array[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        int tmp = array[i];
        array[i] = array[largest];
        array[largest] = tmp;

        heaper(array, n, largest);
    }
}

void sorter(int *array, int n){
    for (int i = n/2 - 1; i >= 0; i--)
    {
        heaper(array, n, i);
    }

    for (int i = n-1; i >= 0; i--)
    {
        int tmp = array[i];
        array[i] = array[0];
        array[0] = tmp;

        heaper(array, i, 0);
    }
}

int main() {
    int n, nums[1010];

    scanf("%d", &n);

    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    
    sorter(nums, n);

    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }
    puts("");

    return 0;
}