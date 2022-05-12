#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;

int n, a[N], dp[N], res = -9999999;

struct Node{
	int left;
	int right;
	int sum;
}node;
int ret[N];
//O(n) 
void fun1(){
	int k=1;
	for (int i = 1 ; i <= n ; i ++ ){
        dp[i] = max(dp[i - 1] + a[i], a[i]);//状态转移方程->选or不选a[i]
        if(dp[i]==a[i]){
        	ret[k++]=0;
        }else{
        	ret[k++]=1;
        }
        res = max(res, dp[i]);
        
    }
    int left,right;
	right=k-1;
    if(ret[k-1]==0){
    	left=right;
    }else{//ret[k]==1 说明以k结尾 
    	for(int i=k-1;i>=0;--i){
    	 	if(ret[i]==0){
    	 		left=i;
    	 		break;
    	 	}
   	    }
    }
    
//    for(int i=0;i<k;++i){
//    	cout<<ret[i]<<" ";
//    }
    
    printf("\n最大子数组是从%2d到%2d\n和为%2d\n", left, right, res);
    //cout << res;
}

//O(nlgn)
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
		int mid = low + ((high - low) >> 1);
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
void fun2(){
	
	struct Node* ans = findmax(a, 1, n);

	printf("最大子数组是从%2d到%2d\n和为%2d\n", ans->left, ans->right, ans->sum);
	
	
} 

int main(){
    cin >> n;
    for (int i = 1 ; i <= n ; i ++ ) cin >> a[i];
    
    fun2();
 	fun1();
    
    return 0;
}










