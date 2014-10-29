#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
class Solution{
public:
	int removeDuplicates(int A[], int n)
	{
		if(n==0) return 0;
		int i = 0, j = 0;
		while(1)
		{
			do{ j++; }while(j<n && A[j]==A[i]);
			if(j==n) break;
			A[i+1] = A[j];
			i++;
		}
		return i+1;
	}
};

void swap(int *a, int *b)
{
	if(*a==*b) return;
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}



void select(int a[],int n)
{
	int s;
	for(int i = 0; i < n-1; i++)
	{
		s = i;
		for(int j = i+1; j < n; j++)
		{
			if(a[s]>a[j])
				s = j;
		}
		if(s!=i)
			swap(&a[s],&a[i]);
	}
}


int main()
{
	srand((unsigned int)time(NULL));
	int a[30];
	for(int i = 0; i < 30; i++)
	{
		a[i] = rand() % 10;
	}
	select(a,30);
	for(int i = 0; i < 30; i++)
    	cout<<a[i]<<" ";
    cout<<endl;
	cout<<endl;
	Solution s;
	int c = s.removeDuplicates(a,30);
	for(int i = 0; i < c; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
