// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=6e3;
const ll INF=1e17;
using namespace std;
int n,a[maxn],ans;
int dp[maxn][maxn]; // [l,r]这段区间合并成一个区间的最小次数 并且最后一次是左边还是右边
void slove(){
    cin>>n; ans=1e7;
    vector<int >e[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        e[a[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=1e7;
        }
        dp[i][i]=0;
    }
    for(int len=1;len<=n;len++){
        for(int i=1;i+len<=n;i++){
            int j=i+len;
            dp[i][j]=min(dp[i][j],dp[i][j-1]+(a[i]!=a[j]));
            for(auto k:e[a[j]]){ // 这里一定是a[j]
                if(k>i ) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        }
    }
    cout<<dp[1][n]<<"\n";
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
		slove();
    }
    return (0-0);
}