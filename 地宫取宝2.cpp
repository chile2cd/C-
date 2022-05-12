#include <iostream>
#include<stdio.h>
#include <cstring>
#include<string.h> 
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


/*

有一个地宫 小明只能向下或者向右 格子 是 m n 规模大小  

从左上角走到右下角 每走过一个格子 当格子中的宝贝比手中的价值大时 

小明可以选择拿起或者不拿 

当走到出口时 手中的宝贝恰好是 k 件  

求有多少不同的方案 拿到这 k 件宝贝  

*/ 
int n, m, k;
long long ans;
int arr[50][50];
long long dfs2(int x,int y,int max,int count); 

long long memory[50][50][14][13]; //！！！ 


int main(int argc, char *argv[]) {
//	cin>>n>>m>>k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			//cin>>arr[i][j];		// 初始化地图 
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
			
	if(x==n-1 && y==m-1)	// 到了最后一个格子 两种情况 
	{
		if(count==k || ( count==k-1&& cur>max ) ) // 只有价值大才捡或者不捡 
		{
			ans++;
		}
		return ans;	
	}
	if(cur>max) 	// 当前格子价值比手里的大 捡起 向下 或 向右 
	{
	
		ans+=dfs2(x,y+1,cur,count+1);  // 捡起 
		ans+=dfs2(x+1,y,cur,count+1);
	}
					// 或者也可以不捡 向下 或者 向右  

	ans+=dfs2(x,y+1,max+1,count);
	ans+=dfs2(x+1,y,max+1,count);
	
	memory[x][y][max+1][count]=ans;  //写缓存 
	return ans;
}	




















