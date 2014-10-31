#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	vector<vector<int> > threeSum(vector<int> &num)
	{
		vector< vector<int> > set;
		
		vector<int> v;
		int k = 0, i, j;
		int n = num.size();

		if(n<3) return set;

		sort(num.begin(),num.end());

		for(vector<int>::iterator iter = num.begin();iter!=num.end();iter++)
			cout<<*iter<<" ";
		cout<<endl;
		while(k<n-2 && num[k]<=0)
		{
			i = k + 1;
			j = n - 1;
			while(i < j)
			{
				if(num[i]+num[j]+num[k] == 0)
				{
					v.push_back(num[k]);
					v.push_back(num[i]);
					v.push_back(num[j]);
					set.push_back(v);
					v.clear();
					do{i++;}while(num[i]==num[i-1]);
				}
				if(num[i]+num[j]+num[k] < 0)	
					i++;
				if(num[i]+num[j]+num[k] > 0)
					j--;
			}
			do{k++;}while(num[k]==num[k-1]);
		}
		return set;
	}
};
int main()
{
	srand((unsigned int)time(NULL));
	vector<int> v;
	for(int i = 0; i < 30; i++)
	{
		v.push_back(rand()%10-rand()%10);
		cout<<v[i]<<" ";
	}
	cout<<endl;
	Solution s;
	vector<vector<int> > set = s.threeSum(v);
	for(vector<vector<int> >::iterator iter = set.begin();iter!=set.end();iter++)
	{
		cout<<"( ";
		for(vector<int>::iterator i = (*iter).begin();i!=(*iter).end();i++)
   			cout<<*i<<" ";
		cout<<" )"<<endl;
	}
    cout<<endl;	
}
