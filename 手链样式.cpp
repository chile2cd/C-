#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop 

С����3�ź���� 4�Ű���� 5�ź����  �����Ǵ���һ������ 
����С����֪�� ���������������ת�� ���߷�ת ������һ��������ɶ�������ʽ 
˼·��ȫ����ȥ��   
*/
int main(int argc, char *argv[]) {
	int ans=0;
	string s="aaabbbbccccc";
	string s2;
	vector<string> v1;
	do{
		s2=s+s;
		int i=0;
		
		for(;i<v1.size();++i){
			if(v1[i].find(s)!=string::npos) // �������ͬ��������ֹѭ�� i �Ͳ�Ϊsize  
			 break;
		}
		if(i!=v1.size())   // ȥ��  
			 continue;	    
		v1.push_back(s2);  // ��ת 
		reverse(s2.begin(),s2.end()); // ��ת  
		v1.push_back(s2);
		ans++;
		
	} while(next_permutation(s.begin(),s.end()));
	cout<<ans<<endl;
	//1170 
	return 0;
}
