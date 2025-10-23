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
int n;
int a[maxn];
int qz[maxn];
int dp[maxn][maxn]; // 合并i 到j的最小代价
void slove(){
	cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        qz[i]=qz[i-1]+a[i];
    }
    for(int len=1;len<=n;len++){ // 枚举长度
        for(int i=1;i+len<=n;i++){ // 枚举起点 
            for(int j=i;j<i+len;j++){ // 枚举左边合并的终点
                if(dp[i][i+len]==0) dp[i][i+len]=dp[i][j]+dp[j+1][i+len]+(qz[i+len]-qz[i-1]);
                else dp[i][i+len]=min(dp[i][i+len],dp[i][j]+dp[j+1][i+len]+(qz[i+len]-qz[i-1]));
            }
        }
    }
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