#include <bits/stdc++.h>
using namespace std;
int a[100001], cnt = 0, l1[100001], r1[100001], up[100001], down[100001];
long long sum;
bool comp(int x, int y);
int main() {
 //freopen("clear.in", "r", stdin);
 //freopen("clear.out", "w", stdout);
 int l = 1, r = l;
 int n;
 scanf("%d",&n);
 for(int i = 1; i <= n; ++i) {
  scanf("%d", &a[i]);
 }
 sort(a + 1, a + n + 1, comp);
 
 for(int i = 1; i < n; ++i) {
  if(abs(a[i]) != abs(a[i + 1]) && i != 1) {
   r1[cnt] = i;
   l1[++cnt] = i + 1;
  }
  else if(i == 1 && abs(a[i]) != abs(a[i + 1])) {
   l1[++cnt] = i; 
  }
  if(a[i] < 0)down[cnt]++;
  if(a[i] > 0)up[cnt]++;
 }
 for(int i = 1; i <= cnt; ++i) {
  sum += min(down[cnt], up[cnt]) * abs(a[l1[i]]);
 }
 printf("%d", sum);
 return 0;
}
bool comp(int x, int y) {
 return abs(x) > abs(y);
}
//#define _CRTSECURE_NO_WARNINGS
//#include<iostream>
//#include<string>
//#include <algorithm>
//using namespace std;
//int a[100001],l1[100001], r1[100001], up[100001], down[100001];
//int cnt = 0;
//long long sum;
//bool comp(int x, int y);
//int main() {
//	//freopen("clear.in", "r", stdin);
//	//freopen("clear.out", "w", stdout);
//	int l = 1, r = l;
//	int n;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; ++i) {
//		scanf("%d", &a[i]);
//	}
//	sort(a + 1, a + n + 1, comp);
//	for (int i = 1; i <n; ++i) {
//		int k = 0;
//			cnt++;
//			l1[cnt] = i;
//			while (abs(a[i])==abs(a[i+k]))
//			{
//			
//				if (a[i+k] < 0)down[cnt]++;
//				if (a[i+k] > 0)up[cnt]++;	
//				k++;
//			}
//			r1[cnt] = i + k-1 ;
//			i=i + k-1;
//	
//	}
//	for (int i = 1; i <= cnt; ++i) {
//		if (down[i] >= 1 && up[i]>=1)
//		sum += min(down[i], up[i]) * abs(a[l1[i]]);
//	}
//	printf("%d", sum);
//	//cout << 1;
//	return 0;
//}
//bool comp(int x, int y) {
//	return abs(x) > abs(y);
//}
