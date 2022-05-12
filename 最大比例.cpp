#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop 

���� N �������� ����С��10^12 ����ܵ�������ϵ�� 

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
vector<Ratio> ratios; // ���ֵ  
int main(int argc, char *argv[]) {
	
	
	scanf("%lld",&N);   // ����1  %d  ---> %lld  
	for(int i=0;i<N;++i){
		scanf("%lld",&data[i]);
	}
	//���� 
	sort(data,data+N); 
	init();
	//��������ֵ ����vector
	for(int i=0;i<N-1;++i){
		if(data[i+1]!=data[i])
		ratios.push_back (Ratio(data[i+1],data[i]));
	}
	
	if(N==2){
		Ratio ans=Ratio(data[1],data[0]);
		cout<< ans.x<<"/"<<ans.y<<endl;
		return 0;
	}
	
	// �Ե�һ����ֵ��pow �η� ��Ϊ���� ������������������ֵ�Ļ����Ļ� �û������Ǵ� 
	for(int pow=1;pow<=40;pow++){
		Ratio ra0=ratios[0];
		LL x=ra0.x;
		LL y=ra0.y;
		
		LL fx=extract(x,pow);
		LL fy=extract(y,pow);
	
		if(fx==-1 || fy==-1)continue;
		
		bool all_match=true;
		//������������������ֵ�Ļ����Ļ� �û������Ǵ� 
		for(int i=1;i<ratios.size();++i){
			LL xx=ratios[i].x;
			LL yy=ratios[i].y;
			
			LL px=getPow(fx,xx);// fx�Ķ��ٴη�Ϊxx 
			LL py=getPow(fy,yy);// fy�Ķ��ٴη�Ϊyy 
			
			if(yy==1&&fy==1) py=px; // �����ĸΪ1�����    ����ط������˰��� ������ 
			
			if(px==-1||py==-1||px!=py){ // long fx xx ������  
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
// ӳ�����һ������  >>Ҫ�ֿ�  
map<LL,map<LL,LL> > all_ex; // all_ex[x][y] x��y�η��Ƕ���  
map<LL,map<LL,LL> > all_log; // all_log[x][y] x�Ķ��ٴη���y  
//��x��pow�η�  
LL extract(LL x,LL pow){
	if(pow==1)return x;
	if(x==1)return 1;
	if(all_ex[x].find(pow)!=all_ex[x].end()) // ��ζ���ܿ�������������ʼ������д���ˣ� 
	
		return all_ex[x][pow];
		
	else 
		return -1;
	
}

// a�Ķ��ٴη�Ϊb  
LL getPow(LL a,LL b){
	if(a==b) return 1;
	if(all_log[b].find(a)!=all_log[b].end())
		return all_log[b][a];
	else return -1; 
	
}  	
void init(){
	
	for(int i=2;i<1e6;++i){ // ö��i  
		LL cur=(LL)i*i;
		LL pow=2; 
		while(cur<1e12){    // �� i ��1 2 3 4... �η� ����map  
			all_ex[cur][pow]=i;
			all_log[cur][i]=pow;
			pow++;
			cur*=i;
			
		}
		
	}
}






