#include <iostream>
#include<algorithm>
using namespace std;



int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13};
int ans=0;

bool check(){
		if(a[0]+a[1]==a[2]
    	&&a[3]-a[4]==a[5]
    	&&a[6]*a[7]==a[8]
    	&&a[9]%a[10]==0
    	&&a[9]/a[10]==a[11]){
    		return true;
    	}
	return false;
}


void f(int k){
	
	if(k==13){
		if(check())ans++;	
		
	}
	
	for(int i=k;i<13;++i){
		
		{int t=a[i]; a[i]=a[k]; a[k]=t;}
		
		if((k==2&&a[0]+a[1]!=a[2]) || (k==5&&a[3]-a[4]!=a[5])
		 || (k==8&&a[6]*a[7]!=a[8]))  {
		 	
		 	int t=a[i]; a[i]=a[k]; a[k]=t;
			 continue;
		 }
		f(k+1);
		
		{int t=a[i]; a[i]=a[k]; a[k]=t;}
	}
	
}

int main()
{
  // 请在此输入您的代码
 

//  do{

//    if(a[0]+a[1]==a[2]
//    &&a[3]-a[4]==a[5]
//    &&a[6]*a[7]==a[8]
//    &&a[9]%a[10]==0
//    &&a[9]/a[10]==a[11]
//    ){
//      ans++;
//    }

//  }while(next_permutation(a,a+13));
	f(0);
    cout<<ans;
  return 0;
}
