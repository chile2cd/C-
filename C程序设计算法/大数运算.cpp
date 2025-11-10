#include <iostream>
#include<string>
#include<string.h>
#include<sstream>
#include<algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int s2i(string& a){    //字符串string类型转换成 int  
	int num;
	stringstream ss;
	ss<<a;
	ss>>num;
	return num;
}

void i2s(int num,string& s){ // 数int 转换成 string类型  
	stringstream ss;
	ss<<num;
	ss>>s;
} 

//大数比较大小 
int cmp(string a,string b){
	
	if((a.find_first_not_of('0'))==string::npos) a='0';
	else a=a.substr(a.find_first_not_of('0'));
	if((b.find_first_not_of('0'))==string::npos) b='0';
	else b=b.substr(b.find_first_not_of('0'));
	
	if(a.length()>b.length())
		return 1;
	else if(a.length()<b.length())
		return -1;
	else{//a b 长度相等  
		for(int i=0;i<a.length();++i){
			if(a[i]>b[i]) return 1;
			if(a[i]<b[i]) return -1; 
		}
	}
	return 0;  // 两个数相等返回0  
} 

//大数加法  
string ex_add(string a,string b){
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end()); //先转置 再补0  
	
	// 123456789+1234567
	
	int len=(a.length()>b.length() ? a.length():b.length());
	
	string ans(len+10,'0'); //初始化结果长度  
	
	if(a.length()>b.length()){
		int k=a.length()-b.length();//如果位数不一样 在少的补0 
		for(int i=0;i<k;++i){
			b+='0';
		} 
	}else{
		int k=b.length()-a.length();
		for(int i=0;i<k;++i){
			a+='0';
		} 
	}
	int temp;
	int j=0;//表示进位
	int i=0 ; 
	for(;i<len;++i){
		temp=a[i]-'0'+b[i]-'0'+j;
		ans[i]=temp%10+'0';//数字转字符串  
		if(temp>=10){
			j=1;
		}
	}
	ans[i]=j+'0';
	reverse(ans.begin(),ans.end());
	
	return ans.substr(ans.find_first_not_of('0'));
	
} 

//大数减法  
string ex_substract(string a,string b){
	if(cmp(a,b)==0)return "0";
	int flag=0;
	if(cmp(a,b)==-1){ //如果a<b  
		a.swap(b);
		flag=1;
	}
	 
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	// 默认b的长度比a短  5555343-39932
	int k=0;int i;
	for(i=0;i<b.length();++i){
		if(a[i]>=b[i]){
			a[i]=k+a[i]-b[i]+'0';
		//	k=0;// 扣完一标志回归初始  
		}else{ //a[i]<b[i]不够减 借一  
			k=1;
			while(a[i+k]=='0')
			{
				a[i+k]='9';
				k++;
			}  //100000 -1 --> 000001-1  
			a[i+k]=a[i+k]-'1'+'0'; //到这一位借一 处理0被减的情况   
			a[i]=(a[i]-'0')+10-(b[i]-'0')+'0';
		}
	}
	
	reverse(a.begin(),a.end()); 
	string ans1('0',a.length()+1);
	ans1=a.substr(a.find_first_not_of('0')); //剔除转置前为0的情况
	if(flag){
		ans1+='0';
		for(int i=ans1.length();i>=1;i--){
			ans1[i]=ans1[i-1];
		}ans1[0]='-'; //112233
	}
	if(a.find_first_not_of('0')==string::npos) return "0";

	return ans1; 
	
}


//大数除法 -> 转换成减法 
string min_divide(string a,string b){ //a<b的情况单独写成函数  
	string _a=a; //拷贝a
		string ans="0.";
	
		int k=101; //保留101位小数 
		for(int i=0;i<101;i++){
			int num=0;
			_a.append("0");
			while(cmp(_a,b)==1 || cmp(_a,b)==0) //如果a>b 继续做减法 减多少次就意味着商多少  
			{
				_a=ex_substract(_a,b); // 减到a<b 为止  
				num++; 
				
			}	
			string t_ans(1,'0');// 初始化追加的字符串 
			i2s(num,t_ans);
			// 每次的商追加到ans中 
			ans.append(t_ans); 
		}	
	return ans;
}
string ex_divide(string a,string b){
	string ans="";
	string _a=a; //拷贝a
	if(cmp(a,b)==0) return "1";	
	
	if(cmp(a,b)==-1){
		
		string t_ans=min_divide(a,b);  // 调用a<b 情况的除法函数  
		ans.append(t_ans);
	}else if(cmp(a,b)==1)
	{// a大于b  
		
	  
		string t_ans(1,'0');// 初始化追加的字符串 
		int num=0;
		int k=101; //保留101位小数 
	
		while(cmp(_a,b)==1 || cmp(_a,b)==0) //如果a>b 继续做减法 减多少次就意味着商多少  
		{
			_a=ex_substract(_a,b); // 减到a<b 为止  
			num++; 
		}
		//将被数转换成字符  
		i2s(num,t_ans);
		// 每次的商追加到ans中 
		ans.append(t_ans); 
		
		string t_ans2=min_divide(_a,b); //"0.xxx"  //当除不尽适合a<b调用小除法  
		
		t_ans2=t_ans2.substr(t_ans2.find_first_not_of('0'));
		
		ans.append(t_ans2);
	}
	
	return ans;
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
			
			ans[i+j]+=(s1[len1-1-i]-'0')*(s2[len2-1-j]-'0');//从后往前  
			
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

int main(int argc, char *argv[]) {
	string a; 
	int ans;
	string b;
	string c;
	cin>>a>>b;
	c=mul(a,b);
	cout<<c;
	return 0;
}











