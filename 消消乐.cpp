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
		if (j != -1){ //�ҵ������±� û�ҵ�����-1
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

int _find(int num){  //���ֲ����ֳ�Ϊ�۰����  ǰ��Ҫ�������Ѿ�������� 
	int left = 0;
	int right = n - 1;

	int j = -1;
	while (left <= right)
	{
		int mid = (left + right) >> 1;//����м��±� ÿ�ζ����鿳һ��
		if (num == a[mid]) //����ҵ���
		{
			j = mid;   // ��¼�ҵ����±� 

		}
		if (num > a[mid])  // Ҫ�ҵ������м������ ������Ҫ�����������Ұ벿��
			left = mid + 1;
		else
		{
			right = mid - 1; // Ҫ�ҵ������м����С ������Ҫ������������벿��
		}
	}
	return j;  //�����±� ���jû����while���ı� ��ô��ζ��û���ҵ� ����-1 
	//����ҵ��˾ͷ�����Ӧ��ֵ
}







