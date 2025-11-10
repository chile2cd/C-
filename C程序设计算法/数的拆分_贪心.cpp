#include <iostream>
#include <bits/stdc++.h>
#include<sstream>
using namespace std;
///* run this program using the console pauser or add your own getch, system("pause") or input



#include <iostream>
#include <cmath>
using namespace std;
char* mul(string,string);
int n;
const int N = 200;
int a[N];//用数组来存储拆分的连续自然数 两个数相乘 肯定大于两个数相加  

string i2s(int num){ //将int类型转换成string类型  
	stringstream ss;
	string t(1,'0');
	ss<<num;
	ss>>t;
	return t;
}

int main()
{
	
    cin>>n;
    int sum = n;//sum用于保证自然数之和为n
    if(n == 0 || n == 1 || n == 2)//n为0，1，2时，无需拆分，直接输出本身
    {
        cout<<n<<endl;
        return 0;
    }
	int i = 0;
    for(i = 2 ;i < n ;i ++)//被拆分的数从2开始 
    {
        if(sum < i)//当sum<i时，接下来sum-i操作会直接使sum<0,所以要做判断 
            break;
        a[i-2] = i;//从0开始存储连续自然数
        sum -= i;
	}
   while(sum > 0)//sum>0说明有多余项，要把它平均分配到前面各个项中
   {
       for(int j=i-3;j>=0;j--)//优先考虑后面项。从后往前分配能保证优先分配给较大的项
       {
           if(sum > 0)
           {
               a[j]++;
               sum--;
			}
           else
               break;
	   }
   }
    string ans="1";
    for(int j = 0;j<i - 2;j++)
       {
       	ans=mul(ans,i2s(a[j]));
        cout<<a[j]<<" ";
       } 
    cout<<"\n"<<ans<<endl;
    
	return 0;

}





int ans[1000];
char result[1000];
//大数乘法 第i位数乘第j位数，乘积是第i+j位数(从0开始)
char* mul(string s1,string s2){
	//123 * 456    123
	//		123		23
 	if(s1[0]=='0'||s2[0]=='0'){
 		
 		result[0]='0';
 		return result;
 	}
 	
	int len1=s1.length();
	int len2=s2.length();
	memset(ans,0,sizeof(int)*1000);
	memset(result,'0',sizeof(char)*1000);
	
	for(int i=0;i<len1;i++){
		for(int j=0;j<len2;j++){
			//从后往前 模拟人手算乘法 
			ans[i+j]+=(s1[len1-1-i]-'0')*(s2[len2-1-j]-'0');
			
		}
	}
	int i=0;
	for(;i<len1+len2;i++){
		if(ans[i]>9)
		{
			ans[i+1]+=ans[i]/10; //第i位超过10 i+1位就进位  
			ans[i]%=10;          // 第i位即是相加保留个位  
		}
	}
	
	while(ans[i]==0)
		i--; //去0 
		
	int k=0;
	
	while(i>=0){
		result[k++]=ans[i]+'0'; // 将int转换成 
		i--;
	}
	result[k]='\0';	
	return result;
} 













