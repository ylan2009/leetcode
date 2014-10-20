#include<iostream>
using namespace std;
class Solution{
public:
	Solution(){}
	~Solution(){}
	int reverse(int x){
		int result = 0;
		while(x)
		{
			result = result * 10 + x % 10;
			x = x / 10;
		}
		return result;
	}
};

int main()
{
	Solution s;
	cout<<s.reverse(65264)<<endl;
	cout<<s.reverse(-65264)<<endl;	
	return 0;
}
