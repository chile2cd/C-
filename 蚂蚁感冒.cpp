#include <iostream>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*

 ��������nֻ���� ���ǵ�ͷ�еĳ��� �еĳ��� 
 
 ÿֻ�����ٶ���ͬ 
 
 ��������ʱ���෴�ķ������� 
 
 ����ĵ�һֻ����Ϊ��ð �������ϻᴫȾ 
 
 ��һ������nֻ��������  
 
 ���������� ��ð�����ϸ���  

*/


int main(int argc, char *argv[]) {
		
	int arr[50];
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>arr[i];
	} 
	int x=arr[0];	// ��ǵ�һֻ���� 
	
	if(x<0)  // �����ð�ĵ�һֻ���ϳ��� 
	{
		int ans=1;
		for(int i=0;i<n;++i) // x��߳��ҵ� �� x�ұ߳���Ķ���ð 
		{
			if(arr[i]<-x && arr[i]>0)
				ans++;
		} 
		if(ans!=1)		// ��ʾx����г��ҵ� ��ô x��߳���ıظ�ð
		{
			for(int i=0;i<n;++i) 
			{
				if(-arr[i]>-x && arr[i]<0)
					ans++;
			} 
		
		} 
	 cout<<ans<<endl;
	}
	if(x>0) 	// ��ʼ��ð���ϳ����� 
	{
		int ans=1;
		for(int i=0;i<n;++i) // x �ұ߳���� �� x��߳��ҵĶ���ð 
		{
			if(-arr[i]>x && arr[i]<0)
				ans++;
		} 
		if(ans!=1)		// ��ʾx����г��ҵ� ��ô x��߳���ıظ�ð
		{
			
			for(int i=0;i<n;++i)
			{
			
				if(arr[i]<x && arr[i]>0)
					ans++;
			} 
		} 
			cout<<ans<<endl;
	}
	

	
	
	return 0;
}
