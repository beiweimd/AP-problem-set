// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=53;
const ll INF=1e17;
using namespace std;
int n;
string s;
// 不要考虑每一段到底“具体”是如何涂色的，只要考虑转移方程就行了！！！！！！ 
int f[maxn][maxn]; // 表示刷 i j这样一个区间的最小次数
void slove(){
	cin>>s;
    s=" "+s;
    n=s.length()-1;
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++){
                f[i][j]=1e7;
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++){
                if(s[i]!=s[j]) break;
                else f[i][j]=1;
        }
    }
    for(int len=1;len<=n;len++){
        for(int i=1;i+len<=n;i++){
            int j=len+i;
            if(s[i]==s[j]) f[i][j]=min(f[i][j],min(f[i+1][j],f[i][j-1])); // 有点神秘的转移方程 大概就是说如果两端相同 在涂得时候 处理左边或者右边 都是可以顺带处理的
            for(int k=i;k<=j;k++){ // 这里是枚举开始涂得起点
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
            }
        }
    }
    cout<<f[1][n];
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
		slove();
    }
    return (0-0);
}
/*
下面这个思想可能更直观一点
把一个空木板涂成指定的图案和把指定的图案涂成一种颜色，然后再涂一下是不是一样
大概就是说 这是一个可逆的过程，原来的方案第一次肯定是涂某种颜色 然后在接着改变
就其实 这是一个互逆的过程 对
#include<bits/stdc++.h>
using namespace std;
int n,dp[100][100];
string a;
int main()
{
	cin >> a;
	a = " " + a;//为了方便接下来使用
	n = a.length() - 1;//虽然再前面加了一个空格，但是实际的使用长度不变，所以要减一
	memset(dp,127,sizeof(dp));//因为一会儿要取min，所以先赋成一个极大值
	for(int i = 1;i <= n;i++)
	{
		dp[i][i] = 0;//左右节点一样肯定不用涂色
	}
	for(int i = 2;i <= n;i++)
	{
		for(int j = 1;j + i - 1 <= n;j++)
		{
			int k = j + i - 1;
			for(int l = j;l < k;l++)
			{
				dp[j][k]=min(dp[j][k],dp[j][l]+dp[l+1][k]+(a[j]!=a[k]));//状态转移方程，求最小的涂色次数。a[l]为中转的字符a[j]~a[l]为同一个颜色，a[l+1]~a[k]为同一个颜色，首先，肯定得把把a[j]~a[l]变成一个颜色的涂色次数（,dp[j][l]）和把a[l+1]~a[k]变成一个颜色的涂色次数（dp[l+1][k]）给加上，如果a[j]和a[k]的颜色不一样，那么还得把这一整段再给涂成一个颜色的涂色次数（1次）给加上，最后在和自己本身取一个min，就OK了
			}
		}
	}
	cout << dp[1][n] + 1 << endl;//还得再加一次，因为它是从啥都没有开始涂得，但是咱们却是从标准图案涂成了同一个颜色，所以还得再涂一次，如果不懂可以往上翻翻，翻到一开始的文字区，还不懂我就帮不了你了
	return 0;
}
*/