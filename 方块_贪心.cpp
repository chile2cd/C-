//#include<bits/stdc++.h>
//#include <iostream>
//using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop 

С��ͬѧ��һ�ŷ��飬ֻ�кڰ���ɫ�����Ҵ�С��״����ͬ���������Щ���鰴ԭ����
˳�����·ֳ����ɷǿնΣ�ʹ��ÿ�εĺڰױ�����ȡ���ע�⣬�����ƶ����飩
����������㣬�������Ҫ������ֳܷɶ��ٶΣ�
3
1 1
3 0
2 1

2
		0001110000000001
4
3 0 		
3 1
9 0
1 1
3
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
long long  n,a[100000],b[100000],ans[100000],sum[100000],maxn;
int main()
{
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		sum[b[i]]+=a[i];//�ֱ�ͳ�ƺ���Ͱ���ĸ�����
	}
	if(!sum[0])//�ж�������������ĳһ���򲻴��ڣ����һ������һ����ĸ�����
	{
		cout<<sum[1];
		return 0;
	}
	if(!sum[1])//�ж���һ������������
	{
		cout<<sum[0];
		return 0;
	}
	
	for(long long  i=1;i<=n;i++)//̰�� �ֱ��һ������һ�����ݵĿ�  
	{//	0001110000000001
		long long  x=b[i];//�������룬��x��Ϊ��һ�ֵ��� 
		long long  y;
		if(x==1)y=0;//���xΪ������y��Ϊ���򣬷�ȡ
		else if(x==0) y=1;//����ͬ��
		// ans[i]��ʾ �����������������ж��ٸ� 
		if(sum[x]*ans[y]%sum[y]==0)//�ж��Ƿ������Ҳ���Ǳ����Ƿ������
		{
			 int h=sum[x]*ans[y]/sum[y]-ans[x];//ȥ�����˶���
			if(a[i]>=h&&h>=1)
			{
				maxn++;//ͳ���ж����ַָ�� 
			}
		}
		ans[x]+=a[i];//ans�ۼ� 
	}
	cout<<maxn;
}


//struct Brick{
//	int k=0;//��������  
//	int c=0;// �ڰ� 1 0 
//}brick[100001];
//int n;
//string _brick=""; 
//int main(int argc, char *argv[]) {
//	//��ʼ������ 
//	cin>>n;
//	for(int i=0;i<n;++i){
//		cin>>brick[i].k>>brick[i].c;
//	}
//	
//	for(int i=0;i<n;++i){
//		if(brick[i].c==1){
//			//׷��k��1
//			_brick+=('1'*brick[i].k); 
//		}else{
//			//׷��k��0 
//			_brick+=('0'*brick[i].k); 
//		}
//	}//��תΪ�ַ��� 
//	 
//	int count=n/2;//�������гɵĳ��� ������2�� ���ٳ���Ҳ��2  ����Ϊ��2-count 
//	for(int i=2;i<=n-2;i+=2){
//		if()
//	} 
//	
//	
//	return 0;
//}




