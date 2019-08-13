#include "stdio.h"

int bsearch_iter(int target, int *list, int n){
    int lo = 0;
    int hi = n-1;

    while (lo <= hi)
    {
        int mid = (lo+hi)/2;
        if (list[mid] == target)
        {
            return mid;
        }

        else if (target > mid)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }

    return -1;
}

int bsearch_rec (int target, int *list, int start, int end){
    int mid = (start+end)/2;
    
    if (list[mid] == target)
    {
        return mid;
    }

    else if (target > mid)
    {
        start = mid;
    }
    else
    {
        end = mid;
    }

    return bsearch_rec(target, list, start, end);
}


int main() {
    int t, l[1010], n;
    
    scanf("%d", &t);
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &l[i]);
    }
    
    printf("%d\n", bsearch_iter(t, l, n));
    printf("%d\n", bsearch_rec(t, l, 0, n));

    return 0;
}