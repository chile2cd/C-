#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std; 


/* run this program using the console pauser or add your own getch, system("pause") or input loop 
ABCADAABBJJCDBA
*/

int min(int a,int b)
{
	return a<b? a:b;
}

char s[10000];
int dfs(char* s,int left,int right,int cnt)
{
	if(left>=right) return cnt;
	if(*(s+left)!=*(s+right))
		return min(dfs(s,left+1,right,cnt+1),dfs(s,left,right-1,cnt+1));
	else
		return dfs(s,left+1,right-1,cnt);
}

int main(int argc, char *argv[]) {
	
	cin>>s;
	int len=strlen(s);
	int ans=dfs(s,0,len-1,0);
	cout<<ans<<endl;
	
	return 0;
}














