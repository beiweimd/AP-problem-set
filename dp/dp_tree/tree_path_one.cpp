// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e4;
using namespace std;
int t,n,m;
int f[maxn];
ll dp[maxn];
// dp i 代表以i 路径lca最高是i为的的所有路径的和 
// 那么转移的时候 就是要么不选 那么状态就是所有的字数之和 选一条路径的话 就是这条路径的点之外的字数点之和
// 那么边界情况显然就是叶子结点
ll cnt[maxn]; // 代表不选的时候的贡献
struct node{
    int u,v,w;
};
vector<node>a[maxn];
int dep[maxn];
vector<int > e[maxn];
int find(int x,int y){
    int ccc=0;
    while(x!=y && ccc<=10){
        if(dep[x]>dep[y]) x=f[x];
        else y=f[y];
    }
    return x;
}
void dfs(int u){
    //cout<<u<<endl;
    for(auto v:e[u]){
        dfs(v);
        cnt[u]+=dp[v];
    }
    dp[u]=cnt[u]; // 那个初始的时候先假设不选自己这条路径
    for(auto p:a[u]){ // 枚举所有的路径
        ll tmp=cnt[u]; // 算经过这条路径的贡献
        // 算法是所有的字数贡献减去路径上的点的贡献
        int x=p.u;
        while(x!=u){
            tmp=tmp-dp[x]+cnt[x];
            x=f[x];
        }
        x=p.v;
        while(x!=u){
            tmp=tmp-dp[x]+cnt[x];
            x=f[x];
        }
        tmp+=p.w; //加上自己这个点 因为被减去了两次
        dp[u]=max(dp[u],tmp);
    }
    return ;
}
void slove(){
	cin>>n>>m;
    for(int i=2;i<=n;i++){
        cin>>f[i];
        dep[i]=dep[f[i]]+1;
        e[f[i]].push_back(i);
    }
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        a[find(u,v)].push_back(node{u,v,w});
    }
    dfs(1);
    cout<<dp[1];
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