//Heap Sort
#include<stdio.h>
void fillArr(int* A,int n){
	int i;
	for(i=0;i<n;++i)
		scanf("%d",&A[i]);
}
void printArr(int* A, int n){
	int i;
	for(i=0 ; i<n ;++i)
		printf("%d  ",A[i]);
}
void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void heapify(int* A, int array_size , int i){
	
	int largest = i;  // Intitialize the largest as root
	int left = 2*i + 1;  // Left = 2*i +1
	int right = 2*i + 2;  // Right = 2*i +2
	
	if( left < array_size  &&  A[left] > A[largest] )
		largest = left;  //Shifting the index
	
	if( right < array_size && A[right] > A[largest])
		largest = right;  //Shifting the index
	
	if(largest != i){
		swap(&A[i] , &A[largest]);
		
		//Recusivly heapify the affected sub Tree
		heapify( A , array_size , largest );
	}
}


void heap_sort(int* A, int array_size){			
	int i,j;
	
	
	//Creats Max heap  Only Once (reArranging array)
	for(i = ( array_size / 2 ) - 1 ; i >= 0 ; --i) 
		heapify( A , array_size , i );    
	
	
	
	for( j = array_size - 1 ; j >= 0 ; --j){
		//swaping root node and last node
		swap( &A[0], &A[j]);	//Swaps last and first node
		
		
		heapify( A , i , 0 );  //Creates max heap on reduced array!
	}
}
int main(){
	int a[50], array_size;
	printf("Enter no. of elemts to sort: ");
	scanf("%d" ,&array_size );
	printf("ENter raw data :\n");
	
	fillArr( a , array_size );
	
	heap_sort( a , array_size );
	
	printf("\nSorted order :\n");
	printArr( a , array_size );
	return 0;
}
