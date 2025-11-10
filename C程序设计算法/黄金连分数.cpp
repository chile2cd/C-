#include<iostream>
#include<string> 
#include<algorithm>
#include<sstream>
using namespace std;

int n=250;

string add(string a,string b)
{
	a=a.substr(a.find_first_not_of('0'));
	b=b.substr(b.find_first_not_of('0'));
	
	long long lenA=a.length();
	long long lenB=b.length();
	long long len=max(lenA,lenB)+10;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());  	//反转字符串 好做加分进位 
	
	string ans(len,'0');
// 把a拷贝到ans中	
	for(int i=0;i<lenA;++i)
	{
		ans[i]=a[i];
	}
	int temp=0;						// 9999+11
	for(int j=0;j<len;++j)   		//18+1281 -> 1821+81 ->64
	{	
		if(j<b.length())			// 以拷贝a到 temp 则遍历b的长度!!! 
		{
			temp+=(ans[j]-'0')+(b[j]-'0');  //temp 进位 
		}else
		{
			temp+=(ans[j]-'0');
		}
			ans[j]=temp%10+'0';
			temp=temp/10;
	}
	reverse(ans.begin(),ans.end()); 
	
	return ans.substr(ans.find_first_not_of('0'));
}

string substract(string a,string b)
{
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	
	// 按位做减法
	//string ans=a;
	for(int i=0;i<b.length();++i)
	{
		if(a[i]>=b[i])
		{
			a[i]=a[i]-b[i]+'0';
			
		}
		else//借一 
		{
			int k=1;
			while(a[i+k]=='0')
			{
				a[i+k]='9';
				k++;
			}
			
			a[i+k]=a[i+k]-'1'+'0'; //到这一位借一 
			a[i]=(a[i]-'0')+10-(b[i]-'0')+'0';	
		}
	}
	reverse(a.begin(),a.end());
	
	if(a.find_first_not_of('0')==string::npos) return "0";
	return a.substr(a.find_first_not_of('0')); 
	
	
}
int  cmp(string a,string b)
{
	if((a.find_first_not_of('0'))==string::npos) a='0';
	else a=a.substr(a.find_first_not_of('0'));
	if((b.find_first_not_of('0'))==string::npos) b='0';
	else b=b.substr(b.find_first_not_of('0'));
	
	
	if(a.length()>b.length())
		return 1;
	else if(a.length()<b.length())
		return -1;
	else 
		if(a>b)return 1;
		if(a<b)return -1;
		else return 0;
}



void i2s(int num,string & b)
{
	b[0]=b[0]+num; 
	 	
}

// 大数除法  转换成减法 
string divide(string a,string b)
{
	// 只考虑a<b的情况 
	string ans="0.";
	
	for(int i=0;i<101;++i)
	{
		a.append("0");
		int num=0;
		while(cmp(a,b)>=0) //a>b 
		{
			a=substract(a,b);
			num++;
		}
		
		string t_ans(1,'0');
	
		i2s(num,t_ans);
	
		ans.append(t_ans);
	}
	

	return ans;
}


int main()
{
	string a="1";
	string b="4";
//	for(int i=3;i<=n;++i)
//	{
//		string temp=b;
//		b=add(a,b);
//		a=temp;
//		
//	}
	string ans =divide(a,b);
	cout<<ans<<endl;
//0.61803398874989484820458683436563811772030917980576286213544862270526046281890244970720720418939113748
//0.61803398874989484820458683436563811772030917980576286213544862270526046281890244970720720418939113748
//0.61803398874989484820458683436563811772030917980576286213544862270526046281890244970720720418939113748
//	string a="123456";
//	
//	int b=(a[8]-'0');
//	cout<<divide(a,b)<<endl;

	return 0;
	//cout<<" "<<endl;
} 












