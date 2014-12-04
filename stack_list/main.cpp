#include<iostream>
using namespace std;
//n个数顺序入栈，求出栈的可能顺序种数
class Solution{
public:
	int stackList(int n)
	{
		if(!n) return 0;
		int g[n+1];
		g[0] = 1;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= i; j++)
			{
				if(i == j) g[j] = g[j-1];
				else g[j] += g[j-1];
			}
		return g[n];
	}
};
int main()
{
	Solution s;
	for(int i = 0; i < 10; i++)
		cout<<s.stackList(i)<<endl;
}
