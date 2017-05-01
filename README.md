# c-learning

#include <stdio.h>

#define N 10

void quick_sort(int [], int, int);
int sort_middle(int [], int, int);

int main()
{
	int a[N], i;
	
	printf("Enter %d numbers: ", N);
	for(i = 0; i < N; i++){
		scanf(" %d", &a[i]);
	}
	
	quick_sort(a, 0, N - 1);
	
	printf("In sorted order:\n");
	for(i = 0; i < N; i++){
		printf("%d\t", a[i]);
		if((i % 4) == 3){
			printf("\n");
		}
	}
	
	return 0;
}

void quick_sort(int a[], int low, int high)
{
	int middle;
	
	if(low >= high){
		return;
	}
	
	middle = sort_middle(a, low, high);
	
	quick_sort(a, low, middle);
	quick_sort(a, middle + 1, high);
}

int sort_middle(int a[], int low, int high)
{
	int middle = a[low];
	
	for(;;){
		while(low < high && middle <= a[high]){
			high--;
		}
		if(low >= high) break;
		a[low] = a[high];
		low++;
		
		while(low < high && a[low] <= middle){
			low++;
		}
		if(low >= high) break;
		a[high] = a[low];
		high--;
	}
	
	a[high] = middle;
	return high;
}
