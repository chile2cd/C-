#include <iostream>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*

 长杆上有n只蚂蚁 它们的头有的朝左 有的朝右 
 
 每只蚂蚁速度相同 
 
 蚂蚁碰面时向相反的方向爬行 
 
 输入的第一只蚂蚁为感冒 碰到蚂蚁会传染 
 
 第一行输入n只蚂蚁坐标  
 
 求它们爬离 感冒的蚂蚁个数  

*/


int main(int argc, char *argv[]) {
		
	int arr[50];
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>arr[i];
	} 
	int x=arr[0];	// 标记第一只蚂蚁 
	
	if(x<0)  // 输入感冒的第一只蚂蚁朝左 
	{
		int ans=1;
		for(int i=0;i<n;++i) // x左边朝右的 和 x右边朝左的都感冒 
		{
			if(arr[i]<-x && arr[i]>0)
				ans++;
		} 
		if(ans!=1)		// 表示x左边有朝右的 那么 x左边朝左的必感冒
		{
			for(int i=0;i<n;++i) 
			{
				if(-arr[i]>-x && arr[i]<0)
					ans++;
			} 
		
		} 
	 cout<<ans<<endl;
	}
	if(x>0) 	// 开始感冒蚂蚁朝向右 
	{
		int ans=1;
		for(int i=0;i<n;++i) // x 右边朝左的 和 x左边朝右的都感冒 
		{
			if(-arr[i]>x && arr[i]<0)
				ans++;
		} 
		if(ans!=1)		// 表示x左边有朝右的 那么 x左边朝左的必感冒
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
