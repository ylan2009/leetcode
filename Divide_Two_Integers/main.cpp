#include<iostream>
#include<stdlib.h>
using namespace std;
class Solution{
public:
	int divide(int dividend, int divisor)
	{
		unsigned long dend = abs((long)dividend), dsor = abs((long)divisor);
		int flag = 1;
		if((dividend >= 0 && divisor < 0) || (dividend <= 0 && divisor > 0))
			flag = -1;
		////long int和int都是32位，当dend=-2147483648，dsor=1时，temp和t会左移32位，导致溢出，所以temp和t的类型至少是long long
		unsigned long long temp = dsor;
		unsigned long long int t = 1;
		int result = 0;
		while(dsor <= dend)
		{
			while(temp <= dend)
			{
				temp <<= 1;
				t <<= 1;
			}
			temp >>= 1;
			t >>= 1;
			result += t;
			t = 1;
			dend -= temp;
			temp = dsor;
		}
		return result * flag;
	}
};
int main()
{
	int a = -2147483648;
	int b = 1;
	Solution s;
	int c = s.divide(a,b);
	cout<<c<<endl;

}

