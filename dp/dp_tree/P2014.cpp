// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=2e3+100;
using namespace std;
int t,n,m;
int siz[maxn];
int w[maxn];
int f[maxn];
int deep[maxn],ans;
int dp[maxn][maxn]; // 代表第i的字树 一共选了j门的最大得分
vector<int >e[maxn];
void dfs(int x ,int fa){
    deep[x]=deep[fa]+1;
    siz[x]=1;
    for(auto u:e[x]){
        if(u==fa) continue;
        dfs(u,x);
        for(int i=siz[x]-1;i>=0;i--){
            for(int j=0;j<=siz[u];j++){
                dp[x][i+j]=max(dp[x][i+j],dp[x][i]+dp[u][j]);
            }
        }
        siz[x]+=siz[u];
    }
    for(int i=siz[x];i>=1;i--){
        dp[x][i]=dp[x][i-1]+w[x];
    }
    return ;
}
void slove(){
    cin>>n>>m;
    n++;
    for(int i=2;i<=n;i++){
        int k;
        cin>>k>>w[i];
        k++;
        f[i]=k;
        e[k].push_back(i);
        e[i].push_back(k);
    }
    dfs(1,0);
    cout<<dp[1][m+1];
	return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    t=1;
    while(t--){
		slove();
    }
    return 0;
}