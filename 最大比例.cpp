#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop 

输入 N 个整数数 整数小于10^12 求可能的最大比例系数 

3
1250 200 32
25/4

4
3125 32 32 200
5/2 

3
549755813888 524288 2
4/1
*/

typedef long long LL;

LL data[100];

struct Ratio{
	LL x,y;
	Ratio(LL _x,LL _y):x(_x),y(_y){
		LL _gcd=gcd(x,y);
		x/=_gcd;
		y/=_gcd;
	}	
	LL gcd(LL a,LL b){
		if(b==0)return a;
			
	 	return gcd(b,a%b);
	}
}; 
LL extract(LL,LL);
LL getPow(LL,LL); 
void init();
int N;
vector<Ratio> ratios; // 存比值  
int main(int argc, char *argv[]) {
	
	
	scanf("%lld",&N);   // 错误1  %d  ---> %lld  
	for(int i=0;i<N;++i){
		scanf("%lld",&data[i]);
	}
	//排序 
	sort(data,data+N); 
	init();
	//求两两比值 存入vector
	for(int i=0;i<N-1;++i){
		if(data[i+1]!=data[i])
		ratios.push_back (Ratio(data[i+1],data[i]));
	}
	
	if(N==2){
		Ratio ans=Ratio(data[1],data[0]);
		cout<< ans.x<<"/"<<ans.y<<endl;
		return 0;
	}
	
	// 对第一个比值开pow 次方 作为基数 如果这个基数是其他比值的基数的话 该基数就是答案 
	for(int pow=1;pow<=40;pow++){
		Ratio ra0=ratios[0];
		LL x=ra0.x;
		LL y=ra0.y;
		
		LL fx=extract(x,pow);
		LL fy=extract(y,pow);
	
		if(fx==-1 || fy==-1)continue;
		
		bool all_match=true;
		//如果这个基数是其他比值的基数的话 该基数就是答案 
		for(int i=1;i<ratios.size();++i){
			LL xx=ratios[i].x;
			LL yy=ratios[i].y;
			
			LL px=getPow(fx,xx);// fx的多少次方为xx 
			LL py=getPow(fy,yy);// fy的多少次方为yy 
			
			if(yy==1&&fy==1) py=px; // 处理分母为1的情况    这个地方调试了半天 ！！！ 
			
			if(px==-1||py==-1||px!=py){ // long fx xx 不存在  
				all_match=false; 
				break;
			}
		
		}	if(all_match){
				
				Ratio ans=Ratio(fx,fy);
				cout<< ans.x<<"/"<<ans.y<<endl;
				return 0;
		}
	
	}
 
	
getchar();
	return 0;
}
// 映射的是一个集合  >>要分开  
map<LL,map<LL,LL> > all_ex; // all_ex[x][y] x开y次方是多少  
map<LL,map<LL,LL> > all_log; // all_log[x][y] x的多少次方是y  
//对x开pow次方  
LL extract(LL x,LL pow){
	if(pow==1)return x;
	if(x==1)return 1;
	if(all_ex[x].find(pow)!=all_ex[x].end()) // 意味着能开出来整数（初始化里面写好了） 
	
		return all_ex[x][pow];
		
	else 
		return -1;
	
}

// a的多少次方为b  
LL getPow(LL a,LL b){
	if(a==b) return 1;
	if(all_log[b].find(a)!=all_log[b].end())
		return all_log[b][a];
	else return -1; 
	
}  	
void init(){
	
	for(int i=2;i<1e6;++i){ // 枚举i  
		LL cur=(LL)i*i;
		LL pow=2; 
		while(cur<1e12){    // 求 i 的1 2 3 4... 次方 存入map  
			all_ex[cur][pow]=i;
			all_log[cur][i]=pow;
			pow++;
			cur*=i;
			
		}
		
	}
}






