#include<stdio.h>
#define SIZE 10  // total number of numbers 0 - 9 !
 
void bucketSort(int* A, int n) {
    int i, j, k, buckets[SIZE];
    
    //Intialize all buckets to 0
    for(i = 0; i < SIZE; ++i)
        buckets[i] = 0;
    //Increment the number of times each element is present in the input array.
  // Insert them in the buckets
    for(i = 0; i < n ; ++i)
        ++buckets[ A[i] ] ;
    
    //Sort using insertion sort and concatenate 
    i = 0 ; // index i = 0
    for( j = 0; j < SIZE ; ++j)
        for(k = buckets[ j ] ; k > 0 ; --k )
            A [ i++ ] = j ;  // i  does not effect the arrya. it gets incremented after performing A [ i ]
}
 
int main() {
    int i, a[] = {3, 6, 5, 1, 8, 4, 3, 1,0,9,4,6}, n = 12;
    
    printf("Before sorting:\n");
    for(i = 0; i < n; ++i)
        printf("%d ", a[i]);
    
    bucketSort(a, n);
    
    printf("\n\nAfter sorting:\n");
    for(i = 0; i < n; ++i)
        printf("%d ", a[i]);
    getch();
    return 0;
}
