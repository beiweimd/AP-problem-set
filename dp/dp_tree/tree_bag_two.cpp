// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=6e4+100;
using namespace std;
int t,n,m;
int f[maxn];
int w[maxn];
int deep[maxn];
int siz[maxn];
int dp[maxn][200]; // dp i j代表第i个点包括自己有j个字树的连通块的最大数值
vector<int >e[maxn];
const int inf= (1<<29);
void dfs(int x){
    static int tmp[maxn];
    siz[x]=0; // 这里记录的字数的大小
    for(auto u:e[x]){
        dfs(u);
        for(int i=0;i<=min(siz[u]+siz[x],m);i++) tmp[i]=-inf;
        for(int i=0;i<=min(siz[x],m);i++){
            for(int j=0;j<=siz[u]&&i+j<=m;j++){
                tmp[i+j]=max(tmp[i+j],dp[x][i]+dp[u][j]);
            }
        }
        for(int i=0;i<=min(siz[u]+siz[x],m);i++) dp[x][i]=tmp[i];
        siz[x]+=siz[u];
    }
    siz[x]++;
    for(int i=min(siz[x],m);i>=1;i--){
        dp[x][i]=dp[x][i-1]+w[x];
    }
    dp[x][0]=0;
    return ;
}
void slove(){
    int q;
    m=101;
	cin>>n>>q;
    for(int i=2;i<=n;i++){
        cin>>f[i];
        e[f[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    dfs(1);
    for(int i=1;i<=q;i++){
        int u,k;
        cin>>u>>k;
        cout<<dp[u][k]<<"\n";
    }
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