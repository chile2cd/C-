#include<iostream>
#include<cstdio>
using namespace std;
 
int fun(int m,int n){
	int rem;			//������������Ϊ0��ʱ������m��Ϊ���Լ��
	//���ý�С�����Խϴ����ȡ�࣬���������Խ�С�������ֱ࣬������Ϊ�� 
	while(n > 0){
		rem = m % n;
		m = n;
		n = rem;
	}
	return m;			//���������			
}
int main(){
	int n,m;
	cin>>m>>n;
	cout<<"m��n�����Լ��Ϊ��"<<fun(m,n)<<endl;
	return 0; 
} 
