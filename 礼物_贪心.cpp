#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop 

��������
����JiaoShou�ڰ��մ�½��������ϣ������ؼң�Ϊ�˼���������У�����������һЩ����������ѡ�
�������߳��˹���ɭ���Ժ�JiaoShou�������ų�һ�ŵ�N��ʯ�ӡ�
������Щʯ�Ӻ�Ư����JiaoShou�����Դ�Ϊ���
����������N��ʯ�ӱ�ʩ����һ�������ħ����
�������Ҫȡ��ʯ�ӣ����밴�����µĹ���ȥȡ��
����ÿ�α���ȡ������2*K��ʯ�ӣ���������ǰK��ʯ�ӵ�������С�ڵ���S����K��ʯ�ӵ�������С�ڵ���S��
��������ʱ����ȣ�Jiaoshouֻ��ȡһ�Ρ�
��������JiaoShou�ҵ��˴������㣬���������Դ��߶��ٸ�ʯ�ӡ�
�����ʽ 
������һ����������N��S��
�����ڶ���N���������ÿո��������ʾÿ��ʯ�ӵ�������
�����ʽ 
������һ�����һ������ʾJiaoShou�����ȡ�߶��ٸ�ʯ�ӡ�
��������
����8 3
����1 1 1 1 1 1 1 1
�������
����6 

*/


//int main(int argc, char *argv[]) {
//	
//	
//	return 0;
//}

// ����  
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long ll;
ll a[N],val[N],S;
int n,k,l,r;
bool check(int tem){
    for(int i=tem;i<=n-tem;i++){
        if(val[i]-val[i-tem]<=S&&val[i+tem]-val[i]<=S){//���𰸴���ʱ ����true
            return true;
        }
    }
    return false;
}
int main(){
    scanf("%d%lld",&n,&S);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        val[i]=val[i-1]+a[i];//��ǰ׺��      
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






































