
#include<bits/stdc++.h>
using namespace std;
#define NMAX 5000
#define MOD 1000000007
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int N; //����  
int L=0; //
int res[NMAX+1];//C״̬��(��϶״̬��)
long long f[NMAX+1][NMAX+1];
string input;

void init(){//��ʼ��״̬��϶�� ((()
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

long long cal(){ //f[n,c]��ʾ��n�����ŷŵ�ǰc����϶�ķ�������
	memset(f,0,sizeof(f));
	//����0���Ų����κ�һ����϶�ķ�������1
	for(int i=0;i<=L;++i){
		f[0][i]=1;
	} 
	//
	 for(int n=1;n<=L;++n){
    	//��һ���ա��ڶ�����...
        for(int c=1;c<=L;++c){
        	//����Լ������
            if(n<=res[c]){ //��ǰ����<��϶  
            	//��ǰ��0����1��...���������n��
                /*for(int i=n;i>=0;--i){
                    F[n][c]+=F[i][c-1];
                    F[n][c]%=VMA1;//��ĿҪ��ķ����
                }*/
                //F[n][c-1]���ǵ�ǰ��1��+��ǰ��...
                f[n][c]=f[n-1][c]+f[n][c-1];
                f[n][c]%=MOD;//��ĿҪ��ķ����
            }
        }
    }
    return f[res[L]][L];

}


int main(int argc, char *argv[]) {
	cin >> input;
    N=input.size();
    init();//��ȡ��϶״̬����
    long long v_left=cal();//����ʹ�����źϷ�������
    //�������෴ת
    for(int i=0;i<N;++i){
        input[i]=(input[i]=='('?')':'(');
    }
    //���з�ת 
    reverse(input.begin(),input.end());
    init();//��ȡ��϶״̬���ң�
    long long v_right=cal();//����ʹ�����źϷ�������
    cout <<v_left<<" "<<v_right<<" "<<(v_left*v_right)%MOD << endl;//���ANS

	return 0;
} 












