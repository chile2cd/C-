#include <iostream>
#include <string>
#include<sstream>
#include<set>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
	一个数字的平方 和 立方 分别把123456789都出现了一遍 求这个数字 
*/
void i2s(int num,string& s)
{
	stringstream ss;
	ss<<num;
	ss>>s;
}
// 用set集合去重  
bool check(string s)
{
	set<char> ss;
	for(int i=0;i<s.length();++i)
	{
		ss.insert(s[i]); // 去重插入 
	}
	return s.size()==10 && ss.size()==10;
}

int main(int argc, char *argv[]) {
	
	string s1,s2;
	for(int i=1;i<10000;++i)
	{
		i2s(i*i,s1);
		i2s(i*i*i,s2);
		
		if(check(s1+s2))
		{
			cout<<i<<endl;
			break;
		}
		
	} 
	
	return 0;
}
