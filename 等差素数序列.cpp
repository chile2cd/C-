#include <iostream>
using namespace std;

bool is_(int b){
  
for(int a=2;a<b/2;a++)
	{
        if(b%a==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{ 
for(int a1=2;a1<50000;a1++)
{
	if(is_(a1))
	{
	 for(int d=2;d<1000;d++)
	 {
	 	bool a=true;
		for(int i=0;i<10;++i)
		{	
			if(!is_(a1+i*d))
			{
				a=false;
				break;
			}
		
		}
      if(a){
      	cout<<d<<endl;
      	return 0;
      }
	}
		
	}
		
}
  return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//bool sushu(int b)
//{
//    for(int a=2;a<b/2;a++)
//    {
//        if(b%a==0)
//        {
//            return 0;
//        }
//    }
//    return 1;
//}
//int main(int argc, char *argv[])
//{
//   ���ڴ��������Ĵ���
//        int biaozhi=0;
//    for(int i=2;i<50000;i++)  //ö������
//    if(sushu(i)) //������������ʱ  ����Ѱ����һ��
//    {
//        for(int j=2;j<1000;j++)  //ö�ٹ���
//        {
//            for(int t=0;t<10;t++)  //��10�� 
//            {
//                if(sushu(i+j*t))  //�Ȳ����� 
//                {
//                    biaozhi++;
//                }
//                else{
//                    biaozhi=0;
//                    break;
//                }
//                if(biaozhi==9)
//                {
//                    printf("%d",j);
//                    return 0;
//                }
//                
//            }
//             
//         } 
//     } 

//  return 0;
//}
