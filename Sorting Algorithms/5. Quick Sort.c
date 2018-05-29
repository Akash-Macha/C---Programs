// QUICK_SORT
#include<stdio.h>
void swap(int* a, int* b);
void quick_sort(int* A,int low, int high);
int partition( int* A, int low, int high);

int main(){
	int a[100],arr_size,i;
	
	printf("How many elements : ");
	scanf("%d",&arr_size);
	
	printf("\nEnter raw data : \n");
	
	for(i=0;i<arr_size;++i)
		scanf("%d",&a[i]);
		
		quick_sort( a , 0 , arr_size-1 );  //*******
		
		printf("\nSorted Order : \n");
		for(i=0;i<arr_size;++i)
			printf("%d  ",a[i]);
			return 0;
}

void quick_sort(int* A,int low, int high)
{
	if(low < high){
		
		int pI = partition( A, low, high);
		
		quick_sort( A , low , pI - 1 );
		quick_sort(A , pI + 1 , high);
	}
}

int partition( int* A, int low, int high){
	
	int j;
	int pivot = A[high] ;
	int i = (low - 1) ;    //**********
	
	for( j = low ; j <= high - 1 ; ++j )
	{
		if( A[j] <= pivot ){
			++i;
			swap( &A[i] , &A[j] );
		}
	}
	
	swap( &A[ i + 1 ] , &A[ high ] );
	
	return (i + 1);
}
void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}
