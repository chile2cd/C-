#include <bits/stdc++.h>
#include<stdlib.h>
#include"time.h"
using namespace std;
#define random(x) (rand()%x)
int a[2000001], s[2000001], maxn=-999;
void fun1(int n,int s);
void fun2(int n,int s);
struct Node* find_cross_max(int A[], int low, int mid, int high);
struct Node* findmax(int A[], int low, int high);
void fun3();
//void fun4();
/*
10 7
0 2 5 -3 4 -2 8 4 6 5
*/
int main() {
	int n, s;
 	cin >> n >> s;
    srand((int)time(0));
    fun1(n,s);
    //memset(a,0,sizeof(a));
    fun2(n,s);
    cout<<endl;
    for(int i=1;i<=10;++i){
    	printf("%d ",a[i]);
    }
	 
 	return 0;
}

void fun1(int n,int S){

 for (int i = 1; i <= 10; i++) {
		//a[i]= random(15)-5;
		cin>>a[i];
		s[i] = s[i - 1] + a[i];
	}
// for (int i = 1; i <= n; ++i) {
//  for (int j = 1; j <= n; ++j) {
//   int big = i > j ? i : j;
//   int sum = s[big] - s[i + j - big - 1];
//   if (sum <= S)maxn = max(maxn, big - (i + j - big) + 1);
//  }
// }

int sum=0,l,r;
 for (int i=0;i<n;++i){
 	for(int j=i+1;j<=n;++j){   //直接从i+1开始 就不用 int big那些 不过这样还是在暴力求解  
 		sum=s[j]-s[i];         // 应该还会超时 暴力求解应该不能拿满分这题 要用其他方法 
 		if(sum<=S)
		 {
		 	maxn = max(maxn,j-i);
		 }
 	}
 }
 
 printf("%d\n", maxn);
}

void fun2(int n,int s){	
        int num = 0;
        int sum = a[1];
        int i = 1;
        int j = 2;
        for(int _i=1;_i<=n;_i++)
        {
                //找到第一个小于S的下标 计为i     		
      		if(a[_i]<=s)        //找到第一个小于S的数记为sum 长度num=1 
      		{
      			i = _i;
      			j = _i+1;
      			sum = a[_i];
      			num = 1;    
      			break;
      		}
      		
      	}
        while (j <= n) {
            if (sum + a[j] <= s) {
                sum += a[j++];
                num = max(num, j - i);
            } else {
                sum += a[j++];
                while (i <= j && sum > s) {
                    sum -= a[i];
                    i++;
                }
            }
        }
	printf("%d", num); 
 
}

struct Node{
	int left;
	int right;
	int sum;
}node;


struct Node* find_cross_max(int A[], int low, int mid, int high){

	int left_sum = -9999;
	int max_left, max_right;
	int sum = 0;
	for (int i = mid; i >= low; i--){
		sum += A[i];
		if (sum > left_sum){
			left_sum = sum;
			max_left = i;
		}
	}

	int right_sum = -9999;
	sum = 0;
	for (int i = mid + 1; i <= high; i++){
		sum += A[i];
		if (sum > right_sum){
			right_sum = sum;
			max_right = i;
		}
	}
	struct Node* t = new Node;
	t->left = max_left;
	t->right = max_right;
	t->sum = right_sum + left_sum;

	return t;

}

struct Node* findmax(int A[], int low, int high){
	//int ans[3];
	struct Node *leftNode = new Node;
	struct Node *rightNode = new Node;
	struct Node *crossNode = new Node;
	struct Node *ans = new Node;
	/*int left_low, left_high, left_sum;
	int right_low, right_high, right_sum;
	int cross_low, cross_high, cross_sum;*/
	if (low == high){
		ans->left = low;
		ans->right = high;
		ans->sum = A[low];
		return ans;
	}
	else{
		int mid = low + (high - low) >> 1;
		mid = (int)mid;
		leftNode = findmax(A, low, mid);
		rightNode = findmax(A, mid + 1, high);
		crossNode = find_cross_max(A, low, mid, high);
	}
	if (leftNode->sum > rightNode->sum && leftNode->sum > crossNode->sum){
		return leftNode;
	}
	else if (rightNode->sum > leftNode->sum && rightNode->sum > crossNode->sum)
	{
		return rightNode;
	}
	else{
		return crossNode;
	}


}


//void fun3(){
//	int n, s;
// cin >> n >> s;
// for (int i = 1; i <= n; ++i) {
//  cin >> a[i];
// }
//    

//}

//#define N 200010
//int n,sum[N],f[N];
//void fun4(){
//	int n, s;
// cin >> n >> s;
//    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
//    f[1]=sum[1]=a[1];
//    int maxn=a[1]; 
//    for(int i=2;i<=n;i++){
//    	if(sum[i]<=s&&sum[i-1]+a[i]<=s) {
//    		sum[i]=max(sum[i-1]+a[i],a[i]);
//       		f[i]=max(maxn,sum[i]);
//        	maxn=f[i];
//    	}
//        
//    }
//    int ans=-0x7fffffff;
//    for(int i=1;i<=n;i++) ans=max(ans,f[i]);
//    printf("%d\n",ans);
//}






