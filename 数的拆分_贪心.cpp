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
int a[N];//���������洢��ֵ�������Ȼ�� ��������� �϶��������������  

string i2s(int num){ //��int����ת����string����  
	stringstream ss;
	string t(1,'0');
	ss<<num;
	ss>>t;
	return t;
}

int main()
{
	
    cin>>n;
    int sum = n;//sum���ڱ�֤��Ȼ��֮��Ϊn
    if(n == 0 || n == 1 || n == 2)//nΪ0��1��2ʱ�������֣�ֱ���������
    {
        cout<<n<<endl;
        return 0;
    }
	int i = 0;
    for(i = 2 ;i < n ;i ++)//����ֵ�����2��ʼ 
    {
        if(sum < i)//��sum<iʱ��������sum-i������ֱ��ʹsum<0,����Ҫ���ж� 
            break;
        a[i-2] = i;//��0��ʼ�洢������Ȼ��
        sum -= i;
	}
   while(sum > 0)//sum>0˵���ж����Ҫ����ƽ�����䵽ǰ���������
   {
       for(int j=i-3;j>=0;j--)//���ȿ��Ǻ�����Ӻ���ǰ�����ܱ�֤���ȷ�����ϴ����
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
//�����˷� ��iλ���˵�jλ�����˻��ǵ�i+jλ��(��0��ʼ)
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
			//�Ӻ���ǰ ģ��������˷� 
			ans[i+j]+=(s1[len1-1-i]-'0')*(s2[len2-1-j]-'0');
			
		}
	}
	int i=0;
	for(;i<len1+len2;i++){
		if(ans[i]>9)
		{
			ans[i+1]+=ans[i]/10; //��iλ����10 i+1λ�ͽ�λ  
			ans[i]%=10;          // ��iλ������ӱ�����λ  
		}
	}
	
	while(ans[i]==0)
		i--; //ȥ0 
		
	int k=0;
	
	while(i>=0){
		result[k++]=ans[i]+'0'; // ��intת���� 
		i--;
	}
	result[k]='\0';	
	return result;
} 













