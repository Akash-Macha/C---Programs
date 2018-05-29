//Selection Sorting
#include <stdio.h>
int selectionSort(int *A,int n);
void swap(int* a, int* b);
void main()
{
	int a[100],n,i;
	printf("Enter number of elements to sort : ");
	scanf("%d",&n);
	printf("Enter raw data :\n");
	for(i=0;i<n;++i)
		scanf("%d",&a[i]);
	selectionSort(a,n);
	printf("After sorting :\n");
	for(i=0;i<n;++i)
		printf("%d  ",a[i]);
		getch();
}

int selectionSort(int *A,int n){
	int i,j,min;
	for(i=0 ; i < n-1 ; ++i)
	{
		min = i;
		for(j = i+1 ; j < n ; ++j)
		{
			if(A[j] < A[min])
			{
				min = j;
			}
		}
		swap(&A[i], &A[min]);
	}
}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
