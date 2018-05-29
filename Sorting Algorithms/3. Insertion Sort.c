// Insertion Sort
#include <stdio.h>
void insertionSort(int *A,int n);
void main(){
	int n,i,a[50];
	printf("ENter the number of elements : ");
	scanf("%d",&n);
	printf("Etner the elements : \n");
	for(i=0;i<n;++i)
		scanf("%d",&a[i]);
	insertionSort(a,n);
	printf("After sorting :\n");
	for(i=0;i<n;++i)
		printf("%d  ",a[i]);
		getch();
}
void insertionSort(int *A,int n){
	int i, temp, position;
	for(i=1 ; i<= n-1 ; ++i){
		position = i;
		temp = A[i];
		while( position > 0 && A[position-1] > temp){
			A[position] = A[position-1];
			position--;
		}
		A[position] = temp;
	}
}
