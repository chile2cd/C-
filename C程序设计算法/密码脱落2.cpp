#include <iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;


/*

有密码串前后对称 由于年代久远 有些密码脱落 现在
给定一个密码串 求至少脱落多少种子才变成现在这样 ？ 
*/
int max(int a,int b){
	return a>b? a:b;
}
const char* rev(const char* s)
{
	int len=strlen(s);
	char* ans=(char*)malloc(sizeof(char)*len);
	for(int i=0;i<len;++i)
	{
		ans[i]=s[len-1-i];
	}
	return ans;
}

int lcs(const char* s1,const char* s2,int len)
{

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
			
			if(s1[j]==s2[i]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);	//最长公共子序列 	
		}
	} 
	
	return dp[len-1][len-1];
}
char s[1000];
int main(int argc, char *argv[]) {
	//abdcdcbabc
//	cin>>s;

	
	cout<<lcs(s,rev(s),10)<<endl;
//	printf("%s",rev("abcd"));

	return 0;
}









 
