#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
	int maxProfit(vector<int> &prices)
	{
		int n = prices.size();
		if(n<=1) return 0;
		int profit = prices[1]-prices[0];
		int minValue = min(prices[1],prices[0]);
		for(int i = 2; i < n; i++)
		{
			profit = max(profit,prices[i]-minValue);
			minValue = min(minValue,prices[i]);
		}
		return max(profit,0);

	}
};

int main()
{
	
}
