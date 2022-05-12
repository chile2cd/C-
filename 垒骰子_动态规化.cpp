#include <iostream>
#include<stdio.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop 

n ��ʾn������ m ��ʾm ����ͻ  
*/
#define MOD 1000000007 

int n,m;
int op[7]; // op[i]��ʾ i �ķ���   
bool conflict[7][7]; // ��ʼ����ͻ����  

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
	}// ��ʼ�����
	
	
	for(int j=1;j<=6;++j)
	{
		dp[0][j]=1;
	}
		// ��ʼ���˵�һ�� �Ե�����  
	int cur=0;
	for(int i=2;i<=n;++i)
	{
		cur=1-cur; // ��ǰ�� 
		for(int n=1;n<=6;++n){
			dp[cur][n]=0; //��ʼ����ǰ��һ�л���˵�����һ��  �����ۼӵ������� 
			
			for(int m=1;m<=6;++m){
				if(conflict[op[n]][m]==true)continue; //ɸѡ��ͻ  
				dp[cur][n]=(dp[cur][n]+ dp[1-cur][m])%MOD; 
			}
		}
	}
	long long sum=0;
	for(int k=1;k<=6;++k)  //������������ۼ�  
	{
		sum+=(dp[cur][k]%MOD);
	}
	//��4��n�η�  
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














