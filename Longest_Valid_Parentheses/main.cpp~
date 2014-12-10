#include<iostream>
#include<string>
using namespace std;
class Solution{
public:
	int longestValidParentheses(string s)
	{
		int n = s.length();
		int g[n];
		int j;
		int maxValue;
		for(int i = 0; i < n; i++)
			g[i] = 0;
		for(int i = n-2; i >= 0; i++)
		{
			if(s[i] == '(')
			{
				j = i+1+g[i+1];	
				if(j<n && s[j] == ')')
				{
					g[i] = g[i+1] + 2;
					if(j+1<n) g[i] += g[j+1];
				}
			}
			maxValue = max(maxValue,g[i]);
		}
		return maxValue;
	}
};
