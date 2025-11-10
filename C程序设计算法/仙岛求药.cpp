#include <bits/stdc++.h>

using namespace std;

class kind {
public:
 int x, y, step;
private:

}start, endd, temp;
int n = 1, m = 1;
bool a[21][21],vis[21][21];
int d[4][2] = { {0, 1},{0, -1},{1, 0},{-1, 0} };//°˙£¨°˚£¨°˝£¨°¸°£
void bfs();
int main() {
 while (n&&m) {
  cin>>n>>m;
  memset(a,0,sizeof(a));
  memset(vis,1,sizeof(vis));
  
  if(m==0&&n==0)break;
  for (int i = 1; i <= n; ++i) {
   for (int j = 1; j <= m; ++j) {
    char c;
    cin >> c;
    if (c == '@') {
     start.x = i;
     start.y = j;
     start.step = 1;
    }
    if (c == '*') {
     endd.x = i;
     endd.y = j;
    }
    if (c == '#') {
     a[i][j] = true;
    }
   }
  }
  bfs();
 }
 return 0;
}
void bfs() {

 //memset(vis, 1, sizeof(vis));
 queue<kind> que;
 que.push(start);
 while (!que.empty()) {
  for(int i = 0; i < 4; ++i) {
   int u = que.front().x + d[i][0], v = que.front().y + d[i][1];
   if (u >= 1 && u <= n && v >= 1 && v <= m && !a[u][v] && vis[u][v]) {
    temp.x = u;
    temp.y = v;
    temp.step = que.front().step + 1;
    que.push(temp);
    vis[u][v] = false;
    if (u == endd.x && v == endd.y) {
     printf("%d\n", que.front().step);
     return;
    }
   }
  }
  que.pop();
 }
 puts("-1");
 return;
}
//
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<cmath>
//using namespace std;
//const int N=25;
//int m,n,ex,ey,cnt[N][N],q[N*N][2],dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
//char a[N][N];
//void bfs(int x,int y)
//{
//	memset(cnt,0,sizeof(cnt));
//	int head=0,tail=1;
//	cnt[x][y]=0;
//	q[head][0]=x;
//	q[head][1]=y;
//	a[x][y]='#';
//	while(head<tail)
//	{
//		for(int i=0;i<4;i++)
//		{
//			int dx=q[head][0]+dir[i][0],dy=q[head][1]+dir[i][1];
//			if(dx>=1&&dx<=m&&dy>=1&&dy<=n&&a[dx][dy]=='.')
//			{
//				cnt[dx][dy]=cnt[q[head][0]][q[head][1]]+1;
//				q[tail][0]=dx;
//				q[tail++][1]=dy;
//				a[dx][dy]='#';
//				if(dx==ex&&dy==ey)
//				{
//					cout<<cnt[dx][dy]<<endl;
//					return ;
//				}
//			}
//		}
//		head++;
//	}
//	cout<<-1<<endl;
//}
//int main()
//{
//	int sx,sy;
//	while(cin>>m>>n)
//	{
//		if(m==0&&n==0) break;
//		for(int i=1;i<=m;i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				cin>>a[i][j];
//				if(a[i][j]=='@')
//				{
//					sx=i;
//					sy=j;
//				}
//				if(a[i][j]=='*')//÷’µ„“ª∞„ªØ
//				{
//					ex=i;
//					ey=j;
//					a[i][j]='.';
//				}
//			}
//		}
//		bfs(sx,sy);
//	}
//	return 0;
//}





