#include<iostream>
using namespace std;
class Solution{
public:
	int singleNumber(int A[],int n){
		int count[32] = {0};
		int result = 0;
		for(int i = 0; i < 32; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if((A[j]>>i) & 1)
					count[i]++;
			}
			result |= ((count[i]%3) << i);
		}
		return result;
	}
	int singleNumber_2(int A[],int n){
		int ones = 0;
		int twos = 0;
		int threes = 0;
		for(int i = 0; i < n; i++)
		{
			//只读进一次A[i]，则twos为0
			//如果读到两个相同的A[i]，则twos为1
			//读到三个，则twos为1
			twos |= ones & A[i];
			//只读进一次A[i]，则ones为1
			//如果读到两个，则ones为0
			//读到三个，则ones为1
			ones ^= A[i];
			//如果threes上某个位为1，则要清零ones和twos位上对应的位
			threes = twos & ones;
			//如果threes的某个位为1，则对应的ones和twos上的位清0
			//否则，对应的ones和twos上的位保持不变
			twos &= ~threes;
			ones &= ~threes;
		}
		cout<<ones<<endl;
		cout<<twos<<endl;
		cout<<threes<<endl;
		return ones;
	}

};
int main()
{
	Solution s;
	int a[13] = {1,3,4,2,1,1,4,3,3,4,5,2,2};
	cout<<s.singleNumber_2(a,13)<<endl;

}
