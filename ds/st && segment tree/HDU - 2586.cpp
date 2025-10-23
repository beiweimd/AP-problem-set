// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p; 正推 线性求出1-n的逆元
// 先求出阶乘fac 快速幂算出fac[n]的阶乘 线性倒推fac[n-1-1]的逆元 invfac[i-1]=invfac[i]*i 
//单个数的逆元是 inv[i]=fact[i-1]*invfact[i]
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
const ll INF=1e17;
using namespace std;
int n,q;
vector<array<int,2>>e[maxn];
int deep[maxn];
int disroot[maxn],dp[maxn][20];
void dfs(int x,int fa, int cost ){
    disroot[x]=disroot[fa]+cost;
    dp[x][0]=fa;
    deep[x]=deep[fa]+1; 
    for(int j=1;j<=18;j++){
        dp[x][j]=dp[dp[x][j-1]][j-1];
    }
    for(auto u:e[x]){
        if(u[0]==fa) continue;
        dfs(u[0],x,u[1]);
    }
    return ;
}
int query(int l ,int r){
    if(deep[l]<deep[r]) swap(l,r);
    if(l==r ) return l;
    int diff=abs(deep[l]-deep[r]);
    for(int j=18;j>=0;j--){
        if(diff&(1<<j)) {
            l=dp[l][j];
        }
    }
    if(l==r)  return l;
    for(int j=18;j>=0;j--){
        if(dp[l][j]!=dp[r][j] ){
            l=dp[l][j];
            r=dp[r][j];
        }
    }
    return dp[l][0];
}
void slove(){
    for(int i=1;i<=n;i++) e[i].clear();
    cin>>n>>q;
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    dfs(1,0,0);
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<disroot[u]+disroot[v]-2*disroot[query(u,v)]<<"\n";
    }
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