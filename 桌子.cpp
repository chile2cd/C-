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
						//	����  
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
struct peanuts{//�ýṹ��������������ʱ�䡣��x��y���꣬timeʱ�䣬w������
    int x,y,time,w;
}p[1000001]; //�ṹ���±���������
int a[21][21];//����2ά���������������ݡ�
int main(){
    cin>>m>>n>>t;
    for(i=1;i<=m;i++)
       for(j=1;j<=n;j++){
          cin>>a[i][j];//������ɡ�
             if(a[i][j]>0) {//���������л�����ʱ��ʹ��������ݡ�
             p[k].w=a[i][j];
             p[k].x=i;
             p[k].y=j;
             k++;
         }
      }
    for(i=1;i<k;i++)
       for(j=i+1;j<=k;j++)
          if(p[i].w<p[j].w)  swap(p[i],p[j]);//ѡ���������±�������������İ�������ժ����
     for(i=1;i<=k;i++){//ö��ÿ��������
         u=p[i].x;//���ص�·�̣���������Ҫ���Ƕ��ɻ������أ������ص�·�̾�����ȼ�x������������x���԰�ʱ���صĻ��Ͳ����������
            if(i==1) p[i].time=p[i].x+1;  //��һ�������ǲ�ͬ�ģ���Ϊ���һ��ʼ����������һ����໨���������С�
              else   p[i].time=p[i-1].time+abs(p[i].x-p[i-1].x)+abs(p[i].y-p[i-1].y)+1;//���ǵ�һ���Ļ��ͼ�����ǰһ����������ټӲ�ժʱ�䡣
                 if (p[i].time+u<=t) ans+=p[i].w;//������ݺϷ���ô�Ͱѻ��������ϡ�
     }
    cout<<ans;//�����໨�������ɡ�
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













