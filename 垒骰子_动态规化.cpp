#include <iostream>
#include<stdio.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop 

n 表示n层骰子 m 表示m 个冲突  
*/
#define MOD 1000000007 

int n,m;
int op[7]; // op[i]表示 i 的反面   
bool conflict[7][7]; // 初始化冲突的面  

void init()
{
	op[1]=4;
	op[2]=5;
	op[3]=6;
	op[4]=1;
	op[5]=2;
	op[6]=3;		
}

long long int f(int up,int cnt)
{
	if(cnt==0) 
		return 1;
	long long ans=0;
	for(int upp=1;upp<=6;++upp)
	{
		if(conflict[op[up]][upp]==true)continue;
		ans+=((f(upp,cnt-1))%MOD);
	}	
	return ans;
} 



int dp[2][7];
int main(int argc, char *argv[]) {
	long long ans=0;
	init();
	scanf("%d %d",&n,&m);
	int x,y;
	for(int i=0;i<m;++i)
	{
    	scanf("%d %d",&x,&y);		
		conflict[x][y]=true;
		conflict[y][x]=true;
	}// 初始化完成
	
	
	for(int j=1;j<=6;++j)
	{
		dp[0][j]=1;
	}
		// 初始化了第一层 自底向上  
	int cur=0;
	for(int i=2;i<=n;++i)
	{
		cur=1-cur; // 当前层 
		for(int n=1;n<=6;++n){
			dp[cur][n]=0; //初始化当前这一行或者说清空这一行  当作累加迭代变量 
			
			for(int m=1;m<=6;++m){
				if(conflict[op[n]][m]==true)continue; //筛选冲突  
				dp[cur][n]=(dp[cur][n]+ dp[1-cur][m])%MOD; 
			}
		}
	}
	long long sum=0;
	for(int k=1;k<=6;++k)  //将这六种情况累加  
	{
		sum+=(dp[cur][k]%MOD);
	}
	//求4的n次方  
	int c=1;
	int a=4;
	while(n!=0){
		if(n&1)
		{
			c=c*a;
			 
		}
		a=a*a;
		n>>=1;
	}
	cout<<sum*c<<endl;
	return 0;
}














