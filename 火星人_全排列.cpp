#include <iostream>
#include<algorithm>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop 

��һ��һ�������� NN����ʾ��������ָ����Ŀ��1��N��10000����
�ڶ�����һ�������� MM����ʾҪ����ȥ��С������1��M��100����
��һ���� 11 �� NN �� NN ��������һ�����У��ÿո��������ʾ��������ָ������˳��
*/
//int a[10000]={0};
//int b[10000]={0};
//int c[10000];
//int main(int argc, char *argv[]) {
//	int N,M; 
//	int k=1;
//	cin>>N>>M;
//	for(int i=0;i<N;++i){
//		a[i]=i+1;
//	}
//	do{ 
//		if(k==M+1)
//		{
//			for(int i=0;i<N;++i)
//			{	
//			  cout<<a[i]<<" ";
//	  		}	
//		}	
//		k++;
//	}while(next_permutation(a,a+N));
//		
//	return 0;
//}
int a[10000]={0};
int b[10000]={0};
int c[10000];
int main(int argc, char *argv[]) {
	int N,M; 
	int k=0;
	cin>>N>>M;
	for(int i=0;i<N;++i){
		cin>>a[i];
	}
	do{ 
		if(k==M)
		{
			for(int i=0;i<N;++i)
			{	
			  cout<<a[i]<<" ";
	  		}	
	  		break;
		}	
		k++;
	}while(next_permutation(a,a+N));
		
	return 0;
}
