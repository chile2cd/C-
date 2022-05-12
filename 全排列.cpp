#include <iostream>
#include<stdio.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop 
123
132
213
231
321
312
*/

void text(int x[])
{
	for(int i=0;i<3;++i)
	{
		cout<<x[i];
	}
	cout<<"\n";
	
}


void f(int x[],int k) // k ´Ó 1 ¿ªÊ¼ 
{
	int i,t;
	
	if(k>=3){
		text(x);  
		return;
	}
	
	for(i=k;i<3;++i)
	{
		t=x[k];
		x[k]=x[i];
		x[i]=t;
		
		f(x,k+1);
		
		t=x[k];
		x[k]=x[i];
		x[i]=t;	
		
	}
} 

int main(int argc, char *argv[]) 
{
	
	
	int a[]={1,2,3};
	f(a,0);
	return 0;
}
