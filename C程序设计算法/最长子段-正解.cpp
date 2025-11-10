//#include<iostream>
//#include<vector>
// https://www.nowcoder.com/questionTerminal/3473e545d6924077a4f7cbc850408ade?f=discussion
//using namespace std;
//https://www.nowcoder.com/questionTerminal/3473e545d6924077a4f7cbc850408ade?f=discussion




#include<bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, k;
int help[N];

int find_lower_bound(int a[],int end,int val){
	int l=0,right=end,mid;
	while(l<right){
		mid=(l+right)>>1;
		if(a[mid]>=val){
			right=mid;
		}else{
			l=mid+1;
		}
	}
	return l;
} 

void fun1(int n,int k){
	int sum = 0;
    int val, ret = 0;
    for ( int i = 1; i <= n; ++i ) {
        scanf("%d", &val);
        sum += val;
        int p = find_lower_bound(help, i, sum - k );//使用二分查找找到第一次大于等于sum-k的位置 
        ret = max( ret, i - p );							 
        help[i] = max( sum, help[i - 1] );   //因为要使用二分查找 所以建立升序数组help  
    }										// help[i]表示以i结尾前面累加最大和  
    printf("%d\n", ret);
}

void fun2(int n,int k){ //滑动窗口思想  
	  // special case
    if (n < 1)
        return ;
    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int h[n], ends[n];
    h[n-1] = arr[n-1];
    ends[n-1] = n-1;
    
    // 找到从i出发的最长的最小值子队列
    for(int i=n-2; i>-1; i--){
        if(h[i+1]<=0){
            h[i] = arr[i] + h[i+1];
            ends[i] = ends[i+1];
        }
        else{
            h[i] = arr[i];
            ends[i] = i;
        }
    }
    
    // 从前往后，依次寻找和比较从位置i出发，满足要求小于等于k的子数组并比较长度
    int len=0, end=0, sum=0;
    for(int i=0; i<n; i++){
        while(end<n && (sum+h[end]<=k)){
            sum += h[end];
            end = ends[end]+1;
        }
        len = max(len, end-i);         // 注意上面的循环退出条件，这里end实际上已经在符合条件的区间外了，所以无需再+1
        sum -= end > i ? arr[i]: 0;    // 同样注意上面的循环条件，如果end压根没动，sum值则未更新，不需要进行再次清零操作
        end = max(i+1, end);           // 同理，此时end恰好在边界外，无需+1
    }
    cout << len;
}

int main(void) {
    scanf("%d%d", &n, &k);
	//fun1(n,k);
	fun2(n,k);
    return 0 ; 
}













