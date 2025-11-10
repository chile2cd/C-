#include<sstream>
#include<iostream>
using namespace std;

int main()
{
	int num;
	int num1;
	stringstream ss1;
	stringstream ss2;
	stringstream ss3;
	string a="30";
	string b="20";
	string c;
	ss1<<a;
	
	ss1>>num;
	
	ss2<<b;
	
	ss2>>num1;
	
	num=num-num1;
	
	ss3<<num;
	ss3>>c;
	
	cout<<c.length()<<endl;
	
	
	return 0;
}
