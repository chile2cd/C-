#include <iostream>
#include<algorithm>
using namespace std;
/*
���������е�ͼ���ҳ�·��Ϊ5����ͨͼ
�����ж��ٸ� 
������dfs�޷���� T ��������  
*/


int a[]={0,0,0,0,0,0,0,1,1,1,1,1};
int ans;
int ans1;
void dfs(int g[3][4],int i,int j){//ȥ�������ڵ�·���Ƿ������ 

	g[i][j]=0;//�߹��ı��0 
	//����������  
	if(i-1>=0&&g[i-1][j]==1) dfs(g,i-1,j); 
	//����������  
	if(i+1<=2&&g[i+1][j]==1) dfs(g,i+1,j); 
	//����������  
	if(j-1>=0&&g[i][j-1]==1) dfs(g,i,j-1); 
	//����������  
	if(j+1<=3&&g[i][j+1]==1) dfs(g,i,j+1); 	
}

bool check(){

	int g[3][4];//��һά�仯ӳ�䵽��ά�仯 
	for(int i=0;i<3;++i){
		for(int j=0;j<4;++j){
			if(a[i*4+j]==1) g[i][j]=1;
			else g[i][j]=0;  
		}
	} //ӳ����� 
	 int cnt=0;
	 //��g����������Ƿ���Ϊ1������ͨ·�� 
	 for(int i=0;i<3;++i){
	 	for(int j=0;j<4;++j){
	 		if(g[i][j]==1){    //������Ϊ1·������Ϊ5�����·������ͨ  
	 			dfs(g,i,j);    // ��ôȥ����ôһ��·�� �߹�����Ϊ0 
	 			cnt++;			// �����һ��һ�����������ͼȫ0 ans=1��������ͨ 
	 		}
	 	}
	 } 
	
	return cnt==1;
}

void f(int k){ // ȫ����  
	
	if(k==12){
		if(check()){//����Ƿ�����ͨ  
			ans++;
		}
	}
	
	for(int i=k;i<12;++i){
		{
			int t=a[i]; a[i]=a[k]; a[k]=t;//���� 
		}
		f(k+1); //ȷ��k+1λ  
		{
			int t=a[i]; a[i]=a[k]; a[k]=t;//���� 
		}
	}
	
	
}
void f1(){
	do{
		
		if(check()){
			ans1++;
		}
		
	}while(next_permutation(a,a+12));

}

int main(int argc, char *argv[]) {
	
	f1();
//	f(0);
	cout<<ans1<<endl;
//	cout<<ans<<endl;
	return 0;
}










