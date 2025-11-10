#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop 

问题描述
　　JiaoShou在爱琳大陆的旅行完毕，即将回家，为了纪念这次旅行，他决定带回一些礼物给好朋友。
　　在走出了怪物森林以后，JiaoShou看到了排成一排的N个石子。
　　这些石子很漂亮，JiaoShou决定以此为礼物。
　　但是这N个石子被施加了一种特殊的魔法。
　　如果要取走石子，必须按照以下的规则去取。
　　每次必须取连续的2*K个石子，并且满足前K个石子的重量和小于等于S，后K个石子的重量和小于等于S。
　　由于时间紧迫，Jiaoshou只能取一次。
　　现在JiaoShou找到了聪明的你，问他最多可以带走多少个石子。
输入格式 
　　第一行两个整数N、S。
　　第二行N个整数，用空格隔开，表示每个石子的重量。
输出格式 
　　第一行输出一个数表示JiaoShou最多能取走多少个石子。
样列输入
　　8 3
　　1 1 1 1 1 1 1 1
样列输出
　　6 

*/


//int main(int argc, char *argv[]) {
//	
//	
//	return 0;
//}

// 二分  
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long ll;
ll a[N],val[N],S;
int n,k,l,r;
bool check(int tem){
    for(int i=tem;i<=n-tem;i++){
        if(val[i]-val[i-tem]<=S&&val[i+tem]-val[i]<=S){//当答案存在时 返回true
            return true;
        }
    }
    return false;
}
int main(){
    scanf("%d%lld",&n,&S);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        val[i]=val[i-1]+a[i];//求前缀和      
    }
    l=1,r=8;
    while(l<r){  
        int mid=(l+r+1)>>1;
        if(check(mid))
            l=mid;
        else 
            r=mid-1;
    }
    printf("%d\n",2*l);
    return 0;
}






































