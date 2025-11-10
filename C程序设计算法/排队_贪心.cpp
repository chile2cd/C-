#include<bits/stdc++.h>
/*
4
4 9
6 5
2 10
5 6
4

4
4 1
6 1
2 2
5 10


3
10 3
2 5
3 3
2
*/ 
using namespace std;
struct node{
	int l,r,val,hurt;
}f[50001];
bool operator <(node x,node y){
	return x.val==y.val?x.l<y.l:x.val<y.val;
}
int n,ans=0,maxx=-1e9;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&f[i].l,&f[i].r);
		f[i].val=f[i].l+f[i].r;
	}
	sort(f+1,f+1+n);
//	for(int i=1;i<=n;i++)printf("%d %d %d\n",f[i].l,f[i].r,f[i].val);
	for(int i=1;i<=n;i++){
		ans+=f[i].l;
		f[i].hurt=ans-f[i].l-f[i].r;
		maxx=max(maxx,f[i].hurt);
	}
	printf("%d",maxx);
}














