//#include<bits/stdc++.h>
//#include <iostream>
//using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop 

小白同学有一排方块，只有黑白两色，并且大小形状均相同；他想把这些方块按原来的
顺序重新分成若干非空段，使得每段的黑白比例相等。（注意，不能移动方块）
请你帮他计算，按上面的要求，最多能分成多少段？
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
		sum[b[i]]+=a[i];//分别统计黑球和白球的个数。
	}
	if(!sum[0])//判断特殊的情况，当某一种球不存在，则答案一定是另一种球的个数。
	{
		cout<<sum[1];
		return 0;
	}
	if(!sum[1])//判断另一种球，理由如上
	{
		cout<<sum[0];
		return 0;
	}
	
	for(long long  i=1;i<=n;i++)//贪心 分别对一组数据一组数据的看  
	{//	0001110000000001
		long long  x=b[i];//根据输入，将x变为第一种的球 
		long long  y;
		if(x==1)y=0;//如果x为白球，则将y变为黑球，反取
		else if(x==0) y=1;//方法同上
		// ans[i]表示 截至到遍历这类球有多少个 
		if(sum[x]*ans[y]%sum[y]==0)//判断是否除尽，也就是比例是否成立。
		{
			 int h=sum[x]*ans[y]/sum[y]-ans[x];//去算少了多少
			if(a[i]>=h&&h>=1)
			{
				maxn++;//统计有多少种分割方案 
			}
		}
		ans[x]+=a[i];//ans累加 
	}
	cout<<maxn;
}


//struct Brick{
//	int k=0;//连续个数  
//	int c=0;// 黑白 1 0 
//}brick[100001];
//int n;
//string _brick=""; 
//int main(int argc, char *argv[]) {
//	//初始化数据 
//	cin>>n;
//	for(int i=0;i<n;++i){
//		cin>>brick[i].k>>brick[i].c;
//	}
//	
//	for(int i=0;i<n;++i){
//		if(brick[i].c==1){
//			//追加k个1
//			_brick+=('1'*brick[i].k); 
//		}else{
//			//追加k个0 
//			_brick+=('0'*brick[i].k); 
//		}
//	}//已转为字符串 
//	 
//	int count=n/2;//算出最多切成的长度 最少切2段 最少长度也是2  长度为：2-count 
//	for(int i=2;i<=n-2;i+=2){
//		if()
//	} 
//	
//	
//	return 0;
//}




