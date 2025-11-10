#include <iostream>
#include <string>
#include <string.h>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop 

共 2 行。

第一行为一个字符串，表示密钥 kk，长度不超过 100，其中仅包含大小写字母。

第二行为一个字符串，表示经加密后的密文，长度不超过 1000，其中仅包含大小写字母。

CompleteVictory
Yvqgpxaimmklongnzfwpvxmniytm 
Wherethereisawillthereisaway

Wherethereisawillthereisaway
*/

char key[100];
char str[1000];
char ans[1000];

// 根据key还原 c 
char ChangStr(char c,char c_key){//c表示加密后的字符 key密钥  
	
	// 如果是密钥大写 还原大写或者小写   
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
	if(c_key>=97&&c_key<=122){//密钥小写  还原大写或者小写
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








