
#include<bits/stdc++.h>
using namespace std;
#define NMAX 5000
#define MOD 1000000007
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int N; //长度  
int L=0; //
int res[NMAX+1];//C状态表(空隙状态表)
long long f[NMAX+1][NMAX+1];
string input;

void init(){//初始化状态空隙表 ((()
	L=0;
	for(int i=1;i<=N;++i){
        if(input[i-1]=='('){
            ++L;
            res[L]=res[L-1]+1;
        }else{
            if(res[L]>0){
                res[L]--;
            }
        }
    }

	 
	
}

long long cal(){ //f[n,c]表示将n个括号放到前c个空隙的方案数。
	memset(f,0,sizeof(f));
	//对于0括号插入任何一个空隙的方案数是1
	for(int i=0;i<=L;++i){
		f[0][i]=1;
	} 
	//
	 for(int n=1;n<=L;++n){
    	//第一个空、第二个空...
        for(int c=1;c<=L;++c){
        	//满足约束条件
            if(n<=res[c]){ //当前括号<空隙  
            	//当前放0个、1个...、放满或放n个
                /*for(int i=n;i>=0;--i){
                    F[n][c]+=F[i][c-1];
                    F[n][c]%=VMA1;//题目要求的防溢出
                }*/
                //F[n][c-1]就是当前放1个+当前放...
                f[n][c]=f[n-1][c]+f[n][c-1];
                f[n][c]%=MOD;//题目要求的防溢出
            }
        }
    }
    return f[res[L]][L];

}


int main(int argc, char *argv[]) {
	cin >> input;
    N=input.size();
    init();//获取空隙状态表（左）
    long long v_left=cal();//计算使左括号合法方案数
    //括号种类反转
    for(int i=0;i<N;++i){
        input[i]=(input[i]=='('?')':'(');
    }
    //序列反转 
    reverse(input.begin(),input.end());
    init();//获取空隙状态表（右）
    long long v_right=cal();//计算使右括号合法方案数
    cout <<v_left<<" "<<v_right<<" "<<(v_left*v_right)%MOD << endl;//输出ANS

	return 0;
} 












