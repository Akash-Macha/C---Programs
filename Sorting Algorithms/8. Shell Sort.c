// Shell Sort -- by insertion sort!
#include<stdio.h>
void shell_sort(int* A , int n)
{
	int gap , i ,j , temp ;
	
	for(gap = n/2 ; gap > 0 ; gap = gap / 2 )
	{
		for( i = gap ; i < n ; ++i ) // ++i moving to wards right
		{
				// insertition Sort
				temp = A[ i ] ;
				
				j = i;
				for( ; j >= gap && A[ j - gap] > temp   ;   j -= gap)
					A[ j ] = A[ j - gap ] ;
				
				A[ j ] = temp ;
				
		}
	}
}

void main(){
	int a[10], n , i ;
	printf("Enter number of elements to sort :  ");
	scanf("%d", &n);
	printf("Enter raw data : \n");
	for(i= 0 ; i < n ; ++i)
		scanf("%d", &a[i]);
		
	shell_sort( a , n ) ;
	
	printf("After sorting :\n");
	for(i = 0 ; i < n ; ++i)
		printf("%d  ",a[i]);
}
