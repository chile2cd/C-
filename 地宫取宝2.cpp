#include <iostream>
#include<stdio.h>
#include <cstring>
#include<string.h> 
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


/*

��һ���ع� С��ֻ�����»������� ���� �� m n ��ģ��С  

�����Ͻ��ߵ����½� ÿ�߹�һ������ �������еı��������еļ�ֵ��ʱ 

С������ѡ��������߲��� 

���ߵ�����ʱ ���еı���ǡ���� k ��  

���ж��ٲ�ͬ�ķ��� �õ��� k ������  

*/ 
int n, m, k;
long long ans;
int arr[50][50];
long long dfs2(int x,int y,int max,int count); 

long long memory[50][50][14][13]; //������ 


int main(int argc, char *argv[]) {
//	cin>>n>>m>>k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			//cin>>arr[i][j];		// ��ʼ����ͼ 
			scanf("%d",&arr[i][j]);
		}	
		
	}
	
	memset(memory,-1,sizeof(memory));
	
	ans=dfs2(0,0,-1,0);
	cout<<ans<<endl;
	
	
	return 0;
}


long long dfs2(int x,int y,int max,int count)
{
	long long ans =0;
	
	if(memory[x][y][max+1][count]!=-1)
		return memory[x][y][max+1][count];
		
	if(x==n || y==m || count>k)
		return 0;
	
	
	int cur=arr[x][y];
			
	if(x==n-1 && y==m-1)	// �������һ������ ������� 
	{
		if(count==k || ( count==k-1&& cur>max ) ) // ֻ�м�ֵ��ż���߲��� 
		{
			ans++;
		}
		return ans;	
	}
	if(cur>max) 	// ��ǰ���Ӽ�ֵ������Ĵ� ���� ���� �� ���� 
	{
	
		ans+=dfs2(x,y+1,cur,count+1);  // ���� 
		ans+=dfs2(x+1,y,cur,count+1);
	}
					// ����Ҳ���Բ��� ���� ���� ����  

	ans+=dfs2(x,y+1,max+1,count);
	ans+=dfs2(x+1,y,max+1,count);
	
	memory[x][y][max+1][count]=ans;  //д���� 
	return ans;
}	




















