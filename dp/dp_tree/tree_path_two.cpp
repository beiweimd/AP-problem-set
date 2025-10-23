// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=2e5;
using namespace std;
int t,n,m;
int f[maxn];
int dep[maxn];
vector<int > e[maxn];
ll dp[maxn][2],ans[maxn];
ll pre[maxn],suf[maxn];
// dp[i][1] 在以1为根的情况下子树的贡献
// dp[i][2]代表以i为根下 除了自己的字数贡献 父亲的贡献
void dfs(int x){
    dp[x][1]=1;
    for(auto u:e[x]){
        dfs(u);
        dp[x][1]=(dp[x][1]*(dp[u][1]+1))%m;
    }
    return ;
}
void dfs2(int x){
    if(e[x].size()==0) return ;
    pre[0]=suf[(int)e[x].size()]=1ll;
    for(int i=0;i<e[x].size();i++){
        pre[i+1]=pre[i]*(1+dp[e[x][i]][1]);
        pre[i+1]%=m;
    }
    for(int i=e[x].size()-1;i>=0;i--){
        suf[i]=suf[i+1]*(1ll+dp[e[x][i]][1]);
        suf[i]%=m;
    }
    // 处理每个结点父亲结点儿子节点的suf 和pre和
    for(int i=0;i<e[x].size();i++){
        int u=e[x][i];
        dp[u][2]=pre[i]*suf[i+1]%m;
        if(x!=1) dp[u][2]=dp[u][2]*(dp[x][2]+1)%m;
    }
    for(auto u:e[x]){
        ans[u]=(dp[u][2]+1)*dp[u][1]%m;
        dfs2(u);
    }
    return ;
}
void slove(){
	cin>>n>>m;
    for(int i=2;i<=n;i++){
        cin>>f[i];
        e[f[i]].push_back(i);
    }
    dfs(1);
    dfs2(1);
    ans[1]=dp[1][1];
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<"\n";
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