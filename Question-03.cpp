#include<iostream>
using namespace std;
int comp=0;
void quicksort(int a[], int i, int j);
int partition(int a[],int l,int u);
void mergesort(int a[], int i, int j);
void merge(int a[], int i1,int j1, int i2, int j2);
void mergesort(int a[],int i,int j)
{
	int mid;
		
	if(i<j)
	{
		mid=(i+j)/2;
		mergesort(a,i,mid);		//left recursion
		mergesort(a,mid+1,j);	//right recursion
		merge(a,i,mid,mid+1,j);	//merging of two sorted sub-arrays
	}
}
 
void merge(int a[],int i1,int j1,int i2,int j2)
{
	int temp[50];	//array used for merging
	int i,j,k;
	i=i1;	//beginning of the first list
	j=i2;	//beginning of the second list
	k=0;
	
	while(i<=j1 && j<=j2)	//while elements in both lists
	{
		if(a[i]<a[j])
		{
		
			temp[k++]=a[i++];
			comp++;
		}
		else
		{
			temp[k++]=a[j++];
			comp++;
		}
	}
	
	while(i<=j1)	//copy remaining elements of the first list
		temp[k++]=a[i++];
		
	while(j<=j2)	//copy remaining elements of the second list
		temp[k++]=a[j++];
		
	//Transfer elements from temp[] back to a[]
	for(i=i1,j=0;i<=j2;i++,j++)
		a[i]=temp[j];
}
void quicksort(int a[],int i,int j)
{
	int mid;
	if(i<j)
	{
	mid=partition(a,i,j);
	quicksort(a,i, mid-1);
	quicksort(a,mid+1,j);	
	}
}
int partition(int a[],int l,int u)
{
	int p,i,j,temp;
	p=a[l];
	i=l;
	j=u+1;
	do{
		do
		i++;
		while(a[i]<p && i<=u);
		do
		j--;
		while(p<a[j]);
		if(i<j)
		{
		 temp=a[i];
		 a[i]=a[j];
		 a[j]=temp;
		}
		comp++;
	}while(i<j);
	a[l]=a[j];
	a[j]=p;
	return(j);
}
int main()
{
	int ch;
	cout<<"\t\n------Enter choice--------\n\n";
	cout<<"\n1. Bubble Sort\n2. Selection Sort\n3. Insertion sort \n 4. Merge Sort\n 5. Quick sort\n6. Exit\n";
	cin>>ch;
	switch (ch)
	{
		case 1:
			break;
		case 2:
				break;
		case 3:
				int n,t,j,ct=0;
	cout<<"\nEnter the size of array: ";
	cin>>n;
	int ar[n];
	cout<<"\nEnter elements in an array: ";
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	cout<<"\nElements are: ";
		for(int i=0;i<n;i++)
	{
		cout<<ar[i]<<" ";
	}
	for(int i=1;i<n;i++)
	{
		t=ar[i];
		for(j=i-1;j>=0&&t<ar[j];j--)
		{
			ar[j+1]=ar[j];
			ct++;
		}
		
    	ar[j+1]=t;
	}
	cout<<"\nSorted array is:";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<ar[i];
	}
	cout<<"\nNo of Comparisions : "<<ct;
					break;
		case 4 :
			
	int n,t,j;
	cout<<"\nEnter the size of array:\n";
	cin>>n;
	int ar[n];
	cout<<"\nEnter elements in an array:\n";
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	cout<<"\nElements are:\n";
		for(int i=0;i<n;i++)
	{
		cout<<ar[i]<<" ";
	}
	mergesort(ar,0,n-1);
	cout<<"\nsorted array is:\n";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<ar[i];
	}
	cout<<"\nTotal number of comparisons are: "<<comp;
	return 0;
						break;
  	   case 5:
  	   		int n,t,j;
	cout<<"\nEnter the size of array:\n";
	cin>>n;
	int ar[n];
	cout<<"\nEnter elements in an array:\n";
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	cout<<"\nElements are:\n";
		for(int i=0;i<n;i++)
	{
		cout<<ar[i]<<" ";
	}
	quicksort(ar,0,n-1);
	cout<<"\nsorted array is:\n";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<ar[i];
	}
	cout<<"\nTotal number of comparisons are: "<<comp;
	return 0;
			break;
			 case 6: system("cls");
                        exit(0);
                        break;
			default :
				cout<<"\n Incorrect Choice \n";
				
	}
}
