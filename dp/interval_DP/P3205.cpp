// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=19650827;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=2e3;
const ll INF=1e17;
using namespace std;
int n;
ll a[maxn];
ll dp[maxn][maxn][3]; // 区间i到j 有多少方案数量 其中0 / 1 代表i j 最后一个数放置的是a[i]还是a[j]
void slove(){
	cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][i][0]=1;
    }
    for(int len=1;len<=n;len++){ // 枚举长度len
        for(int i=1;i+len<=n;i++){ // 枚举起点
            int j=i+len;
            if(a[j]>a[j-1])  dp[i][j][1]+=dp[i][j-1][1];
            //if(a[j]<a[j-1])  dp[i][j][0]+=dp[i][j-1][1]; 注意这个转移是不行的 因为a[j]只能查到右边 不然就和dp意义相悖了
            if(a[j]>a[i]) dp[i][j][1]+=dp[i][j-1][0];
            dp[i][j][1]%=mod;
            if(a[i]<a[j]) dp[i][j][0]+=dp[i+1][j][1];
            if(a[i]<a[i+1]) dp[i][j][0]+=dp[i+1][j][0];
             dp[i][j][0]%=mod;
        }
    }
    cout<<(dp[1][n][0]+dp[1][n][1])%mod;
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