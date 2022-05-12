#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop

杨辉三角形又称Pascal三角形，它的第i+1行是(a+b)i的展开式的系数。
　　
它的一个重要性质是：三角形中的每个数字等于它两肩上的数字相加。

下面给出了杨辉三角形的前4行：

   1
　　
  1 1
　　
 1 2 1
　　
1 3 3 1
　　
给出n，输出它的前n行。
*/

int a[35][35]={0};
void fun(int n){
	
	
	for(int i=0;i<n;++i){
		if(i==0)
			a[0][0]=1;
		for(int j=0;j<=i;j++){
			if(j==0&&i>0){
				a[i][j]=a[i-1][j];
			}else if(j==i&&i>0&&j>0){
				a[i][j]=a[i-1][j-1];
			}else{
				if(i>0&&j>0)
				a[i][j]=a[i-1][j]+a[i-1][j-1];
			}
		}
	}
	// 输出杨辉三角 
	for(int i1=0;i1<n;i1++){
		for(int j1=0;j1<n;j1++){
			if(a[i1][j1]!=0){
				cout<<a[i1][j1]<<" ";
			}
		}cout<<endl;
	} 
	
}

int main(int argc, char *argv[]) {
	int num;
	cin>>num;
	fun(num);
	
	return 0;
}
















