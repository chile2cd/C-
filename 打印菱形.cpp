#include <iostream>
#include<string>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop 
.......*
......*.*
.....*...*
....*.....*
...*.......*
..*.........*
.*...........*
*.............*
.*...........*
..*.........*
...*.......*
....*.....*
.....*...*
......*.*
.......*
*/


void f(int n);//��ӡn�߳������� 
int main(int argc, char *argv[]) {
	f(8);	
	return 0; 
}
void f(int n){
	
	
	// �м䲿�ֳ�ʼ��
	string s="*";
	for(int i=0;i<2*n-3;++i){
		s+=".";
	}
	s+="*";//
	
	string s1=s+"\n"; //s1��ʼ��Ϊs  
	string s2="";
	
	for(int i=0;i<n-1;++i){
		s="."+s.substr(0,s.length()-3)+"*";
		s1=s+"\n"+s1;
		s2+=s+"\n";
	}
	cout<<s1+s2<<endl;
}










