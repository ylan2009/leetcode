#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
class Solution{
public:
	void merge(int A[], int m, int B[], int n)
	{
		int i,j,k;
		for(i = m-1; i >= 0; i--)
			A[i+n] = A[i];
		i = n;
		j = 0;
		k = 0;
		while(i<m+n && j<n)
		{
			A[k++] = (A[i] < B[j]) ? A[i++] : B[j++];
		}
		while(j<n)
		{
			A[k++] = B[j++];
		}
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
	int A[30],B[10];
	for(int i = 0; i < 30; i++)
		A[i] = 0;
	for(int i = 0; i < 20; i++)
	{
		A[i] = rand() % 100;
	}
	for(int i = 0; i < 10; i++)
	{
		B[i] = rand() % 100;
	}
	select(A,20);
	select(B,10);
	for(int i = 0; i < 20; i++)
		cout<<A[i]<<" ";
	cout<<endl;
	for(int j = 0; j < 10; j++)
		cout<<B[j]<<" ";
	cout<<endl;
	Solution s;
	s.merge(A,20,B,10);
	for(int i = 0; i < 30; i++)
		cout<<A[i]<<" ";
	cout<<endl;

}
