#include <iostream>
using namespace std;

/*
2*N个格子 
*  *    
*  **

*/ 

const long long MOD = 1e9 + 7;

const int maxn = 1e7 + 100;
long long dp[maxn];

void f(int n){
	
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 5;
	for (int i = 4; i <= n; i++) {
		// 注意每次相加后都要取余
		dp[i] = (((((dp[i - 1] + dp[i - 2]) % MOD) + dp[i - 3] * 2) % MOD) + 
		dp[i - 4] * 2) % MOD;
	}
	cout << dp[n] << endl;

}
void f2(int n){
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
	for(int i=3;i<=n;++i){
		dp[i]=dp[i-1]+dp[i-2]+dp[i-3]*2;
	}
	cout << dp[n] << endl;
}
int main() {
	int n;
	cin >> n;
	f(n);
	return 0;
}

