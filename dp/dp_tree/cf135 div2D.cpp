// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p;
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
const ll INF=1e17;
using namespace std;
int n,ans=1e8,dp[maxn],g[maxn];
vector<pair<int,int> >e[maxn];
void dfs(int x ,int fa){
    for(auto [u,w]:e[x]){
        if(u==fa) continue;
        dfs(u,x);
        dp[x]=dp[x]+dp[u]+w;
    }
    return ;
}
void dfs2(int x,int fa){
    for(auto [u,w]:e[x]){
        if(u==fa) continue;
        g[u]=g[u]+g[x]+(dp[x]-dp[u])-w+(w==0?1:0);
        dfs2(u,x);
    }
}
void slove(){
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back({v,0});
        e[v].push_back({u,1});
    }
    dfs(1,-1);
    g[1]=0;
    dfs2(1,-1);
    for(int i=1;i<=n;i++){
        ans=min(ans,dp[i]+g[i]);
    }
    cout<<ans<<"\n";
    for(int i=1;i<=n;i++) if(dp[i]+g[i]==ans)  cout<<i<<" ";
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
// // ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// // inv[i]=(p-p/i)*inv[p%i]%p;
// #include <bits/stdc++.h>
// typedef long long ll;
// typedef long double db;
// const ll mod=1e9+7;
// const db pi=acos(-1);
// const db eps=1e-10;
// const int maxn=3e5;
// const ll INF=1e17;
// using namespace std;
// int n;
// vector<pair<int,int > >e[maxn];
// int dp[maxn],f[maxn];
// int g[maxn];
// void dfs1(int u, int p){
//     dp[u] = 0;
//     for (auto [v, w] : e[u]) {
//         if (v == p) continue;
//         dfs1(v, u);
//         dp[u] += dp[v] + w; // 子树内部 + 通过(u->v)的代价w
//     }
// }
// void dfs2(int u, int p){
//     for (auto [v, w] : e[u]) {
//         if (v == p) continue;
//         // 由父u推子v：g[v] 用上面的公式
//         g[v] = (dp[u] + g[u]) - (dp[v] + w) + (w == 0 ? 1 : 0);
//         dfs2(v, u);
//     }
// }

// void slove(){
//     cin >> n;
//     for (int i = 1; i <= n; ++i) {
//         e[i].clear();
//         dp[i] = g[i] = 0;
//     }
//     for (int i = 1; i < n; ++i) {
//         int u, v; cin >> u >> v;
//         e[u].push_back({v, 0}); // u->v 记 0
//         e[v].push_back({u, 1}); // v->u 记 1
//     }
//     dfs1(1, 0);     // 先算所有 dp（向下代价）
//     g[1] = 0;       // 根的“向上代价”为 0
//     dfs2(1, 0);     // 再把 g 向下推
//     int ans = 1e9;
//     for (int i = 1; i <= n; ++i) ans = min(ans, dp[i] + g[i]);
//     cout << ans << "\n";
//     for (int i = 1; i <= n; ++i) if (dp[i] + g[i] == ans) cout << i << " ";
// }

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int t=1;
//     //cin>>t;
//     while(t--){
// 		slove();
//     }
//     return (0-0);
// }