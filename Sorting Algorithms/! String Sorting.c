#include<stdio.h>

 char* sort(char* string,int n)
 {
     int i,j,temp,count=0;
     		// i<n-1 since j = i+1 will give the last element!
     for (i=0 ; i < n-1 ; i++)
     {
         for (j=i+1; j<n; j++)
         {
             if (string[i] > string[j])
             {
             	count++;
                 temp = string[i];
                 string[i] = string[j];
                 string[j] = temp;
             }
         }
     }
     printf("Count : %i\n",count);
 }
void main(){
	char a[20] = "bdcfeazwy";
	
	sort(a,9);
	
	printf("String is : %s",a);

}

