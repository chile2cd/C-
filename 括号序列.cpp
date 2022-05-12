#include <iostream>
#include<stack>
using namespace std;
/* run this program using the console pauser or add your own getch,、、
给定一个括号序列，要求尽可能少地添加若干括号使得括号序列变得合法，当添加完成后，会产生不同的添加结果，请问有多少种本质不同的添加结果。

两个结果是本质不同的是指存在某个位置一个结果是左括号，而另一个是右括号。
	(((()) 
例如，对于括号序列 ((()，只需要添加两个括号就能让其合法，有以下几种不同的添加结果：
()()()  ()(())  (()) ()  (()())  ((( )))
输入描述 
输入一行包含一个字符串 s，表示给定的括号序列，序列中只有左括号和右括号。

输出描述
输出一个整数表示答案，答案可能很大，请输出答案除以 10000000071000000007 
(即 10^9 + 7)10 
9
 +7) 的余数。
*/
#define MOD 1000000007


/*
一 全排列思想 ：先补全括号 再对这个序列用全排列筛选合法的 统计即可  
二 深度dfs 
三 动态规划  
*/ 

// 1 
//判断括号序列是否合法 
string s(5001,'0');
int a[5001]={0};
int len;
int ans=0;

bool is_illegall (int  _s[],int len){ //判断有误！！  
	// 101001 ()())(  ((())) 111000    1,0,1,1,0,0
	stack<int> t;
	for(int i=0;i<len;++i){
		if(t.empty()==true){//开始栈为空 
			t.push(_s[i]); 
		}else if(t.top()==1&&_s[i]==0){ 
				t.pop();//如果能和此时栈顶匹配 则弹出和其匹配  
		}else{
			t.push(_s[i]); 
		}
	}
	if(t.empty()==true) {
		return true;    // 如果能匹配无剩余则该序列合法  
	}else{
		return false;
	}
	
}
template <class T2>
void swap1(T2 &a, T2 &b){
	T2 t;
	t = a;
	a = b;
	b = t;
}

//判断是否可以交换
int finish(int * list, int k, int i)
{//第i个元素是否在前面元素[k...i-1]中出现过
	if (i > k)
	{
		for (int j = k; j < i; j++)
		if (list[j] == list[i])
			return 0;
	}
	return 1;
}


void Per(int* str, int begin, int end)   //从begin开始到end结尾的str的带有重复元素的全排列
{

	if (begin==end){
		// 这里生成无重复元素的全排列 
		if(is_illegall(str,len)){
			
			ans++;
		}
		return;
	}


	for (int i = begin; i <= end; i++)
	{
		/*如果begin可以和i交换就交换，不可以那么就继续循环*/
		if (finish(str, begin, i))
		{
			swap1(str[begin], str[i]);
			//确定好了头元素，那么就可以排列剩下的了 
			Per(str, begin + 1, end);
			swap1(str[begin], str[i]);
		}
	}
}

void fun1(){
	int cnt[2]={0};
	
	int sum=1,temp=0;
	
	cin>>s;
	
	//统计 左括号 右括号的数量 
	for(int i=0;i<s.length();++i){
		
		if(s[i]=='(') cnt[0]++;
		
		else cnt[1]++;
	}
	
	int max=(cnt[0]>cnt[1] ? cnt[0]:cnt[1]);
	int min=(cnt[0]<cnt[1] ? cnt[0]:cnt[1]);
	
	int tol=max*2; //总括号数  
	int ad=tol-cnt[0]-cnt[1]; //要添加的括号数  
	
	int i;
	for(i=0;i<tol;++i){  // 初始化括号序列为 1 0 
		if(i<tol/2) a[i]=1;
		else a[i]=0;	
	}
	
	 len=i; 

	 Per(a,0,len-1);    //无重复元素的全排列 去重后的 序列 筛选合法的括号序列
	//int tex[6]={1,0,1,1,0,0};
	ans%=MOD;
	cout<<ans<<endl;


//	int a[6]={1,1,0,0,0,1};
//	cout<<is_illegall(a,6)<<endl; 
	
}


void fun2(){
	
}
int main(int argc, char *argv[]) {
	
	//fun1(); 

	return 0;
}


/*
首先这个序列中我们需要添加的是左括号和右括号， 那么显然的我们要想左括号和右括号的
添加是不是相互独立的呢？答案是肯定的：

考虑到我们只能在空隙中插入括号， 如果我们添加的一对左右括号不是在同一个空隙中， 
那么他们显然是互不干扰的；如果是添加在同一个空隙中， 那么他们的添加顺序是唯一的， 
只能是）（， 因为如果是（）的话， 那我们本次的添加就是无效的，
不满足添加最少的括号使得序列得到匹配。 由此可得，
 我们只需要单独计算出添加左括号的方案数， 乘上单独添加右括号的方案数就是答案的数量。

明确了上面那个问题，我们就可以对左右括号进行单独计算了， 我们这里以添加左括号为例。

我们如果以右括号为端点， 将整个序列进行分割， 那么在分割后的每一小段添加左括号的
方案数显然只和这段序列中左括号的数量有关， 因为这段序列里全是左括号， 怎
么排列都是一种。所以我们只关注左括号的个数就好了， 更准确的来说， 我
们只要关注我们添加的左括号的个数。

那么我们可以设计一个状态f[i][j]表示当前枚举到第i个右括号， 
我们添加了j个左括号的==合法==方案（注意， 如果我们添加的操作使得前i个右括号都被匹配
完后还有剩余的左括号， 我们仍认为这个状态是合法的）， 那么我们首先预处理出每个右括号
前面至少需要添加的左括号的数量记为add数组，那么显然小于add的方案都是不合法的，
 对于大于add的数量， 我们将添加的左括号分为两组， 一组在第i - 1个右括号的前面，
 另一组在第i - 1个括号到第i个括号之间， 那么枚举任意一段的数目就可以实现转移了
 
for(int i = add[1]; i <= len; i ++) f[1][i] = 1;//预处理， 很显然

for(int i = 2; i <= num; i ++)
    for(int j = add[i]; j <= len; j ++)//注意从add[i]开始， 比add[i]小的状态一定不
	合法
        for(int k = 0; k <= j; k ++)//k表示的是i - 1到i段添加左括号的数量
            f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod;
作者：Alkaid1506
链接：https://www.acwing.com/solution/content/47526/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
这样我们的工作看似就完成了， 但是这个dp的时间复杂度是==n ^ 3==的， 过不了本题5k的数
据， 那么我们就要考虑进行优化

我们可以明显注意到
f[i][j] = f[i - 1][0] + f[i - 1][1] + ...... + f[i - 1][j]

f[i][j + 1] = f[i - 1][0] + f[i - 1][1] + ...... + f[i - 1][j] + f[i - 1][j + 1]
那么我们可以得出
f[i][j] = f[i][j - 1] + f[i - 1][j - 1]
那么我们只需要先O(n)的算出f[i][add[i]]， 后面的f[i][j]就都可以O(1)转移出了， 总体时间复杂度==n ^ 2==， 可以通过本题

当然对与添加右括号来说， 只需要将序列镜像翻转， 然后当作匹配左括号就可以了

*/















