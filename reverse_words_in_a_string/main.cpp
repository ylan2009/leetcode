#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Solution{
public:
	void reverseWords(string &s){
		//��ջ�ķ���
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
		//�����ķ���
		//���㷨��" "��Ϊƴ���ַ����ı�־�������ո��ʱ�򣬿�ʼ����ƴ��
		//�е������ۼӵ��������������Ա��ֳ����ռ䣬��ʱ�临�Ӷȱȶ�ջ�ķ�����һ��
		string temp = "", result = "";
		string sign = " ";
		for(int i = 0; i < s.length(); i++)
		{
			if(s[i] == ' '){
				if(result == ""||temp == "")//�ʼ��ʱ��result=""��ÿ��ƴ��һ����temp=""(����Ŀո񲻼���)
					sign = "";
				result = temp + sign +result;
				temp = "";
				sign = " ";
			}
			else
				temp = temp + s[i];
		}
		//������Ҫ���������������������ֻ�ǵ���һ��"",��resultʼ���ǿ�
		//��������һ��tempƴ��
		//������Σ���Ҫ��resultƴ��������s
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
