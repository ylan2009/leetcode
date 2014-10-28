#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
class Solution{
public:
	int removeElement(int A[], int n, int elem){
		int i = -1, j = n;
		while(1)
		{
			do{i++;}while(j>i && A[i] != elem);
			do{j--;}while(j>i && A[j] == elem);
			if(i>=j) break;
			A[i] = A[j];
		}
		if(A[j] == elem)
			j--;
		return j+1;
	}
};
int main()
{
	int A[100];
	srand((unsigned int)time(NULL));
	int temp;
	int x = 5;
	int c = 0;
	for(int i = 0; i < 100; i++)
	{
		temp = rand() % 10;
		A[i] = temp;
		cout<<temp<<" ";
		if(temp == x)
			c++;
	}
	cout<<endl;
	Solution s;
	cout<<c<<endl;
	cout<<s.removeElement(A,100,x)<<endl;
}
