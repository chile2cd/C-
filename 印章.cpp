
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
������n��ͼ����ӡ�£�ÿ��ͼ���ĳ��ָ�����ͬ��
СA����m��ӡ�£���СA����n��ӡ�µĸ��ʡ�
һ������������n��m
һ��ʵ��P��ʾ�𰸣�����4λС���� 1��n��m��20
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
	memset(dp, 0, sizeof(dp));//ͷ�ļ���#include<string.h>
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
















