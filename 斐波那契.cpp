#include <iostream>
#include<stdio.h>
#include <string.h>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop

����n m mod �� n%m%mod ���ݹ�ģ10^18�η�  
f(x)=f(x-1)+f(x-2)
f1(x)=f(1)+.....f(x)  -->  f1(n)=f(n+2)-1

�ȼ�  (f(n+2)-1)%f(m)%mod 

*/
typedef long long LL;
LL n,m,mod;

void fun1()
{
	int ans=0;

	if(n+2<=m)
	{
     	LL a=1;
    	LL b=1;
    	LL t;
     for(int i=3;i<=n+2;++i)
	 {
		t=b;
		b=a+b;
		a=t;	
	 }
		ans=b%mod-1;
		
	}
	else
	{
		LL a=1;
    	LL b=1; 
    	LL t,ansN,ansM=0;
      for(int i=3;i<=n+2;++i)
	  {
	    	t=b;
	    	b=a+b;
	    	a=t;
	    	if(i==m)
		    	ansM=b;	
	 }
	  ansN=b;
	  ans=ansN%ansM%mod-1;
		
	}
	
	cout<<ans<<endl;
	
	
}

class M{
	
public:
	int a[2][2];
	M(){memset(a,0,sizeof(a));}	
		
}; 

M* mul(M* a,M* b)// ����˷� 
{
	M* ans=new M();
	ans->a[0][0]=(a->a[0][0])*(b->a[0][0])+(a->a[0][1])*(b->a[1][0]);
	ans->a[0][1]=(a->a[0][0])*(b->a[0][1])+(a->a[0][1])*(b->a[1][1]);
	ans->a[1][0]=(a->a[1][0])*(b->a[0][0])+(a->a[1][1])*(b->a[1][0]);
	ans->a[1][1]=(a->a[1][0])*(b->a[0][1])+(a->a[1][1])*(b->a[1][1]);
	return ans;
}
M* pow(M* m,int n)// ������������� �����m��n����  
{
	M* E=new M();
	E->a[0][0]=1;
	E->a[1][1]=1;//��ʼ����λ����  
	
 	while(n!=0){
 		
 		if(n&1)//���һλ��1
		 {
		 	E=mul(E,m);
		 } 
 		m=mul(m,m);
 		n>>=1;
 	}
 	
 	return E;
}
LL fib(LL i)
{
	M* A=new M();
	A->a[0][0]=1; 
	A->a[0][1]=1;
	
	M* B=new M();
	B->a[0][0]=1; 
	B->a[0][1]=1;	
	B->a[1][0]=1;		
	M* ans=mul(A,pow(B,i-2));  // A x B^(i-2)  
	
	return ans->a[0][0];
	
}
// �Ż� 
//�� 쳲�������10^18 �η����� �þ���Ĵ��ݱ�ʾ ���� ���������ÿ���������  1 1 2 3 5
void fun2()
{
	LL ans=0;
	if(n+2>=m){
		ans=(fib(n+2)-1)%mod;
		
	} else{
	LL	ansN=fib(n+2);
	LL	ansM=fib(m);
		ans=ansN%ansM%mod-1;
	}
	cout<<ans<<endl;
}


int main(int argc, char *argv[]) {
	scanf("%lli %lli %lli",&n,&m,&mod);
	fun2(); 
//	for(int i=3;i<=10;++i){
//		cout<<fib(i)<<endl;
//	}
	return 0;
}




















