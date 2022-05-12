#include <iostream>
#include<algorithm>
using namespace std;
/*
从三乘四列的图中找出路径为5的连通图
计算有多少个 
单纯的dfs无法解决 T 字形问题  
*/


int a[]={0,0,0,0,0,0,0,1,1,1,1,1};
int ans;
int ans1;
void dfs(int g[3][4],int i,int j){//去搜索相邻的路径是否可以走 

	g[i][j]=0;//走过的标记0 
	//可以往上走  
	if(i-1>=0&&g[i-1][j]==1) dfs(g,i-1,j); 
	//可以往下走  
	if(i+1<=2&&g[i+1][j]==1) dfs(g,i+1,j); 
	//可以往左走  
	if(j-1>=0&&g[i][j-1]==1) dfs(g,i,j-1); 
	//可以往右走  
	if(j+1<=3&&g[i][j+1]==1) dfs(g,i,j+1); 	
}

bool check(){

	int g[3][4];//将一维变化映射到二维变化 
	for(int i=0;i<3;++i){
		for(int j=0;j<4;++j){
			if(a[i*4+j]==1) g[i][j]=1;
			else g[i][j]=0;  
		}
	} //映射完成 
	 int cnt=0;
	 //对g数组遍历看是否标记为1的是连通路径 
	 for(int i=0;i<3;++i){
	 	for(int j=0;j<4;++j){
	 		if(g[i][j]==1){    //如果标记为1路径长度为5的这个路径是连通  
	 			dfs(g,i,j);    // 那么去走这么一个路径 走过的置为0 
	 			cnt++;			// 如果第一次一次性走完则地图全0 ans=1；否则不连通 
	 		}
	 	}
	 } 
	
	return cnt==1;
}

void f(int k){ // 全排列  
	
	if(k==12){
		if(check()){//检查是否是连通  
			ans++;
		}
	}
	
	for(int i=k;i<12;++i){
		{
			int t=a[i]; a[i]=a[k]; a[k]=t;//交换 
		}
		f(k+1); //确定k+1位  
		{
			int t=a[i]; a[i]=a[k]; a[k]=t;//回溯 
		}
	}
	
	
}
void f1(){
	do{
		
		if(check()){
			ans1++;
		}
		
	}while(next_permutation(a,a+12));

}

int main(int argc, char *argv[]) {
	
	f1();
//	f(0);
	cout<<ans1<<endl;
//	cout<<ans<<endl;
	return 0;
}










