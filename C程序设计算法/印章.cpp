
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
　共有n种图案的印章，每种图案的出现概率相同。
小A买了m张印章，求小A集齐n种印章的概率。
一行两个正整数n和m
一个实数P表示答案，保留4位小数。 1≤n，m≤20
2 3
0.7500
*/ 
#include<iostream>
#include<cmath>
#include<string.h>
#include<stdio.h> 
using namespace std;
int main() 
{
	int n, m;
	double dp[21][21];
	memset(dp, 0, sizeof(dp));//头文件加#include<string.h>
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i < j)
				dp[i][j] = 0;
			else if (j == 1)
				dp[i][j] = pow(1.0 / n, i-1);
			else  //dp[i][j]=dp[i-1][j]*(j/n)+dp[i-1][j-1]*(1-(j-1)/n) 
				dp[i][j] = dp[i - 1][j - 1] * (n - j + 1) / n + dp[i - 1][j] * j / n;
		}
	}
	printf("%.4lf", dp[m][n]);
	return 0;
}







//
//#include<iostream>
//#include<stdio.h>
//#include<math.h>
//using namespace std;
//int main() {
//	int n, m;
//	double p;
//	int a[21];
//	a[0] = 1;
//	a[1] = 1;
//	for (int i = 2; i < 20; i++) {
//		a[i] = a[i - 1] * i;
//	}
//	cin >> n >> m;
//	if (n > m) {
//		p = 0;
//		printf("%.4lf", p);
//		return 0;
//	}
//	int t = m - n;
//	p = pow(1.0 / n, n) * a[m] / (a[t] * a[n]);
//	printf("%.4lf", p);
//	return 0;
//}
















