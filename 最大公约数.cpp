#include<iostream>
#include<cstdio>
using namespace std;
 
int fun(int m,int n){
	int rem;			//余数，当余数为0的时候，最后的m即为最大公约数
	//先用较小的数对较大的数取余，再用余数对较小的数求余，直到余数为零 
	while(n > 0){
		rem = m % n;
		m = n;
		n = rem;
	}
	return m;			//将结果返回			
}
int main(){
	int n,m;
	cin>>m>>n;
	cout<<"m和n的最大公约数为："<<fun(m,n)<<endl;
	return 0; 
} 
