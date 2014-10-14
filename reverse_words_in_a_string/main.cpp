#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Solution{
public:
	void reverseWords(string &s){
		//堆栈的方法
		stack<string> st;
		int l = s.length();
		int i = 0;
		while(i<l){
			while(s[i] == ' ' && i < l)
			{i++;}
			if(i==l) break;
			string temp;
			while(s[i] != ' ' && i < l)
			{
				temp.push_back(s[i]);
				i++;
			}
			st.push(temp);
			st.push(" ");
			i++;
		}
		string result;
		if(!st.empty()) st.pop();
		while(!st.empty())
		{
			result.append(st.top());
			st.pop();
		}
		s = result;
	}
	void reverseWords_2(string &s){
		string temp = "", result = "";
		for(int i = 0; i < s.length(); i++)
		{
			if( *(s.c_str()+i) == ' ' ){
				result = temp + (temp==""||result=="" ? "":" ") + result;
				temp = "";
			}
			else
				temp = temp + *(s.c_str()+i);
		}
		s = temp + (temp==""||result=="" ? "":" ") + result;
	}
	void reverseWords_3(string &s){
		//迭代的方法
		//本算法将" "作为拼接字符串的标志，遇到空格的时候，开始进行拼接
		//有点类似累加的做法，这样可以保持常数空间，但时间复杂度比堆栈的方法高一点
		string temp = "", result = "";
		string sign = " ";
		for(int i = 0; i < s.length(); i++)
		{
			if(s[i] == ' '){
				if(result == ""||temp == "")//最开始的时候result=""，每次拼完一个词temp=""(多余的空格不计入)
					sign = "";
				result = temp + sign +result;
				temp = "";
				sign = " ";
			}
			else
				temp = temp + s[i];
		}
		//这里需要处理两种情况，如果输入的只是单纯一个"",则result始终是空
		//或者正好一个temp拼完
		//不管如何，都要把result拼起来赋给s
		if(result == ""||temp == "")
			sign = "";
		s = temp + sign + result;
	}
};

int main()
{
	Solution s;
	string a = " hello    world haha  ";
	string b = "";
	string c = "   ";
	s.reverseWords_3(a);
	s.reverseWords_3(b);
	s.reverseWords_3(c);
	cout<<"|"<<a<<"|"<<endl;
	cout<<"|"<<b<<"|"<<endl;
	cout<<"|"<<c<<"|"<<endl;
}
