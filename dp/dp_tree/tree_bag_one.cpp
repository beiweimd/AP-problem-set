// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=2e3;
using namespace std;
int t,n,m;
int f[maxn];
int w[maxn];
int deep[maxn];
int siz[maxn];
int tmp[maxn];
int dp[maxn][maxn]; // dp i j代表第i个点包括自己有j个字树的连通块的最大数值
vector<int >e[maxn];
const int inf= (1<<29);
void dfs(int x,int fa){
    siz[x]=1;
    deep[x]=deep[fa]+1;
    for(auto u:e[x]){
        dfs(u,x);
        siz[x]+=siz[u];
    }
    return ;
}
void dfs2(int x){
    //cout<<x<<endl;
    if(siz[x]==1) return ;
    int cnt=1;
    for(auto u:e[x]){ // 枚举所有叶子结点
        dfs2(u);
        for(int i=1;i<=siz[x];i++){
            tmp[i]=-inf;
        }
        for(int i=cnt;i>=1;i--){
            for(int j=1;j<=siz[u];j++){
                tmp[i+j]=max(tmp[i+j],dp[x][i]+dp[u][j]);
            }
        }
        cnt+=siz[u];
        for(int i=1;i<=cnt;i++){
            dp[x][i]=max(dp[x][i],tmp[i]);
        }
    }
    return ;
}
void slove(){
	cin>>n>>m;
    for(int i=2;i<=n;i++){
        cin>>f[i];
        e[f[i]].push_back(i);
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++){
        cin>>w[i];
        dp[i][1]=w[i];
        dp[i][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=2;j<=siz[i];j++) dp[i][j]=-1e7;
    }
    dfs2(1);
    for(int i=1;i<=m;i++){
        int u,m;
        cin>>u>>m;
        cout<<dp[u][m]<<"\n";
    }
    for(int i=1;i<=3;i++){
        //cout<<dp[2][i]<<endl;
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