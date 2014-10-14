#include<iostream>
using namespace std;
class Solution{
public:
	int singleNumber(int A[], int n){
		int result = 0;
		for(int i = 0; i < n; i++)
		{
			result = result ^ A[i];
		}
		return result;
	}
};
int main()
{
	Solution s;
	int a[13] = {1,2,3,4,5,7,7,3,5,8,2,1,4};
	cout<<s.singleNumber(a,13)<<endl;
}
