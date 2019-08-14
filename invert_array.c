#include <stdio.h>

// O(n), assignemnt is made 3*n times.
void invert(int *list, int len){
	for (int i = 0, j = len-1; i < len-1; ++i, j--)
	{
		int tmp = list[i];
		list[i] = list[j];
		list[j] = tmp;
	}
}

void printa(int *array, int size){
    for (int i=0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n"); 
}

int main(int argc, char const *argv[])
{
	int array[1010], n;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &array[i]);
	}

	printa(array, n);
	invert(array, n);
	printa(array, n);

	return 0;
}