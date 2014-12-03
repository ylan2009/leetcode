#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

class Solution{
public:
//暴力 O(n^2)
int maxSubArray(int A[], int n) {
        int maxValue = A[0];
        int maxItem;
        int i,j;
        for(i = 0; i < n; i++)
        {
            maxItem = A[i];
            for(j = i+1; j < n; j++)
            {
                maxItem = max(maxItem,maxItem+A[j]);
            }
            maxValue = max(maxValue,maxItem);
        }
        return maxValue;
    }
//bottom up O(n^2)
int maxSubArray_2(int A[], int n){
	int g[n][n];
	int i,j;
	int temp;
	for(i = n-1; i >= 0; i--)
		for(j = i; j < n; j++)
		{
			if(i == j) g[i][j] = A[i];
			else 
			{
				g[i][j] = max(g[i][j-1],g[i+1][j]);
				for(int k = i; k <= j; k++)
					temp += A[k];
				g[i][j] = max(g[i][j],temp);
				temp = 0;
			}
		}
	return g[0][n-1];
	}
//O(n)
int maxSubArray(int A[], int n){
	int sumValue = A[0];
	int maxValue = A[0];
	for(int i = 1; i < n; i++)
	{
		if(sumValue < 0) sumValue = 0;
		sumValue += A[i];
		maxValue = max(maxValue,sumValue);
	}
	return maxValue;
}
//分治法O(nlogn)
int maxSubArray(int A[], int n) {
        return subMax(A,0,n-1);

    }
    int subMax(int A[], int m, int n)
    {
        if(m == n) return A[m];
        
        int mid = (m + n)/2;
        int maxPre = subMax(A,m,mid);
        int maxEnd = subMax(A,mid+1,n);
        
        int leftMax = A[mid];
        int rightMax = A[mid+1];
        
        int sum = leftMax;
        
        for(int i = mid-1; i>=m;i--)
        {
            sum += A[i];
            leftMax = max(leftMax,sum);
        }
        sum = rightMax;
        for(int j = mid+2; j<=n;j++)
        {
            sum += A[j];
            rightMax = max(rightMax,sum);
        }
        sum = leftMax + rightMax;
        return max(sum,max(maxPre,maxEnd));
    }



int main()
{
	int A[10];
	srand((unsigned)time(NULL));
	for(int i = 0; i < 10; i++)
	{
		A[i] = rand() % 10;
		if(rand() % 10 < 5)
			A[i] = -A[i];
		cout<<A[i]<<" ";
	}
	cout<<endl;
	Solution s;
	cout<<s.maxSubArray_2(A,10)<<endl;

}


