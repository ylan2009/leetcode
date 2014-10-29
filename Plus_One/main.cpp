#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	vector<int> plusOne(vector<int> &digits)
	{
		reverse(digits.begin(),digits.end());
		vector<int> v;
		int a = 1;
		int b = 0;
		for(vector<int>::iterator iter = digits.begin();iter!=digits.end();iter++)
		{
			v.push_back( (*iter + a + b)%10 );
			b = (*iter + a + b) / 10;
			a = 0;
		}
		if(b)
			v.push_back(b);
		reverse(digits.begin(),digits.end());
		reverse(v.begin(),v.end());
		return v;
	}
};

int main()
{
	vector<int> v;
	for(int i = 0; i < 9; i++)
		v.push_back(9);
	for(vector<int>::iterator iter = v.begin();iter!=v.end();iter++)
	{
		cout<<*iter<<" ";
	}
	cout<<endl;

	Solution s;
	vector<int> u;
	v = s.plusOne(v);
	for(vector<int>::iterator iter = v.begin();iter!=v.end();iter++)
	{
		cout<<*iter<<" ";
	}
	cout<<endl;
	
}
