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
	 
	for(int i=1;i<=6;++i)
	{
		ans=(ans+f(i,n-1))%MOD;
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














