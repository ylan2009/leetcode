#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	int threeSumClosest(vector<int> &num,int target)
	{
		int result = 0,temp;
		int k = 0, i, j;
		int n = num.size();
		if(n<=3)
		{
			for(int c = 0; c < n; c++)
				result += num[c];
			return result;
		}

		sort(num.begin(),num.end());

		for(vector<int>::iterator iter = num.begin();iter!=num.end();iter++)
			cout<<*iter<<" ";
		cout<<endl;

		result = num[0]+num[1]+num[2];
		while(k<n-2)
		{
			i = k + 1;
			j = n - 1;
			while(i<j)
			{
				temp = num[k] + num[i] + num[j];		
				if(abs(result-target)>abs(temp-target))
					result = temp;
				if(temp == target)
					return target;
				if(temp > target)
					j--;
				if(temp < target)
					i++;
			}
			k++;
		}
		return result;
	}
};
int main()
{
	srand((unsigned int)time(NULL));
	vector<int> v;
	for(int i = 0; i < 20; i++)
	{
		v.push_back(rand()%10-rand()%10);
		cout<<v[i]<<" ";
	}
	cout<<endl;
	Solution s;
	int a = s.threeSumClosest(v,-11);
	cout<<a<<endl;
}
