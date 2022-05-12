#include <bits/stdc++.h>
using namespace std;
int a[100001];
long long sum;
int n;
int _find(int num);
int main() {
	//freopen("clear.in", "r", stdin);
	//freopen("clear.out", "w", stdout);
	int l = 1, r = l;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i)
	{
		int j = _find(-a[i]);
		if (j != -1){ //找到返回下标 没找到返回-1
			sum += abs(a[i]);
			a[i] = 0;
			a[j] = 0;
		}
	}
	printf("%d", sum);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

int _find(int num){  //二分查找又称为折半查找  前提要是数组已经是有序的 
	int left = 0;
	int right = n - 1;

	int j = -1;
	while (left <= right)
	{
		int mid = (left + right) >> 1;//求出中间下标 每次对数组砍一半
		if (num == a[mid]) //如果找到了
		{
			j = mid;   // 记录找到的下标 

		}
		if (num > a[mid])  // 要找的数比中间的数大 则我们要的数在数组右半部分
			left = mid + 1;
		else
		{
			right = mid - 1; // 要找的数比中间的数小 则我们要的数在数组左半部分
		}
	}
	return j;  //返回下标 如果j没有在while被改变 那么意味着没有找到 返回-1 
	//如果找到了就返回相应的值
}







