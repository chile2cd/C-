#include <iostream>
#include<string.h>
#include<stdlib.h> 
#include<stdio.h>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop 
����
�������Ƚϴ���������ʱ�����ܻ����������������Ρ�Ϊ���������

���Բ����ַ����ķ�����ʵ����������֮��ĳ˷���������˵���������ַ�������ʽ��������������

ÿ�������ĳ��Ȳ��ᳬ��10λ��Ȼ���������˵Ľ���洢����һ���ַ������У����Ȳ��ᳬ��20λ����

��������ַ�����ӡ������

���磬�����û�����Ϊ��62773417��12345678����������Ϊ��774980393241726.

����д���� void Multiply(char* s1, char* s2, char* result); ʵ�ִ����˷���ֻ������������������result = s1 * s2.
����дmain�������Ըú�������ȷ��.

���룺
����62773417 12345678

�����
����774980393241726
*/
char s1[10];
char s2[10];
int ans[100];
char* result;
void Multiply(char* s1, char* s2, char* result);
int main(){
	memset(s1,'\0',sizeof(s1));
	memset(s2,'\0',sizeof(s2));
	scanf("%s %s",s1,s2);
	result=(char*)malloc(sizeof(char)*21);
	Multiply(s1,s2,result);
	printf("%s",result);
	
	return 0;
} 

void Multiply(char* s1, char* s2, char* result){

	int len1=strlen(s1);
	int len2=strlen(s2);
	memset(ans,0,sizeof(int));
	
	for(int i=0;i<len1;i++){
		for(int j=0;j<len2;j++){
			
			ans[i+j]+=(s1[len1-1-i]-'0')*(s2[len2-1-j]-'0');
			
		}
	}
	int i=0;
	for(;i<len1+len2;i++){
		if(ans[i]>9)
		{
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
	}
	while(ans[i]==0)
		i--; //ȥ0 
	int k=0;
	while(i>=0){
		result[k++]=ans[i]+'0';
		i--;
	}
	result[k]='\0';
	
	
	
	
}






//char a[11];
//char b[11];
//char ans[21];
//void Multiply(char* s1, char* s2, char* result);

//char* rev(char* a,int len){
//	int i=0;
//	char* t=(char*)malloc(sizeof(char)*len+1);
//	while(len>=0){
//		t[i++]=a[len--];
//	}

//	t[i]='\0';
//	return t;
//}
//int main(int argc, char *argv[]) {
//	
//	scanf("%s %s",a,b); 
//	
//	Multiply(a,b,ans);
//	

//	
//	return 0;
//}
//void Multiply(char* s1, char* s2, char* res){
//	
//	int len1=strlen(s1);
//	int len2=strlen(s2);
//	// ��ת�ַ��� 
//	char* _s1=rev(s1,len1-1);
//	char* _s2=rev(s2,len2-1);
//	// ����ü���  
//	char* s11=(char*)malloc(sizeof(char)*20+1);
//	char* s22=(char*)malloc(sizeof(char)*20+1);
//	//char* ans=(char*)malloc(sizeof(char)*20+1);
//	
//	memset(s11,'0',sizeof(s11));
//	memset(s22,'0',sizeof(s22));
//	memset(ans,'0',sizeof(ans));
//	
//	memset(s22,'0',sizeof(s22));
//	for(int i=0;i<len1;++i){
//		s11[i]=_s1[i];
//	}s11[len1]='\0'; 
//	for(int i=0;i<len2;++i){
//		s22[i]=_s2[i];
//	}s22[len2]='\0';
//	
//	//��ʼ�������˷� �˷�ת���ɼӷ�  
//	for(int i=0;i<) 
//	
//	
//	
//	
//	int b,c=0;
//	while(ans[b++]!='\0'){
//		if(ans[b]!='0')
//		ans[c++]=ans[b];
//	}ans[c]='\0';
//	
//	res=rev(ans,c-1);
//	
//	

//}




























