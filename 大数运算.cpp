#include <iostream>
#include<string>
#include<string.h>
#include<sstream>
#include<algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int s2i(string& a){    //�ַ���string����ת���� int  
	int num;
	stringstream ss;
	ss<<a;
	ss>>num;
	return num;
}

void i2s(int num,string& s){ // ��int ת���� string����  
	stringstream ss;
	ss<<num;
	ss>>s;
} 

//�����Ƚϴ�С 
int cmp(string a,string b){
	
	if((a.find_first_not_of('0'))==string::npos) a='0';
	else a=a.substr(a.find_first_not_of('0'));
	if((b.find_first_not_of('0'))==string::npos) b='0';
	else b=b.substr(b.find_first_not_of('0'));
	
	if(a.length()>b.length())
		return 1;
	else if(a.length()<b.length())
		return -1;
	else{//a b �������  
		for(int i=0;i<a.length();++i){
			if(a[i]>b[i]) return 1;
			if(a[i]<b[i]) return -1; 
		}
	}
	return 0;  // ��������ȷ���0  
} 

//�����ӷ�  
string ex_add(string a,string b){
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end()); //��ת�� �ٲ�0  
	
	// 123456789+1234567
	
	int len=(a.length()>b.length() ? a.length():b.length());
	
	string ans(len+10,'0'); //��ʼ���������  
	
	if(a.length()>b.length()){
		int k=a.length()-b.length();//���λ����һ�� ���ٵĲ�0 
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
	int j=0;//��ʾ��λ
	int i=0 ; 
	for(;i<len;++i){
		temp=a[i]-'0'+b[i]-'0'+j;
		ans[i]=temp%10+'0';//����ת�ַ���  
		if(temp>=10){
			j=1;
		}
	}
	ans[i]=j+'0';
	reverse(ans.begin(),ans.end());
	
	return ans.substr(ans.find_first_not_of('0'));
	
} 

//��������  
string ex_substract(string a,string b){
	if(cmp(a,b)==0)return "0";
	int flag=0;
	if(cmp(a,b)==-1){ //���a<b  
		a.swap(b);
		flag=1;
	}
	 
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	// Ĭ��b�ĳ��ȱ�a��  5555343-39932
	int k=0;int i;
	for(i=0;i<b.length();++i){
		if(a[i]>=b[i]){
			a[i]=k+a[i]-b[i]+'0';
		//	k=0;// ����һ��־�ع��ʼ  
		}else{ //a[i]<b[i]������ ��һ  
			k=1;
			while(a[i+k]=='0')
			{
				a[i+k]='9';
				k++;
			}  //100000 -1 --> 000001-1  
			a[i+k]=a[i+k]-'1'+'0'; //����һλ��һ ����0���������   
			a[i]=(a[i]-'0')+10-(b[i]-'0')+'0';
		}
	}
	
	reverse(a.begin(),a.end()); 
	string ans1('0',a.length()+1);
	ans1=a.substr(a.find_first_not_of('0')); //�޳�ת��ǰΪ0�����
	if(flag){
		ans1+='0';
		for(int i=ans1.length();i>=1;i--){
			ans1[i]=ans1[i-1];
		}ans1[0]='-'; //112233
	}
	if(a.find_first_not_of('0')==string::npos) return "0";

	return ans1; 
	
}


//�������� -> ת���ɼ��� 
string min_divide(string a,string b){ //a<b���������д�ɺ���  
	string _a=a; //����a
		string ans="0.";
	
		int k=101; //����101λС�� 
		for(int i=0;i<101;i++){
			int num=0;
			_a.append("0");
			while(cmp(_a,b)==1 || cmp(_a,b)==0) //���a>b ���������� �����ٴξ���ζ���̶���  
			{
				_a=ex_substract(_a,b); // ����a<b Ϊֹ  
				num++; 
				
			}	
			string t_ans(1,'0');// ��ʼ��׷�ӵ��ַ��� 
			i2s(num,t_ans);
			// ÿ�ε���׷�ӵ�ans�� 
			ans.append(t_ans); 
		}	
	return ans;
}
string ex_divide(string a,string b){
	string ans="";
	string _a=a; //����a
	if(cmp(a,b)==0) return "1";	
	
	if(cmp(a,b)==-1){
		
		string t_ans=min_divide(a,b);  // ����a<b ����ĳ�������  
		ans.append(t_ans);
	}else if(cmp(a,b)==1)
	{// a����b  
		
	  
		string t_ans(1,'0');// ��ʼ��׷�ӵ��ַ��� 
		int num=0;
		int k=101; //����101λС�� 
	
		while(cmp(_a,b)==1 || cmp(_a,b)==0) //���a>b ���������� �����ٴξ���ζ���̶���  
		{
			_a=ex_substract(_a,b); // ����a<b Ϊֹ  
			num++; 
		}
		//������ת�����ַ�  
		i2s(num,t_ans);
		// ÿ�ε���׷�ӵ�ans�� 
		ans.append(t_ans); 
		
		string t_ans2=min_divide(_a,b); //"0.xxx"  //���������ʺ�a<b����С����  
		
		t_ans2=t_ans2.substr(t_ans2.find_first_not_of('0'));
		
		ans.append(t_ans2);
	}
	
	return ans;
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
			
			ans[i+j]+=(s1[len1-1-i]-'0')*(s2[len2-1-j]-'0');//�Ӻ���ǰ  
			
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











