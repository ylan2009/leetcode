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
			//ֻ����һ��A[i]����twosΪ0
			//�������������ͬ��A[i]����twosΪ1
			//������������twosΪ1
			twos |= ones & A[i];
			//ֻ����һ��A[i]����onesΪ1
			//���������������onesΪ0
			//������������onesΪ1
			ones ^= A[i];
			//���threes��ĳ��λΪ1����Ҫ����ones��twosλ�϶�Ӧ��λ
			threes = twos & ones;
			//���threes��ĳ��λΪ1�����Ӧ��ones��twos�ϵ�λ��0
			//���򣬶�Ӧ��ones��twos�ϵ�λ���ֲ���
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
