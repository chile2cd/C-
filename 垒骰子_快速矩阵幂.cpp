#include <iostream>
#include<stdio.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop 

n 表示n层骰子 m 表示m 个冲突  
*/
#define MOD 1000000007 
typedef long long LL;
int n,m;
int op[7]; // op[i]表示 i 的反面   
bool conflict[7][7]; // 初始化冲突的面  
struct M{
	LL a[6][6];
	// 默认构造  
	M(){
		for(int i=0;i<6;++i){
			for(int j=0;j<6;++j){
				a[i][j]=1;
			}
		}
	}
};
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

M mul(M m1,M m2)//求矩阵的乘法 
{
	M ans;
	for(int i=0;i<6;++i)
	{
		for(int j=0;j<6;++j)
		{
			ans.a[i][j]=0;
			for(int k=0;k<6;++k)
			{
				ans.a[i][j]=m1.a[i][k]*m2.a[k][j];
			} 
		}
	}
	return ans;	
}

M mPow(M m,int k) //求矩阵M的k次方  
{
	M ans; 
	for(int i=0;i<6;++i){
		for(int j=0;j<6;++j)
		{
			if(i==j)
			 	ans.a[i][j]=1;
			else 
			 	ans.a[i][j]=0;
		}
	}//初始化单位迭代矩阵 
	while(k!=0){
		if(n&1)
		{
	    	ans=mul(ans,m);
			 
		}
		m=mul(m,m);
		k>>=1;
	}
}

int dp[2][7];

int main(int argc, char *argv[]) {

	init();
	scanf("%d %d",&n,&m);
	int x,y;
	M cMatrix;//定义冲突矩阵 
	for(int i=0;i<m;++i)
	{
    	scanf("%d %d",&x,&y);		//x和y 冲突  
		cMatrix.a[x-1][y-1]=0;
		cMatrix.a[y-1][x-1]=0;
		
	}// 初始化完成
	
	M cMatrix_n_1=mPow(cMatrix,n-1);//求矩阵的n-1次幂  
	LL ans=0;
	for(int i=0;i<6;++i)
	{
		for(int j=0;j<6;++j)
		{
			ans+=(cMatrix.a[i][j])%MOD;
		}
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
	
	cout<<ans*c<<endl;
	return 0;
}














