#include <iostream>
#include <string>
#include <string.h>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop 

�� 2 �С�

��һ��Ϊһ���ַ�������ʾ��Կ kk�����Ȳ����� 100�����н�������Сд��ĸ��

�ڶ���Ϊһ���ַ�������ʾ�����ܺ�����ģ����Ȳ����� 1000�����н�������Сд��ĸ��

CompleteVictory
Yvqgpxaimmklongnzfwpvxmniytm 
Wherethereisawillthereisaway

Wherethereisawillthereisaway
*/

char key[100];
char str[1000];
char ans[1000];

// ����key��ԭ c 
char ChangStr(char c,char c_key){//c��ʾ���ܺ���ַ� key��Կ  
	
	// �������Կ��д ��ԭ��д����Сд   
	if(c_key>=65&&c_key<=90){
		int back=c_key-'A'; 
		char k=c-back;
		if(c>=97&&c<=122)
		{
			if(k<'a') k=k+26; 
		} 
		
		else{
			if(k<'A') k=k+26;
		} 
		return k; 
	}
	if(c_key>=97&&c_key<=122){//��ԿСд  ��ԭ��д����Сд
		int back=c_key-'a';
		char k=c-back;
		if(c>=97&&c<=122)
		{
			if(k<97) k=k+26; 
		}
		
		else{
			if(k<65) k=k+26;
		} 
		return k; 
	}
	
}

int main(int argc, char *argv[]) {

	cin>>key;
	cin>>str;
	int len_k=strlen(key);
	int len_s=strlen(str);
	
	for(int i=0;i<len_s;++i){
		ans[i]=ChangStr(str[i],key[i%len_k]);
	}
	
	cout<<ans;
	
//	char a='a';
//	a=a+1;
//	cout<<a;
	
	
	return 0;
}








