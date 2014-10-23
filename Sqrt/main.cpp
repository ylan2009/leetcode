#include<iostream>
using namespace std;

class Solution{
public:
	int sqrt(int x){
		unsigned long long begin = 0;
        unsigned long long end = (x+1)/2;
        unsigned long long tmp;
        unsigned long long mid;
        while(begin<end)
        {
	        mid = (begin+end)/2;
	        //mid = begin + (end - begin)/2;
	        tmp = mid * mid;
	        if(tmp == x)
		        return mid;
	        else if(tmp < x)
		        begin = mid + 1;
	        else
		        end = mid - 1;
        }
        tmp = end*end;
        if(tmp>x)
	        return end - 1;	
        else
	        return end;
	}
};

int main()
{
	Solution s;
	int a = 0;
	int b = 1;
	int c = 2;
	int d = 3;
	int e = 4;
	int f = 9;
	int g = 10;
	cout<<a<<":"<<s.sqrt(a)<<endl;
	cout<<b<<":"<<s.sqrt(b)<<endl;
	cout<<c<<":"<<s.sqrt(c)<<endl;
	cout<<d<<":"<<s.sqrt(d)<<endl;
	cout<<e<<":"<<s.sqrt(e)<<endl;
	cout<<f<<":"<<s.sqrt(f)<<endl;
	cout<<g<<":"<<s.sqrt(g)<<endl;
}
