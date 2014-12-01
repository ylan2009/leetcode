#include<iostream>
using namespace std;

class Solution{
public:
	int *record;
	int climbStairs(int n){
		record = new int[n];
		for(int i=0; i<n; i++)
			record[i] = -1;
		return cs(n);
	}
	int cs(int n){
		int steps;
		if(record[n-1] != -1)  return record[n-1];
		else if(n == 1) steps = 1;
		else if(n == 2) steps = 2;
		else steps = cs(n-1) + cs(n-2);
		record[n-1] = steps;
		return steps; 
	}
};
int main()
{
	Solution s;
	cout<<s.climbStairs(5)<<endl;
}
