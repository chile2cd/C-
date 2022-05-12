#include <iostream>
#include<stdio.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop 

n ��ʾn������ m ��ʾm ����ͻ  
*/
#define MOD 1000000007 
typedef long long LL;
int n,m;
int op[7]; // op[i]��ʾ i �ķ���   
bool conflict[7][7]; // ��ʼ����ͻ����  
struct M{
	LL a[6][6];
	// Ĭ�Ϲ���  
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

M mul(M m1,M m2)//�����ĳ˷� 
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

M mPow(M m,int k) //�����M��k�η�  
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
	}//��ʼ����λ�������� 
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
	M cMatrix;//�����ͻ���� 
	for(int i=0;i<m;++i)
	{
    	scanf("%d %d",&x,&y);		//x��y ��ͻ  
		cMatrix.a[x-1][y-1]=0;
		cMatrix.a[y-1][x-1]=0;
		
	}// ��ʼ�����
	
	M cMatrix_n_1=mPow(cMatrix,n-1);//������n-1����  
	LL ans=0;
	for(int i=0;i<6;++i)
	{
		for(int j=0;j<6;++j)
		{
			ans+=(cMatrix.a[i][j])%MOD;
		}
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
	
	cout<<ans*c<<endl;
	return 0;
}














