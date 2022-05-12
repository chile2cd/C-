//#include <bits/stdc++.h>

//using namespace std;
//bool a[200001], b[200001][3];
//int a_num, b_num, n, t[200001], cnt_a, cnt_b, answer;
//int main() {
//	scanf("%d%d%d", &n, &a_num, &b_num);
//	for (int i = 1; i <= n; ++i) {
//		scanf("%d", &t[i]);
//		bool flag = false;
//		if (t[i] == 2) {
//			if (cnt_b + 1 <= b_num){
//				b[++cnt_b][1] = true;
//				b[cnt_b][2] = true;
//			}
//			else answer += 2;
//		}
//		else {
//			if (cnt_a + 1 <= a_num){
//				a[++cnt_a] = true;
//			}
//			else {
//				if (cnt_b + 1 <= b_num){
//					b[++cnt_b][1] = true;
//				}
//				else {
//					for (int i = 1; i <= b_num; ++i) {
//						if (b[i][1] == true && b[i][2] == false) {
//							b[i][2] = true;
//							break;
//						}
						//	少了  
//					}
//				}
//			}
//		}
//	}
//	printf("%d", answer);
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int n, a, b, hb = 0, ans;
//int x;
//int main()
//{
//	cin >> n >> a >> b;
//	for(int i = 1; i <= n; i++)
//	{
//		cin >> x;
//		if(x == 1)
//		{
//			if(a >= 1)
//				--a;
//			else if(b >= 1)
//			{
//				--b;
//				hb++;
//			}
//			else if(hb >= 1)
//				hb--;
//			else
//				ans++;
//		}
//		else
//		{
//			if(b >= 1)
//				--b;
//			else
//				ans += 2;
//		}
//	}
//	cout << ans;
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//int book_row[505],book_column[505],m,n,k,maxx=-1,cnt_peanuts,x,y,cnt_caizhai=0;bool a[505];
//int main() {
//	scanf("%d%d%d",&m,&n,&k);
//	for(int i=1;i<=m;++i)
//		for(int j=1;j<=n;++j) {
//			int temp;
//			scanf("%d",&temp);
//			if(temp!=0) {
//				book_row[temp]=i;
//				book_column[temp]=j;
//				cnt_peanuts++;
//				a[temp]=true;
//			}
//			maxx=max(maxx,temp);
//		}
//	y=book_column[maxx];
//	while(k-abs(x-book_row[maxx])-abs(y-book_column[maxx])>=abs(book_row[maxx]-x)+abs(book_column[maxx]-y)+
//	book_row[maxx]+1&&cnt_peanuts!=0) {
//		k-=abs(x-book_row[maxx])+abs(y-book_column[maxx]);
//		cnt_peanuts--;
//		cnt_caizhai+=maxx;
//		a[maxx]=false;
//		
//		for(int i=maxx;i>=1;--i)
//		if(a[maxx]==true)
//		{
//			maxx=i;
//			break;
//		}
//	}
//	printf("%d",cnt_caizhai);
//	return 0;
//} 



#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int m,n,i,j,k=1,t,u,ans;
struct peanuts{//用结构体存坐标和数量及时间。（x，y坐标，time时间，w数量）
    int x,y,time,w;
}p[1000001]; //结构体下标用来排序。
int a[21][21];//开个2维数组用来输入数据。
int main(){
    cin>>m>>n>>t;
    for(i=1;i<=m;i++)
       for(j=1;j<=n;j++){
          cin>>a[i][j];//输入完成。
             if(a[i][j]>0) {//当它下面有花生的时候就存它的数据。
             p[k].w=a[i][j];
             p[k].x=i;
             p[k].y=j;
             k++;
         }
      }
    for(i=1;i<k;i++)
       for(j=i+1;j<=k;j++)
          if(p[i].w<p[j].w)  swap(p[i],p[j]);//选择排序（用下标来排序，数量多的按题意先摘）。
     for(i=1;i<=k;i++){//枚举每个花生。
         u=p[i].x;//返回的路程，由于我们要考虑多多采花生返回，而返回的路程就是深度即x，如果加上这个x可以按时返回的话就采这个花生。
            if(i==1) p[i].time=p[i].x+1;  //第一个花生是不同的，因为多多一开始可以跳到第一个最多花生的所在列。
              else   p[i].time=p[i-1].time+abs(p[i].x-p[i-1].x)+abs(p[i].y-p[i-1].y)+1;//不是第一个的话就加上与前一个的坐标差再加采摘时间。
                 if (p[i].time+u<=t) ans+=p[i].w;//如果数据合法那么就把花生数加上。
     }
    cout<<ans;//输出最多花生数即可。
    return 0;
}




//#include<bits/stdc++.h>
//using namespace std;
//int a[105][105],b[105][105];
//int main(){
//	int n,m,ans=-999;
//    cin>>n>>m;
//    for (int i=1;i<=n;i++)
//        for (int j=1;j<=m;j++){
//            cin>>a[i][j];
//            if (a[i][j]==1) b[i][j]=min(min(b[i][j-1],b[i-1][j]),b[i-1][j-1])+1;
//            ans=max(ans,b[i][j]);
//        }
//    cout<<ans;
//      
//    return 0;
//}













