#include<bits/stdc++.h>
#include<string>
using namespace std;
string s,ans[1005],e,a;int key,b[105],i=1,num;
int main()
{
	while(cin>>s,getline(cin,a),getline(cin,a),cin>>e)
	{	
    	int len=a.size();
    	for(i=0;i<len;i++)
    	{
    	    if(a[i]>='a'&&a[i]<='z')
    		a[i]-=32;
		}
		num++;
		if(num==1)
		{
			for(int i=0;i<len;i++)
			{
				b[int(a[i])]++;
			}
			int maxx=0,k;
			for(int i='A';i<='Z';i++)
			{
				if(b[i]>maxx)
				{
					maxx=b[i];
					k=i;
				}
			}
			key='E'-k;
		}
		for(int i=0;i<len;i++)
		{
			
			if(a[i]>='A'&&a[i]<='Z')
			{
				a[i]+=key;
				if(a[i]>'Z') a[i]-=26;
				if(a[i]<'A') a[i]+=26;
			}
		}
		ans[num]=a;
		if (a== "ENDOFINPUT" == 1)break;
	}
	for(int i=1;i<=num;i++)
	{
		cout<<ans[i]<<endl;
	}

//	char a[100];
//	gets(a);
//	cout<<a; 
	return 0;
}
