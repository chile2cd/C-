#include <bits/stdc++.h>

using namespace std;

class kind {
public:
	int x, y, step;
private:

};
//建立位移数组d  
int d[12][2] = { {2, 1}, {-2, 1}, {1, 2}, {-1, 2} , {1, -2} , {-1, -2} , {2 , -1}, {-2, -1}, 
{-2, -2}, {-2, 2}, {2, -2}, {2, 2} }, 
vis[101][101];//标记数组vis
 
void bfs(kind temp) {
	
	queue<kind> que;


	que.push(temp);//第一个点入队  
	while (!que.empty()) {
		for (int i = 0; i <= 11; ++i) {
			int u = que.front().x + d[i][0], v = que.front().y + d[i][1];
			temp.x = u; //temp走到 u，v  
			temp.y = v;
			temp.step = que.front().step + 1;//步数加一  
			//如果没有越界 并且当前u v 没有被访问  
			if (u > 0 && u < 101 && v > 0 && v < 101 && !vis[u][v]) {
				que.push(temp);  //将访问的节点入队 
				vis[u][v] = true;//标记以访问  
				if (u == v && v == 1) {//探测到 1 1 结束  
					printf("%d\n", que.front().step);
					return;
				}
			}
		}
		que.pop();
	}
}

int main() {
	kind a, b;
	kind temp1,temp2;
	cin >> a.x >> a.y >> b.x >> b.y;
	temp1.x = a.x;
	temp1.y = a.y;
	temp1.step = 1;
	bfs(temp1);
	
	memset(vis,0,sizeof(vis)); 
	
	temp2.x = b.x;
	temp2.y = b.y;
	temp2.step = 1;
	bfs(temp2);
	
	
	return 0;
}








































