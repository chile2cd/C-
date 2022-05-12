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
        int p = find_lower_bound(help, i, sum - k );//ʹ�ö��ֲ����ҵ���һ�δ��ڵ���sum-k��λ�� 
        ret = max( ret, i - p );							 
        help[i] = max( sum, help[i - 1] );   //��ΪҪʹ�ö��ֲ��� ���Խ�����������help  
    }										// help[i]��ʾ��i��βǰ���ۼ�����  
    printf("%d\n", ret);
}

void fun2(int n,int k){ //��������˼��  
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
    
    // �ҵ���i�����������Сֵ�Ӷ���
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
    
    // ��ǰ��������Ѱ�ҺͱȽϴ�λ��i����������Ҫ��С�ڵ���k�������鲢�Ƚϳ���
    int len=0, end=0, sum=0;
    for(int i=0; i<n; i++){
        while(end<n && (sum+h[end]<=k)){
            sum += h[end];
            end = ends[end]+1;
        }
        len = max(len, end-i);         // ע�������ѭ���˳�����������endʵ�����Ѿ��ڷ����������������ˣ�����������+1
        sum -= end > i ? arr[i]: 0;    // ͬ��ע�������ѭ�����������endѹ��û����sumֵ��δ���£�����Ҫ�����ٴ��������
        end = max(i+1, end);           // ͬ����ʱendǡ���ڱ߽��⣬����+1
    }
    cout << len;
}

int main(void) {
    scanf("%d%d", &n, &k);
	//fun1(n,k);
	fun2(n,k);
    return 0 ; 
}













