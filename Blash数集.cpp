#include <bits/stdc++.h>
/*
大数学家高斯小时候偶然间发现一种有趣的自然数集合Blah，对于以a为基的集合Ba定义如下：

(1)a是集合Ba的基，且a是Ba的第一个元素；

(2)如果x在集合Ba中，则2x+1
(3)没有其他元素在集合Ba中了。

现在小高斯想知道如果将集合Ba中元素按照升序排列，第N个元素会是多少？
*/
using namespace std;
#define N 1000001
unsigned long long que1[1000001], que2[1000001];
unsigned long long  arr[1000001];
int main() {
 unsigned long long a, n;
 while(cin>>a>>n) {
  unsigned long long x, head1 = 0, tail1 = 1, head2 = 0, tail2 = 1, tot = 0;
  tot = 0;
  memset(arr, 0, sizeof(arr));
  memset(que1, 0, sizeof(arr));
  memset(que2, 0, sizeof(arr));
  x = a;
  while(tot < n) {
   arr[++tot] = x;
   que2[++head2] = x * 3 + 1;
   que1[++head1] = x * 2 + 1;                                                 
   if(que1[tail1] > que2[tail2])
   		x = que2[tail2++];
   else if(que1[tail1] < que2[tail2])
   		x = que1[tail1++];
   else {
    x = que1[tail1++];
    tail2++;
   }
  }
  
  
  for(int i=0;i<40;++i){
  	printf("%3llu ", que1[i]);
  } 
  cout<<endl;
  for(int i=0;i<40;++i){
  	printf("%3llu ", que2[i]);
  }
  cout<<endl;
  for(int i=0;i<40;++i){
  	printf("%3llu ",arr[i]);
  }
  printf("\n%llu ", arr[tot]);
 }
 return 0;
}

//
//void fun1(unsigned long long  a,unsigned long long  n){
//	
//  tot = 0;
//  memset(arr, 0, sizeof(arr));
//  x = a;
//  while(tot < n) {
//   arr[++tot] = x;
//   que2[++head2] = x * 3 + 1;
//   que1[++head1] = x * 2 + 1;                                                 
//   if(que1[tail1] > que2[tail2])
//   		x = que2[tail2++];
//   else if(que1[tail1] < que2[tail2])
//   		x = que1[tail1++];
//   else {
//    x = que1[tail1++];
//    tail2++;
//   }
//  }
//  for(int i=5400;i<=5437;++i){
//  	printf("%llu ", arr[i]);
//  }
//  cout<<endl;
// // for(int i=0;i<40;++i){
////  	printf("%4d ", que1[i]);
////  } 
////  cout<<endl;
////  for(int i=0;i<40;++i){
////  	printf("%4d ", que2[i]);
////  }
//  printf("\n%llu\n",arr[tot]);
//  printf("%d",tot);
//}

//int q[N];
//void fun2(int a,int n){
//	 int head1=1,head2=1,tail=1;
//        q[tail]=a;
//        tail++;
//        while(tail<=n)
//        {
//            int x=q[head1]*2+1;
//            int y=q[head2]*3+1;
//            if(x<y)
//            {
//                q[tail]=x;
//                tail++;
//                head1++;
//            }
//            else if(x>y)
//            {
//                q[tail]=y;
//                tail++;
//                head2++;
//            }
//            else
//            {
//                q[tail]=x;
//                tail++;
//                head1++;
//                head2++;
//            }
//        }
//	for(int i=5400;i<=5473;++i){
//		printf("%4d ",q[i]);
//	}
//	printf("\n%d",q[n]);
//	
//}
//int main() {
// int a, n;
//// scanf("%d%d", &a, &n);
// unsigned long long  a1, n1;
//  scanf("%llu%llu", &a1, &n1);
//fun1(a1,n1);
//printf("\n----------------\n");
// 
//fun2(28,5437);
// return 0;
//}










