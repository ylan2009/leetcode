#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
	int maxProfit(vector<int> &prices)
	{
		int n = prices.size();	
		if(n<=1) return 0;
		int profit[n];
		profit[0] = 0;
		int minValue = prices[0];
		for(int i = 1; i < n; i++)
		{
			profit[i] = max(profit[i-1],prices[i]-minValue);
			minValue = min(minValue,prices[i]);
		}

		int maxprofit = 0;
		int maxValue = prices[n-1];
		int res = profit[n-1];
		for(int i = n-2; i>=0;i--)
		{
			maxprofit = max(maxprofit,maxValue-prices[i]);
			res = max( res, profit[i] + maxprofit ); 
			maxValue = max(maxValue,prices[i]);
		}
		return res;
	}
};
