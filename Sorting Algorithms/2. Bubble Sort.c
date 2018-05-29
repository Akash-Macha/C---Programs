//Bubble Sort
#include <stdio.h>
void bubbleSort(int *A,int n);
void swap(int* a, int* b);

void main(){
	int n,a[100],i;
	printf("Enter number of numbers to Sort : ");
	scanf("%d",&n);
	printf("Enter numbers : \n");
	for(i=0;i<n;++i)
		scanf("%d",&a[i]);
	bubbleSort(a,n);
	printf("After sorting :\n");
	for(i=0;i<n;++i)
		printf("%d  ",a[i]);
		getch();
}

void bubbleSort(int *A,int n){
	int k,i,temp;
	for( k = 1 ; k <= n-1 ; ++k){			// No of passes
		for(i = 0 ; i <= n-k-1 ; ++i){	 // Comparing starting to other
			if(A[i] > A[i+1]){				//than sorted section
				swap(&A[i],&A[i+1]);
			}
		}
	}
}
void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}				
