// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e3;
const ll INF=1e17;
using namespace std;
/*
将一个字符串变换为回文串 
最少需要多少插入多少个字符
*/
string s;
int dp[maxn][maxn]; //代表第i到j的子串成为回文串需要拼接几次
void slove(){
    cin>>s;
    int n=s.length();
    s="0"+s;
    for(int i=1;i<n;i++){
        if(s[i]==s[i+1]) dp[i][i+1]=0;
        else dp[i][i+1]=1;
    }
    for(int i=2;i<=n;i++){ // 枚举的是长度
        for(int j=1;j+i<=n;j++){ // 计算 dp[j][i+j]
            dp[j][j+i]=1+min(dp[j][i+j-1],dp[j+1][i+j]);    
            if(s[j]==s[i+j]) dp[j][j+i]=min(dp[j][i+j],dp[j+1][i+j-1]);
        }
    }
    //cout<<dp[2][5]<<endl;
    cout<<dp[1][n];
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