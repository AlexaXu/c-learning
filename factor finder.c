#include <stdio.h>

int main()
{
	int i, n, a = 0;
	
	printf("enter a number: ");
	scanf("%d", &n);
	
	if(n <= 3){
		printf("%d is prime\n", n);
	}
	else {
		for(i = 2; i < n; i++)
			if(n % i != 0)
			continue;
			else {
				printf("%d is dicisible by %d\n", n, i);
				a++;
			}
	if(a > 0){
		printf("%d has %d factors\n", n, a);
	}
	else {
		printf("%d is prime\n", n);
	}
	}
	return 0;
}