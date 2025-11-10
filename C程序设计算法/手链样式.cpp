#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop 

小明有3颗红玛瑙 4颗白玛瑙 5颗红玛瑙  用它们串成一副手链 
现在小明想知道 如果考虑手链可以转动 或者翻转 求手链一共可以组成多少种样式 
思路：全排列去重   
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
			if(v1[i].find(s)!=string::npos) // 如果有相同的立刻终止循环 i 就不为size  
			 break;
		}
		if(i!=v1.size())   // 去重  
			 continue;	    
		v1.push_back(s2);  // 旋转 
		reverse(s2.begin(),s2.end()); // 翻转  
		v1.push_back(s2);
		ans++;
		
	} while(next_permutation(s.begin(),s.end()));
	cout<<ans<<endl;
	//1170 
	return 0;
}
