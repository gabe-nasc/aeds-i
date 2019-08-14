#include "stdio.h"
#include "string.h"

int memo[1010];

int fib(int n){
	if(n == 1){
			return 0;
	}

	if(n == 2){
			return 1;
	}

	if(memo[n] != -1){
		return memo[n];
	}

	return fib(n-1)+fib(n-2);

}

int main(int argc, char const *argv[])
{	
	int n;

	memset(memo, -1, sizeof(memo));

	scanf("%d", &n);
	printf("%d\n", fib(n));
	
	return 0;
}