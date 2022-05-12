#include <iostream>
#include<algorithm>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop 

第一行一个正整数 NN，表示火星人手指的数目（1≤N≤10000）。
第二行是一个正整数 MM，表示要加上去的小整数（1≤M≤100）。
下一行是 11 到 NN 这 NN 个整数的一个排列，用空格隔开，表示火星人手指的排列顺序。
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
