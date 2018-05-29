//Merge Sort
#include<stdio.h>
void merge(int *A, int low, int mid, int high){
	int i,j,k;
	int nL = mid - low + 1 ; //Number of terms in left
	int nR = high - mid;	// Number of terms in right
	
	int left[nL], right[nR];
	
	for(i = 0 ; i < nL ; ++i)
		left[i] = A[ low + i ] ;
		
	for(j=0; j < nR ; ++j)
		right[j] = A [ mid + 1 + j ] ;
		
	i = 0 ;
	j = 0 ;
	k = low ;
	
	while(i < nL && j < nR)
	{
		if( left [ i ] <= right [ j ] )
		{
			A [ k ] = left [ i ] ;
			++i ;
		}
		else{
			A[k] = right[j];
			++j;
		}
		++k ;
	}
	while(i < nL)
	{
		A[k] = left[i]; 
		++i;
		++k;
	}
	while(j < nR)
	{
		A[k] = right[j];
		++j;
		++k;
	}
}

int merge_sort(int *A,int low, int high)
{
	// divide the array till size becomes one 
	if( low < high )
	{
		int mid = (low+high)/2;
		
		merge_sort( A , low , mid );
		merge_sort( A , mid+1 , high );
		
		merge( A , low , mid , high );
	}
}

int main(){
	int a[100],arr_size,i;
	printf("Enter number of numbers to sort : ");
	scanf("%d",&arr_size);
	printf("Enter raw data : \n");
	for(i = 0 ; i < arr_size ; ++i)
		scanf("%d",&a[i]);
	
	merge_sort (a,0, arr_size -1) ;
	
	printf("\nSorted Order :\n");
	for(i = 0 ; i < arr_size ; ++i)
		printf("%d  ",a[i]);
	getch();
	return 0;
}
