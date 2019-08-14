#include <stdio.h>


int merge(int *array, int m, int l, int r){
	int nr = r - m;
	int nl = m - l + 1

	int i, j, k, right[nr], left[nl];
	

	for (i = 0; i < nl; ++i)
	{
		left[i] = array[l+i];
	}

	for (i = 0; i < nr; ++i)
	{
		right[i] = array[m+l+j];
	}

	i, j, k = 0, 0, l;

	while(i < nl && j < nr){
		if (left[i] <= R[j])
		{
			array[k] = left[i];
			i++;
		}
		else{
			array[k] = right[j];
			j++;
		}
		k++
	}

	while(i < nl){
		array[k] = left[i];
		i++;
		k++;
	}

	while(j < nr){
		array[k] = right[i];
		i++;
		k++;
	}
}

int merge_sort(){

}

int main(int argc, char const *argv[])
{
	
	return 0;
}