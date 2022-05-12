#include <iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

void swap(char &a,char &b)
{
	char t=a;
	a=b;
	b=t;
}
int max(int a,int b){
	return a>b? a:b;
}
char* rev(char* s)
{
	int len=sizeof(s)/sizeof(char);
	char* ans=(char*)malloc(sizeof(s));
	for(int i=0;i<len;++i)
	{
		ans[i]=s[len-1-i];
	}
	return ans;
}

int lcs(char* s1,char* s2)
{
	int len=sizeof(s1)/sizeof(char);       
	
	int dp[len][len];
	for(int i=0;i<len;++i)
	{
		if(s1[i]==s2[0])//初始化第一行 
			dp[0][i]=1;
		else dp[0][i]= (i==0 ? 0 : dp[0][i-1]);
		
		// 初始化第一列  
		if(s1[0]==s2[i])
			dp[i][0]=1;
		else dp[i][0]= (i==0 ? 0 : dp[i-1][0]);
		
	}
	//填表 
	for(int i=1;i<len;++i){
		for(int j=1;j<len;++j){
			
			if(s1[i]==s2[j]) dp[i][j]=dp[i-1][j-1];
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);	//最长公共子序列 	
		}
	} 
	
	return dp[len-1][len-1];
}
char s[1000];
int main(int argc, char *argv[]) {
	
	cin>>s;

	cout<<lcs(s,rev(s))<<endl;
	
	return 0;
}









 
