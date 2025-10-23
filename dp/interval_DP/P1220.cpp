// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=200;
const ll INF=1e17;
using namespace std;
int n,c,ans;
int pos[maxn];
int w[maxn];
int cnt[maxn][maxn];// 这里指的是从i到j这一段中 这一段中间的电贡献了多少
int dp[maxn][maxn][3]; // [i,j]这样一个区间已经被关了 并且说 最后一次关的是左边的i还是右边的j
int qz[maxn],suf[maxn];
void slove(){
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>pos[i]>>w[i];
        suf[i]=suf[i-1]+w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            dp[i][j][1]=dp[i][j][2]=1e7;
        }
    }
    dp[c][c][1]=dp[c][c][2]=0;
    for(int i=c+1;i<=n;i++){
        dp[c][i][2]=dp[c][i-1][2]+(pos[i]-pos[i-1])*(suf[n]-(suf[i-1]-suf[c]));
    }
    for(int i=c-1;i>=1;i--){
        dp[i][c][1]=dp[i+1][c][1]+(pos[i+1]-pos[i])*(suf[n]-(suf[c]-suf[i]));
    }
    for(int len=1;len<=n;len++){
        for(int i=1;i+len<=n;i++){
            int j=i+len;
            dp[i][j][1]=min(
                dp[i+1][j][1]+(pos[i+1]-pos[i])*(suf[n]-(suf[j]-suf[i])), // 第一种情况 直接从i+1，r这个区间涂过来 
                dp[i+1][j][2]+(pos[j]-pos[i])*(suf[n]-(suf[j]-suf[i])) // 从最右边的r移过来
            );
            dp[i][j][2]=min(
                dp[i][j-1][2]+(pos[j]-pos[j-1])*(suf[n]-(suf[j-1]-suf[i-1])), // 这里只有[i,j-1]是已经关了的
                dp[i][j-1][1]+(pos[j]-pos[i])*(suf[n]-(suf[j-1]-suf[i-1]))
            );
        }
    }
    cout<<min(dp[1][n][1],dp[1][n][2]);
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