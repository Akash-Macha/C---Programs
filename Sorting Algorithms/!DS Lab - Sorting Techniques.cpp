/*

Linear Search  Using function template
 Binary Search

Insertion Sort	in ascending

Selection Sort 	template  in decending
Quick Sort	template in ascending


Merge Sort	ascending

*/
#include<iostream>
#include<algorithm>
using namespace std;
template<class t>
void print(t *A,int n)
{
	cout << "After sorting:" << endl;
	for(int i=0;i<n;i++)
		cout << A[i] << " ";
}
void Merge(int *A,int low,int mid,int high)
{
	int nL = mid - low + 1;
	int nR = high - mid;

	int Left[nL] , Right[nR];

	for(int i=0;i<nL;i++)
		Left[i] = A[low + i];
	for(int j=0;j<nR;j++)
		Right[j] = A[j + mid + 1];

	int i=0;
	int j=0;
	int k=low;

	while(i < nL && j < nR)
	{
		if(Left[i] < Right[j])
		{
			A[k] = Left[i];
			++i;
		}else{			
			A[k] = Right[j];
			++j;
		}
		++k;
	}
	while(i < nL)
	{
		A[k] = Left[i];
		++i;
		++k;
	}
	while(j < nR)
	{
		A[k] = Right[j];
		++j;
		++k;
	}
}

void Merge_Sort(int *A,int low, int high)
{
	if(low < high)
	{
		int mid = (low+high)/2;

		Merge_Sort(A,low,mid);
		Merge_Sort(A,mid+1,high);

		Merge(A,low,mid,high);
	}
}

void MergeSort()
{	
	//Ascending order
	cout << "--MergeSort--" << endl;
	cout << "Enter how many elements : ";
	int n;
	cin >> n;
	cout << "Enter " << n << " elements :\n";
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	Merge_Sort(a,0,n-1);
	
	print<int>(a,n);
}

template<class t>
int partition(t *A,int low, int high)
{
	t pivote = A[high];
	int i = low-1; // index of smaller element
	int j;

	for(j=low;j<=high-1;j++)
	{
		if( A[j] <= pivote )
		{
			++i;
			swap(A[i],A[j]);
		}
	}
	swap( A[i+1] , A[high] );

	return (i+1);
}

template<class t>
int Quick_Sort(t *A,int low, int high)
{
	if(low < high)
	{
		int pivote = partition<int>(A,low,high);

		Quick_Sort<int>(A,low,pivote-1);
		Quick_Sort<int>(A,pivote+1,high);
	}
}

void QuickSort()
{
	cout << "--QuickSort--" << endl;
	cout << "Enter how many elements : ";
	int n;
	cin >> n;
	//the type of data matters HERE!
	int a[n];
	
	cout << "Enter " << n << " elements:\n";
	for(int i=0;i<n;i++)
		cin >> a[i];

	//QuickSort pivote - a[high] = pivote

	Quick_Sort<int>(a,0,n-1);

	print(a,n);

}

template<class t>
void SelectionSort()
{
	cout << "--SelectionSort using template class--" << endl;
	cout << "Enter how many elements : ";
	int n;
	cin >> n;
	t a[n];
	cout << "Enter " << n << " elements :\n";
	for(int i=0;i<n;i++)
		cin >> a[i];
	//updating the current minimum
	for(int i=0;i<n-1;i++)
	{
		int min = i;
		for(int j=i+1; j < n ; j++)
		{
			if(a[j] < a[min]){
				min = j;
			}
		}
		swap(a[i],a[min]);
	}

	print<float>(a,n);
}
void InsertionSort()
{
	cout << "--InsertionSort--" << endl;
	cout << "Enter how many elements : ";
	int n;
	cin >> n;
	int a[n];
	cout << "Enter " << n << " elemtns :\n";
	for(int i=0;i<n;i++)
		cin >> a[i];
	//Insertion sort --  ascending
	int temp,position;
	for(int i=1;i<n;i++)
	{
		position = i;
		temp = a[i];
		while(position > 0 && a[position-1] > temp){
			a[position] = a[position-1];
			--position;
		}
		a[position] = temp;
	}
	print<int>(a,n);
}
void BinarySearch()
{
	cout << "-- BinarySearch --" << endl;
	cout << "Enter how many elements : ";
	int n;
	cin >> n;
	int a[n];
	cout << "Enter " << n << " elements :\n";
	for(int i=0;i<n;i++)
		cin >> a[i];
	cout << "Enter key element : ";
	int key;
	cin >> key;
	int low=0,high=n-1, mid;
	int flag=0;
	while(low <= high)
	{
		mid = (low+high)/2;
		if(key == a[mid]){
			flag=1;
			break;
		}
		else if(key < a[mid])
		{
			high = mid - 1;
		}else if(key > a[mid]){
			low = mid + 1;
		}
	}
	if(flag == 1)
		cout << "Key element found at " << mid << " index" << endl;
	else
		cout << "Key element not found" << endl;
}
void LinearSearch()
{
	cout << "-- LinearSearch --" << endl;
	cout << "Enter how many numbers : ";
	int n;
	cin >> n;
	int a[n];
	cout << "Enter " << n << " elements :\n";
	for(int i =0;i<n;i++)
		cin >> a[i];
	int key;
	cout << "Enter key element : ";
	cin >> key;
	int i,pos;
	for(i=0;i<n;i++){
		if(key == a[i]){
			break;
		}
	}
	cout << "Element found at " << i << " index";
}

int main(){
	cout << "---All searching Technics!---\n" << endl;
	cout << "1. Linear Search using template function" << endl;
	cout << "2. Binary Search using template function" << endl;
	cout << "3. Insertion Sort in ascending order" << endl;
	cout << "4. Selection Sort using template function" << endl;
	cout << "5. Quick Sort using template function" << endl;
	cout << "6. Merge Sort in ascending order" << endl;
	int choice;
	cin >> choice;
	switch(choice){
		case 1 :	LinearSearch();
					break;
		case 2 :	BinarySearch();
					break;
		case 3 :	InsertionSort();
					break;
		case 4 :	SelectionSort<float>();
					break;
		case 5 :	QuickSort();
					break;
		case 6 :	MergeSort();
					break;
		default: cout << "Wrong choice!" << endl;
	}
}